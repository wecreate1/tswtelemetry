#include "PzbData.hpp"
#include "PzbService.hpp"
#include "TripleBuffer.hpp"
#include "TS2Prototype.hpp"
#include "AcsesAtcService.hpp"
#include "AcsesAtcData.hpp"
#include "Containers/EnumAsByte.hpp"
#include "DynamicOutput/Output.hpp"
#include "DynamicOutput/OutputDevice.hpp"
#include "FWeakObjectPtr.hpp"
#include "HAL/Platform.hpp"
#include <Unreal/UObject.hpp>
#include <Unreal/UObjectMacros.hpp>
#include <Unreal/BPMacros.hpp>
#include <Unreal/UObjectGlobals.hpp>
#include <Unreal/UClass.hpp>
#include <Mod/CppUserModBase.hpp>
#include <Unreal/Hooks.hpp>
#include <Unreal/UFunction.hpp>
#include <filesystem>
#include <fstream>
#include <malloc.h>
#include <atomic>
#include "json.hpp"
#include "libusockets.h"
#include "uwebsockets/Loop.h"
#include "uwebsockets/WebSocketProtocol.h"
#include <optional>
#include <stdexcept>
#include <filesystem>
#include <uwebsockets/App.h>

using namespace RC;
using namespace RC::Unreal;

static TCHAR dllFilePath[1024 + 1] = { 0 };

NLOHMANN_JSON_NAMESPACE_BEGIN
template <typename T>
struct adl_serializer<std::optional<T>> {
    static void to_json(json& j, const std::optional<T>& opt) {
        if (opt == std::nullopt) {
            j = nullptr;
        } else {
            j = *opt; // this will call adl_serializer<T>::to_json which will
                      // find the free function to_json in T's namespace!
        }
    }

    static void from_json(const json& j, std::optional<T>& opt) {
        if (j.is_null()) {
            opt = std::nullopt;
        } else {
            opt = j.template get<T>(); // same as above, but with
                              // adl_serializer<T>::from_json
        }
    }
};
NLOHMANN_JSON_NAMESPACE_END

struct buffer {
    std::optional<AcsesAtcData> DTG_ACSES_ATC;
    std::optional<PzbData> DTG_PZB90;
    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ONLY_SERIALIZE(buffer,
        DTG_ACSES_ATC,
        DTG_PZB90)
};

struct Settings {
    int port = 6865;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE_WITH_DEFAULT(Settings, port);
};

class TelemMod final : public CppUserModBase
{
    TripleBuffer<buffer> buffer = {};
    std::thread ws_thread;
    uWS::App* p_app;
    struct us_timer_t* p_timer;
    Settings config = {};
public:
    TelemMod() : CppUserModBase()
    {
        ModName = STR("TelemMod");
        ModVersion = STR("0.0");
        ModDescription = STR("This mod exposes a Websocket Server");
        ModAuthors = STR("Luex & ClutchFred");

        auto config_path = std::filesystem::path(dllFilePath).parent_path().parent_path() / "config.json";
        if (std::filesystem::exists(config_path)) {
            std::ifstream config_stream(config_path);
            config = nlohmann::json::parse(config_stream);
        }
    }

    ~TelemMod() override
    {
    }
    
