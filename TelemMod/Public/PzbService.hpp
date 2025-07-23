#pragma once

#include "TS2Prototype.hpp"
#include "json.hpp"
#include <Unreal/Core/Containers/EnumAsByte.hpp>

namespace PZB_Modes {
    enum Type {
        NewEnumerator0 = 0,
        NewEnumerator1 = 1,
        NewEnumerator2 = 2,
        NewEnumerator3 = 3,
        PZB_MAX = 4,
    };
}

namespace PZB2_EmergencyState {
    enum Type {
        NewEnumerator0 = 0,
        NewEnumerator1 = 1,
        NewEnumerator2 = 2,
        NewEnumerator4 = 3,
        PZB2_MAX = 4,
    };
}

NLOHMANN_JSON_NAMESPACE_BEGIN
template <>
struct adl_serializer<RC::Unreal::TEnumAsByte<PZB_Modes::Type>> {
    static void to_json(json& j, const RC::Unreal::TEnumAsByte<PZB_Modes::Type>& opt) {
        j = opt.GetIntValue();
    }
};

template <>
struct adl_serializer<RC::Unreal::TEnumAsByte<PZB2_EmergencyState::Type>> {
    static void to_json(json& j, const RC::Unreal::TEnumAsByte<PZB2_EmergencyState::Type>& opt) {
        j = opt.GetIntValue();
    }
};
NLOHMANN_JSON_NAMESPACE_END

namespace RC::Unreal {

    struct FPZB_InfluenceProgram {
        bool InfluenceRange;
        bool _1000Hz_Active;
        bool _500Hz_Active;
        bool _2000Hz_Active;
        bool _1000Hz_ReleaseRange;
        bool isAcknowledged;
        bool isRestricted;
        bool isExtended;
        bool isOverrideValid;
        bool isReverse;
        bool isStartup;
        bool isOverspeed;
        bool isEmergency;
        int32 _1000Hz_Time;
        int32 _500Hz_Distance;
        int32 SpeedLimit;
        TEnumAsByte<PZB2_EmergencyState::Type> EmergencyType;

        NLOHMANN_DEFINE_TYPE_INTRUSIVE_ONLY_SERIALIZE(::RC::Unreal::FPZB_InfluenceProgram,
            InfluenceRange,
            _1000Hz_Active,
            _500Hz_Active,
            _2000Hz_Active,
            _1000Hz_ReleaseRange,
            isAcknowledged,
            isRestricted,
            isExtended,
            isOverrideValid,
            isReverse,
            isStartup,
            isOverspeed,
            isEmergency,
            _1000Hz_Time,
            _500Hz_Distance,
            SpeedLimit,
            EmergencyType)
    };

    class II_PZB_Service_C : public UObject
    {
    public:
        void PZB_GetRestrictionMaxSpeed(float& CurrentRestrictionSpeedMS);
        void PZB_GetIsLZBActive(bool& bIsLZBActive);
        void PZB_GetIsReady(bool& bIsReady);
        void PZB_GetOverspeed(bool& IsOverspeed, bool& IsForcedBrake);
        void PZB_GetEmergency(bool& IsEmergency);
        void PZB_GetActiveState(bool& IsActive);
        void PZB_SetActiveState(bool IsActive);
        void PZB_SetPowerState(bool IsPowered);
        void PZB_SetDirection(EDirectionOfTravel Direction, bool Engaged);
        void PZB_Override(bool IsPressed);
        void PZB_Release(bool IsPressed);
        void PZB_Acknowledge(bool IsPressed);
        // bool PZB_UnregisterClient(TScriptInterface<class II_PZB_Client_C> Client);
        // bool PZB_RegisterClient(TScriptInterface<class II_PZB_Client_C> Client);
        void PZB_GetProgramMode(TEnumAsByte<PZB_Modes::Type>& mode);
        void PZB_GetDataStruct(FPZB_InfluenceProgram& Influence);
    };
}