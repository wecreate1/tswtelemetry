#include "AcsesAtcData.hpp"

void AcsesAtcData::FromService(AcsesAtcData& data, RC::Unreal::II_ACSES_ATC_Service_C* service)
{
    service->ATC_GetAspectTerritory(data.ATC_GetAspectTerritory__TerritoryID);
    service->ATC_GetIsOverspeed(data.ATC_GetIsOverspeed__bIsOverspeed);
    service->ACSES_GetIsOverspeed(data.ACSES_GetIsOverspeed__bIsOverspeed);
    service->ACSES_ATC_GetAudio(data.ACSES_ATC_GetAudio__bAlarm);
    service->ACSES_ATC_GetMaxPermittedSpeed(data.ACSES_ATC_GetMaxPermittedSpeed__MaxSpeed_ms,
                                            data.ACSES_ATC_GetMaxPermittedSpeed__WarningSpeed_ms,
                                            data.ACSES_ATC_GetMaxPermittedSpeed__bIsActive);
    service->ACSES_GetAudio(data.ACSES_GetAudio__bAlarm);
    service->ACSES_GetStopAspect(data.ACSES_GetStopAspect__bNearStopSignal,
                                    data.ACSES_GetStopAspect__bCanPass);
    service->ACSES_GetPassStop(data.ACSES_GetPassStop__bPassStop);
    service->ATC_GetAudio(data.ATC_GetAudio__bAlarm);
    service->ATC_GetType(data.ATC_GetType__Type);   
    service->ATC_GetAuthorisedSpeed(data.ATC_GetAuthorisedSpeed__Speed_mps);
    service->ATC_GetAspect(data.ATC_GetAspect__CabAspect);
    service->ATC_GetHasValidSignal(data.ATC_GetHasValidSignal__bHasValidSignal);
    service->ACSES_ATC_GetIsZeroVelocity(data.ACSES_ATC_GetIsZeroVelocity__bIsZeroVelocity);
    service->ACSES_ATC_GetIsInSuppresion(data.ACSES_ATC_GetIsInSuppresion__bIsInSuppresion);
    service->ACSES_ATC_GetBrakePipeSuppresion(data.ACSES_ATC_GetBrakePipeSuppresion__bIsValid);
    service->ACSES_ATC_GetDecelerationRateSuppresion(data.ACSES_ATC_GetDecelerationRateSuppresion__bIsValid,
                                                        data.ACSES_ATC_GetDecelerationRateSuppresion__bIsPermanent);
    service->ACSES_ATC_GetIsBraking(data.ACSES_ATC_GetIsBraking__bIsRequired,
                                    data.ACSES_ATC_GetIsBraking__bIsEnforced,
                                    data.ACSES_ATC_GetIsBraking__bIsPermanent);
    service->ACSES_ATC_GetMaxLocoSpeed(data.ACSES_ATC_GetMaxLocoSpeed__Speed_mps);
    service->ACSES_ATC_GetWarningSpeed(data.ACSES_ATC_GetWarningSpeed__Speed_mps);
    service->ACSES_ATC_GetMaxAuthorisedSpeed(data.ACSES_ATC_GetMaxAuthorisedSpeed__Speed_mps,
                                                data.ACSES_ATC_GetMaxAuthorisedSpeed__bIsACSES,
                                                data.ACSES_ATC_GetMaxAuthorisedSpeed__bIsATC);
    service->ACSES_GetTimeToPenalty(data.ACSES_GetTimeToPenalty__Time_seconds);
    service->ACSES_GetAuthorisedSpeed(data.ACSES_GetAuthorisedSpeed__Speed_mps);
    service->ACSES_GetIsInActiveTerritory(data.ACSES_GetIsInActiveTerritory__bActiveTerritory);
    service->ACSES_GetIsActiveSpeedCurve(data.ACSES_GetIsActiveSpeedCurve__bIsActive,
                                            data.ACSES_GetIsActiveSpeedCurve__bIsOverspeed);
    service->ACSES_ATC_GetAcknowledgement(data.ACSES_ATC_GetAcknowledgement__bIsRequired,
                                            data.ACSES_ATC_GetAcknowledgement__bIsAcknowledged);
    service->ACSES_ATC_GetBrakeState(data.ACSES_ATC_GetBrakeState__bIsInSuppresion);
    service->ACSES_GetHasValidTSR_Data(data.ACSES_GetHasValidTSR_Data__bHasData);
    service->ACSES_GetIsActive(data.ACSES_GetIsActive__bIsActive);
    service->ATC_GetIsCabTerritoryCutIn(data.ATC_GetIsCabTerritoryCutIn__bIsCutIn,
                                        data.ATC_GetIsCabTerritoryCutIn__bIsRequired);
    service->ATC_GetIsActive(data.ATC_GetIsActive__bIsActive);
    service->ATC_GetIsCutIn(data.ATC_GetIsCutIn__bIsCutIn);
    service->ACSES_GetIsCutIn(data.ACSES_GetIsCutIn__bIsCutIn);
    service->ACSES_ATC_GetIsEnabled(data.ACSES_ATC_GetIsEnabled__bIsEnabled);
}

AcsesAtcData AcsesAtcData::FromService(RC::Unreal::II_ACSES_ATC_Service_C* service)
{
    AcsesAtcData data;
    FromService(data, service);
    return data;
}