    void on_tick(RC::Unreal::UEngine* Context, float DeltaSeconds)
    {
        // Output::send<LogLevel::Normal>(STR("TelemMod: Tick\n"));
        static FWeakObjectPtr cachedPlayerController;
        ATS2PrototypePlayerController* playerController = Cast<ATS2PrototypePlayerController>(cachedPlayerController.Get());
        if (playerController == nullptr)
            cachedPlayerController = playerController = Cast<ATS2PrototypePlayerController>(Unreal::UObjectGlobals::FindFirstOf(STR("TS2PrototypePlayerController")));
        // Output::send<LogLevel::Normal>(std::format(STR("TelemMod: playerController: {}\n"), playerController->GetFullName(nullptr)));
        if (!playerController)
            return;
        ARailVehicle* railVehicle = Cast<ARailVehicle>(playerController->GetDrivableActor());
        // Output::send<LogLevel::Normal>(std::format(STR("TelemMod: railVehicle: {}\n"), railVehicle->GetFullName(nullptr)));
        if (!railVehicle)
            return;
        UObject* service = nullptr;

        struct buffer& out = buffer.write();

        bool found = railVehicle->FindService(FName(STR("DTG_ACSES_ATC")), service);
        // Output::send<LogLevel::Normal>(std::format(STR("TelemMod: service: {}\n"), service->GetFullName(nullptr)));
        (void) found;

        if (service) {
            II_ACSES_ATC_Service_C* acsesAtcService = static_cast<II_ACSES_ATC_Service_C*>(service);

            // Output::send<LogLevel::Normal>(STR("TelemMod: Found Service 1\n"));
            out.DTG_ACSES_ATC = AcsesAtcData::FromService(acsesAtcService);
        } else {
            out.DTG_ACSES_ATC.reset();
        }

        service = nullptr;
        found = railVehicle->FindService(FName(STR("DTG_PZB90")), service);
        // Output::send<LogLevel::Normal>(std::format(STR("TelemMod: service: {}\n"), service->GetFullName(nullptr)));
        (void) found;

        if (service) {
            II_PZB_Service_C* pzbService = static_cast<II_PZB_Service_C*>(service);

            // Output::send<LogLevel::Normal>(STR("TelemMod: Found Service 2\n"));
            out.DTG_PZB90 = PzbData::FromService(pzbService);
        } else {
            out.DTG_PZB90.reset();
        }
        buffer.flip();
        // Output::send<LogLevel::Normal>(STR("TelemMod: Flip\n"));
    }

    void ws_start()
    {
        auto port = config.port;
        auto app = uWS::App()
            .ws<char>("/app", {
                .open = [](auto* ws){
                    ws->subscribe("DTG_ACSES_ATC");
                }
            })
            .listen(port, [port](auto *listenSocket) {
                if (listenSocket) {
                    Output::send<LogLevel::Normal>(STR("TelemMod: Listening on port {}\n"), port);
                } else {
                    Output::send<LogLevel::Warning>(STR("TelemMod: Failed to load certs or to bind to port\n"));
                }
            });

        p_app = &app;
        auto loop = reinterpret_cast<struct us_loop_t*>(uWS::Loop::get());
        p_timer = us_create_timer(loop, 0, sizeof(TelemMod*));
        TelemMod** ext = reinterpret_cast<TelemMod**>(us_timer_ext(p_timer));
        *ext = this;

        us_timer_set(p_timer, [](struct us_timer_t* t) {
            TelemMod* self = *reinterpret_cast<TelemMod**>(us_timer_ext(t));
            auto [flipped, data] = self->buffer.read();
            // Output::send<LogLevel::Normal>(STR("TelemMod: Read"));
            if (flipped) {
                // Outp ut::send<LogLevel::Normal>(STR("TelemMod: Read flipped"));
                self->p_app->publish("DTG_ACSES_ATC", nlohmann::to_string(nlohmann::json(data)), uWS::OpCode::TEXT);
            }
        }, 100, 100);

        app.run();
    }

    void on_program_start() override
    {
        RC::Unreal::Hook::RegisterEngineTickPostCallback(std::bind_front(&TelemMod::on_tick, this));
        ws_thread = std::thread(&TelemMod::ws_start, this);
        Output::send<LogLevel::Normal>(STR("TelemMod: Started\n"));
    }

    void uninstall() {
        p_app->getLoop()->defer([this](){
            p_app->close();
            us_timer_close(p_timer);
            delete this;
        });
    }
};

#define TELEM_MOD_API __declspec(dllexport)

extern "C" {
    TELEM_MOD_API CppUserModBase* start_mod()
    {
        return new TelemMod();
    }

    TELEM_MOD_API void uninstall_mod(CppUserModBase* mod)
    {
        TelemMod* telemMod = dynamic_cast<TelemMod*>(mod);
        if (!telemMod)
            return;
        telemMod->uninstall();
    }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason) {
    case DLL_PROCESS_ATTACH:
        GetModuleFileName(hModule, dllFilePath, (sizeof(dllFilePath)/sizeof(dllFilePath[0]))-1);
        break;
    }
    return TRUE;
}
