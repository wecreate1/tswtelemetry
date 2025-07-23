#pragma once

#include <string>
#include <Unreal/Core/Containers/EnumAsByte.hpp>
#include "PzbService.hpp"
#include "json.hpp"

struct PzbData {
    float PZB_GetRestrictionMaxSpeed__CurrentRestrictionSpeedMS;
    bool PZB_GetIsLZBActive__bIsLZBActive;
    bool PZB_GetIsReady__bIsReady;
    bool PZB_GetOverspeed__IsOverspeed;
    bool PZB_GetOverspeed__IsForcedBrake;
    bool PZB_GetEmergency__IsEmergency;
    bool PZB_GetActiveState__IsActive;
    RC::Unreal::TEnumAsByte<PZB_Modes::Type> PZB_GetProgramMode__mode;
    RC::Unreal::FPZB_InfluenceProgram PZB_GetDataStruct__Influence;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ONLY_SERIALIZE(PzbData,
        PZB_GetRestrictionMaxSpeed__CurrentRestrictionSpeedMS,
        PZB_GetIsLZBActive__bIsLZBActive,
        PZB_GetIsReady__bIsReady,
        PZB_GetOverspeed__IsOverspeed,
        PZB_GetOverspeed__IsForcedBrake,
        PZB_GetEmergency__IsEmergency,
        PZB_GetActiveState__IsActive,
        PZB_GetProgramMode__mode,
        PZB_GetDataStruct__Influence)


    static void FromService(PzbData& data, RC::Unreal::II_PZB_Service_C* service);

    static PzbData FromService(RC::Unreal::II_PZB_Service_C* service);
};