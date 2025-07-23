#pragma once

#include <string>
#include <Unreal/Core/Containers/EnumAsByte.hpp>
#include "AcsesAtcService.hpp"
#include "json.hpp"

struct AcsesAtcData {
    int32_t ATC_GetAspectTerritory__TerritoryID;
    bool ATC_GetIsOverspeed__bIsOverspeed;
    bool ACSES_GetIsOverspeed__bIsOverspeed;  // This

    // Not sure what this is yet
    // TEnumAsByte<E_ACSES_ATC_DisplayMessages::Type> ACSES_ATC_GetDisplayMessages__Messages;

    bool ACSES_ATC_GetAudio__bAlarm;
    float ACSES_ATC_GetMaxPermittedSpeed__MaxSpeed_ms;
    float ACSES_ATC_GetMaxPermittedSpeed__WarningSpeed_ms;
    bool ACSES_ATC_GetMaxPermittedSpeed__bIsActive;
    bool ACSES_GetAudio__bAlarm;
    bool ACSES_GetStopAspect__bNearStopSignal; // This
    bool ACSES_GetStopAspect__bCanPass;
    bool ACSES_GetPassStop__bPassStop;
    bool ATC_GetAudio__bAlarm;
    RC::Unreal::TEnumAsByte<E_ATC_Type::Type> ATC_GetType__Type;
    float ATC_GetAuthorisedSpeed__Speed_mps;  // This
    uint8_t ATC_GetAspect__CabAspect;
    bool ATC_GetHasValidSignal__bHasValidSignal;
    bool ACSES_ATC_GetIsZeroVelocity__bIsZeroVelocity;
    bool ACSES_ATC_GetIsInSuppresion__bIsInSuppresion;
    bool ACSES_ATC_GetBrakePipeSuppresion__bIsValid;
    bool ACSES_ATC_GetDecelerationRateSuppresion__bIsValid;
    bool ACSES_ATC_GetDecelerationRateSuppresion__bIsPermanent;
    bool ACSES_ATC_GetIsBraking__bIsRequired;
    bool ACSES_ATC_GetIsBraking__bIsEnforced;
    bool ACSES_ATC_GetIsBraking__bIsPermanent;
    float ACSES_ATC_GetMaxLocoSpeed__Speed_mps;
    float ACSES_ATC_GetWarningSpeed__Speed_mps;
    float ACSES_ATC_GetMaxAuthorisedSpeed__Speed_mps;
    bool ACSES_ATC_GetMaxAuthorisedSpeed__bIsACSES;
    bool ACSES_ATC_GetMaxAuthorisedSpeed__bIsATC;
    float ACSES_GetTimeToPenalty__Time_seconds;
    float ACSES_GetAuthorisedSpeed__Speed_mps;  // This
    bool ACSES_GetIsInActiveTerritory__bActiveTerritory;
    bool ACSES_GetIsActiveSpeedCurve__bIsActive;
    bool ACSES_GetIsActiveSpeedCurve__bIsOverspeed;
    bool ACSES_ATC_GetAcknowledgement__bIsRequired;
    bool ACSES_ATC_GetAcknowledgement__bIsAcknowledged;
    bool ACSES_ATC_GetBrakeState__bIsInSuppresion;
    bool ACSES_GetHasValidTSR_Data__bHasData;
    bool ACSES_GetIsActive__bIsActive; // This
    bool ATC_GetIsCabTerritoryCutIn__bIsCutIn;
    bool ATC_GetIsCabTerritoryCutIn__bIsRequired;
    bool ATC_GetIsActive__bIsActive;  // This
    bool ATC_GetIsCutIn__bIsCutIn;
    bool ACSES_GetIsCutIn__bIsCutIn;
    bool ACSES_ATC_GetIsEnabled__bIsEnabled;

    NLOHMANN_DEFINE_TYPE_INTRUSIVE_ONLY_SERIALIZE(AcsesAtcData,
        ATC_GetAspectTerritory__TerritoryID,
        ATC_GetIsOverspeed__bIsOverspeed,
        ACSES_GetIsOverspeed__bIsOverspeed,
        ACSES_ATC_GetAudio__bAlarm,
        ACSES_ATC_GetMaxPermittedSpeed__MaxSpeed_ms,
        ACSES_ATC_GetMaxPermittedSpeed__WarningSpeed_ms,
        ACSES_ATC_GetMaxPermittedSpeed__bIsActive,
        ACSES_GetAudio__bAlarm,
        ACSES_GetStopAspect__bNearStopSignal,
        ACSES_GetStopAspect__bCanPass,
        ACSES_GetPassStop__bPassStop,
        ATC_GetAudio__bAlarm,
        ATC_GetType__Type,
        ATC_GetAuthorisedSpeed__Speed_mps,
        ATC_GetAspect__CabAspect,
        ATC_GetHasValidSignal__bHasValidSignal,
        ACSES_ATC_GetIsZeroVelocity__bIsZeroVelocity,
        ACSES_ATC_GetIsInSuppresion__bIsInSuppresion,
        ACSES_ATC_GetBrakePipeSuppresion__bIsValid,
        ACSES_ATC_GetDecelerationRateSuppresion__bIsValid,
        ACSES_ATC_GetDecelerationRateSuppresion__bIsPermanent,
        ACSES_ATC_GetIsBraking__bIsRequired,
        ACSES_ATC_GetIsBraking__bIsEnforced,
        ACSES_ATC_GetIsBraking__bIsPermanent,
        ACSES_ATC_GetMaxLocoSpeed__Speed_mps,
        ACSES_ATC_GetWarningSpeed__Speed_mps,
        ACSES_ATC_GetMaxAuthorisedSpeed__Speed_mps,
        ACSES_ATC_GetMaxAuthorisedSpeed__bIsACSES,
        ACSES_ATC_GetMaxAuthorisedSpeed__bIsATC,
        ACSES_GetTimeToPenalty__Time_seconds,
        ACSES_GetAuthorisedSpeed__Speed_mps,
        ACSES_GetIsInActiveTerritory__bActiveTerritory,
        ACSES_GetIsActiveSpeedCurve__bIsActive,
        ACSES_GetIsActiveSpeedCurve__bIsOverspeed,
        ACSES_ATC_GetAcknowledgement__bIsRequired,
        ACSES_ATC_GetAcknowledgement__bIsAcknowledged,
        ACSES_ATC_GetBrakeState__bIsInSuppresion,
        ACSES_GetHasValidTSR_Data__bHasData,
        ACSES_GetIsActive__bIsActive,
        ATC_GetIsCabTerritoryCutIn__bIsCutIn,
        ATC_GetIsCabTerritoryCutIn__bIsRequired,
        ATC_GetIsActive__bIsActive,
        ATC_GetIsCutIn__bIsCutIn,
        ACSES_GetIsCutIn__bIsCutIn,
        ACSES_ATC_GetIsEnabled__bIsEnabled)


    static void FromService(AcsesAtcData& data, RC::Unreal::II_ACSES_ATC_Service_C* service);

    static AcsesAtcData FromService(RC::Unreal::II_ACSES_ATC_Service_C* service);
};
