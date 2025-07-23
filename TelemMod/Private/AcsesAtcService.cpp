#include "AcsesAtcService.hpp"
#include <Unreal/UObject.hpp>
#include <Unreal/UObjectMacros.hpp>
#include <Unreal/BPMacros.hpp>
#include <Unreal/UObjectGlobals.hpp>
#include <Unreal/UClass.hpp>
#include <Mod/CppUserModBase.hpp>
#include <Unreal/Hooks.hpp>
#include <Unreal/UFunction.hpp>

using namespace RC;
using namespace RC::Unreal;


void II_ACSES_ATC_Service_C::ATC_GetAspectTerritory(int32& TerritoryID)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ATC_GetAspectTerritory")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(TerritoryID, int32)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ATC_GetIsOverspeed(bool& bIsOverspeed)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ATC_GetIsOverspeed")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsOverspeed, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_GetIsOverspeed(bool& bIsOverspeed)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_GetIsOverspeed")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsOverspeed, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetDisplayMessages(TEnumAsByte<E_ACSES_ATC_DisplayMessages::Type>& Messages)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetDisplayMessages")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(Messages, TEnumAsByte<E_ACSES_ATC_DisplayMessages::Type>)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetDisplayMessage(TEnumAsByte<E_ACSES_ATC_DisplayMessages::Type> Message, bool& bIsSet)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetDisplayMessage")
    UE_COPY_OUT_PROPERTY(Message, TEnumAsByte<E_ACSES_ATC_DisplayMessages::Type>)
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsSet, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetAudio(bool& bAlarm)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetAudio")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bAlarm, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetMaxPermittedSpeed(float& MaxSpeed_ms, float& WarningSpeed_ms, bool& bIsActive)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetMaxPermittedSpeed")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(MaxSpeed_ms, float)
    UE_COPY_OUT_PROPERTY(WarningSpeed_ms, float)
    UE_COPY_OUT_PROPERTY(bIsActive, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_GetAudio(bool& bAlarm)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_GetAudio")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bAlarm, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_GetStopAspect(bool& bNearStopSignal, bool& bCanPass)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_GetStopAspect")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bNearStopSignal, bool)
    UE_COPY_OUT_PROPERTY(bCanPass, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_GetPassStop(bool& bPassStop)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_GetPassStop")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bPassStop, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ATC_GetAudio(bool& bAlarm)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ATC_GetAudio")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bAlarm, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ATC_GetType(TEnumAsByte<E_ATC_Type::Type>& Type)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ATC_GetType")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(Type, TEnumAsByte<E_ATC_Type::Type>)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ATC_GetAuthorisedSpeed(float& Speed_mps)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ATC_GetAuthorisedSpeed")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(Speed_mps, float)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ATC_GetAspect(uint8& CabAspect)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ATC_GetAspect")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(CabAspect, uint8)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ATC_GetHasValidSignal(bool& bHasValidSignal)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ATC_GetHasValidSignal")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bHasValidSignal, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetIsZeroVelocity(bool& bIsZeroVelocity)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetIsZeroVelocity")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsZeroVelocity, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetIsInSuppresion(bool& bIsInSuppresion)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetIsInSuppresion")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsInSuppresion, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetBrakePipeSuppresion(bool& bIsValid)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetBrakePipeSuppresion")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsValid, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetDecelerationRateSuppresion(bool& bIsValid, bool& bIsPermanent)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetDecelerationRateSuppresion")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsValid, bool)
    UE_COPY_OUT_PROPERTY(bIsPermanent, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetIsBraking(bool& bIsRequired, bool& bIsEnforced, bool& bIsPermanent)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetIsBraking")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsRequired, bool)
    UE_COPY_OUT_PROPERTY(bIsEnforced, bool)
    UE_COPY_OUT_PROPERTY(bIsPermanent, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetMaxLocoSpeed(float& Speed_mps)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetMaxLocoSpeed")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(Speed_mps, float)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetWarningSpeed(float& Speed_mps)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetWarningSpeed")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(Speed_mps, float)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetMaxAuthorisedSpeed(float& Speed_mps, bool& bIsACSES, bool& bIsATC)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetMaxAuthorisedSpeed")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(Speed_mps, float)
    UE_COPY_OUT_PROPERTY(bIsACSES, bool)
    UE_COPY_OUT_PROPERTY(bIsATC, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_GetTimeToPenalty(float& Time_seconds)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_GetTimeToPenalty")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(Time_seconds, float)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_GetAuthorisedSpeed(float& Speed_mps)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_GetAuthorisedSpeed")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(Speed_mps, float)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_GetIsInActiveTerritory(bool& bActiveTerritory)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_GetIsInActiveTerritory")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bActiveTerritory, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_GetIsActiveSpeedCurve(bool& bIsActive, bool& bIsOverspeed)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_GetIsActiveSpeedCurve")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsActive, bool)
    UE_COPY_OUT_PROPERTY(bIsOverspeed, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetAcknowledgement(bool& bIsRequired, bool& bIsAcknowledged)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetAcknowledgement")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsRequired, bool)
    UE_COPY_OUT_PROPERTY(bIsAcknowledged, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetBrakeState(bool& bIsInSuppresion)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetBrakeState")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsInSuppresion, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_GetHasValidTSR_Data(bool& bHasData)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_GetHasValidTSR_Data")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bHasData, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_GetIsActive(bool& bIsActive)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_GetIsActive")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsActive, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ATC_GetIsCabTerritoryCutIn(bool& bIsCutIn, bool& bIsRequired)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ATC_GetIsCabTerritoryCutIn")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsCutIn, bool)
    UE_COPY_OUT_PROPERTY(bIsRequired, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ATC_SetIsCabTerritoryCutIn(bool bIsCutIn, bool& bHandled)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ATC_SetIsCabTerritoryCutIn")
    UE_COPY_PROPERTY(bIsCutIn, bool)
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bHandled, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ATC_GetIsActive(bool& bIsActive)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ATC_GetIsActive")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsActive, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ATC_GetIsCutIn(bool& bIsCutIn)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ATC_GetIsCutIn")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsCutIn, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ATC_SetIsCutIn(bool bIsCutIn, bool& bHandled)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ATC_SetIsCutIn")
    UE_COPY_PROPERTY(bIsCutIn, bool)
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bHandled, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_GetIsCutIn(bool& bIsCutIn)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_GetIsCutIn")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsCutIn, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_SetIsCutIn(bool bIsCutIn, bool& bHandled)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_SetIsCutIn")
    UE_COPY_PROPERTY(bIsCutIn, bool)
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bHandled, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_PassStop(bool bIsPressed, bool& bHandled)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_PassStop")
    UE_COPY_PROPERTY(bIsPressed, bool)
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bHandled, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_GetIsEnabled(bool& bIsEnabled)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_GetIsEnabled")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsEnabled, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_SetBrakeState(bool bIsInSuppression, bool& bHandled)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_SetBrakeState")
    UE_COPY_PROPERTY(bIsInSuppression, bool)
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bHandled, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_SetThrottleState(bool bIsInIdle, bool& bHandled)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_SetThrottleState")
    UE_COPY_PROPERTY(bIsInIdle, bool)
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bHandled, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_SetReverserState(EDirectionOfTravel Direction, bool bIsReverserEngaged, int32 CabFlags, bool& bHandled)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_SetReverserState")
    UE_COPY_PROPERTY(Direction, EDirectionOfTravel)
    UE_COPY_PROPERTY(bIsReverserEngaged, bool)
    UE_COPY_PROPERTY(CabFlags, int32)
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bHandled, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_SetIsEnabled(bool bIsEnabled, bool& bHandled)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_SetIsEnabled")
    UE_COPY_PROPERTY(bIsEnabled, bool)
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bHandled, bool)
    UE_END_VOID_FUNCTION()
}

void II_ACSES_ATC_Service_C::ACSES_ATC_Acknowledge(bool bIsPressed, bool& bHandled)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("ACSES_ATC_Acknowledge")
    UE_COPY_PROPERTY(bIsPressed, bool)
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bHandled, bool)
    UE_END_VOID_FUNCTION()
}

// void II_ACSES_ATC_Service_C::ACSES_ATC_UnregisterClient(TScriptInterface<class II_ACSES_ATC_Client_C> Client, bool& bUnregistered);
// void II_ACSES_ATC_Service_C::ACSES_ATC_RegisterClient(TScriptInterface<class II_ACSES_ATC_Client_C> Client, bool& bRegistered);
