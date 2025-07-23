#include "PzbService.hpp"
#include "FProperty.hpp"
#include "MyBPMacros.hpp"
#include <Unreal/UObject.hpp>
#include <Unreal/UObjectMacros.hpp>
#include <Unreal/BPMacros.hpp>
#include <Unreal/UObjectGlobals.hpp>
#include <Unreal/UClass.hpp>
#include <Mod/CppUserModBase.hpp>
#include <Unreal/Hooks.hpp>
#include <Unreal/UFunction.hpp>
#include <Unreal/UScriptStruct.hpp>

using namespace RC;
using namespace RC::Unreal;

void II_PZB_Service_C::PZB_GetRestrictionMaxSpeed(float& CurrentRestrictionSpeedMS)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_GetRestrictionMaxSpeed")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(CurrentRestrictionSpeedMS, float)
    UE_END_VOID_FUNCTION()
}

void II_PZB_Service_C::PZB_GetIsLZBActive(bool& bIsLZBActive)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_GetIsLZBActive")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsLZBActive, bool)
    UE_END_VOID_FUNCTION()
}

void II_PZB_Service_C::PZB_GetIsReady(bool& bIsReady)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_GetIsReady")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(bIsReady, bool)
    UE_END_VOID_FUNCTION()
}

void II_PZB_Service_C::PZB_GetOverspeed(bool& IsOverspeed, bool& IsForcedBrake)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_GetOverspeed")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(IsOverspeed, bool)
    UE_COPY_OUT_PROPERTY(IsForcedBrake, bool)
    UE_END_VOID_FUNCTION()
}

void II_PZB_Service_C::PZB_GetEmergency(bool& IsEmergency)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_GetEmergency")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(IsEmergency, bool)
    UE_END_VOID_FUNCTION()
}

void II_PZB_Service_C::PZB_GetActiveState(bool& IsActive)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_GetActiveState")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(IsActive, bool)
    UE_END_VOID_FUNCTION()
}

void II_PZB_Service_C::PZB_SetActiveState(bool IsActive)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_SetActiveState")
    UE_COPY_PROPERTY(IsActive, bool)
    UE_CALL_FUNCTION()
    UE_END_VOID_FUNCTION()
}

void II_PZB_Service_C::PZB_SetPowerState(bool IsPowered)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_SetPowerState")
    UE_COPY_PROPERTY(IsPowered, bool)
    UE_CALL_FUNCTION()
    UE_END_VOID_FUNCTION()
}

void II_PZB_Service_C::PZB_SetDirection(EDirectionOfTravel Direction, bool Engaged)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_SetDirection")
    UE_COPY_PROPERTY(Direction, EDirectionOfTravel)
    UE_COPY_PROPERTY(Engaged, bool)
    UE_CALL_FUNCTION()
    UE_END_VOID_FUNCTION()
}

void II_PZB_Service_C::PZB_Override(bool IsPressed)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_Override")
    UE_COPY_PROPERTY(IsPressed, bool)
    UE_CALL_FUNCTION()
    UE_END_VOID_FUNCTION()
}

void II_PZB_Service_C::PZB_Release(bool IsPressed)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_Release")
    UE_COPY_PROPERTY(IsPressed, bool)
    UE_CALL_FUNCTION()
    UE_END_VOID_FUNCTION()
}

void II_PZB_Service_C::PZB_Acknowledge(bool IsPressed)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_Acknowledge")
    UE_COPY_PROPERTY(IsPressed, bool)
    UE_CALL_FUNCTION()
    UE_END_VOID_FUNCTION()
}

void II_PZB_Service_C::PZB_GetProgramMode(TEnumAsByte<PZB_Modes::Type>& mode)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_GetProgramMode")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(mode, TEnumAsByte<PZB_Modes::Type>)
    UE_END_VOID_FUNCTION()
}

void II_PZB_Service_C::PZB_GetDataStruct(FPZB_InfluenceProgram& Influence)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("PZB_GetDataStruct")
    UE_CALL_FUNCTION()
    UE_COPY_OUT_STRUCT_PROPERTY_BEGIN(Influence)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, InfluenceRange, bool, Influence.InfluenceRange)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, 1000Hz_Active, bool, Influence._1000Hz_Active)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, 500Hz_Active, bool, Influence._500Hz_Active)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, 2000Hz_Active, bool, Influence._2000Hz_Active)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, 1000Hz_ReleaseRange, bool, Influence._1000Hz_ReleaseRange)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, isAcknowledged, bool, Influence.isAcknowledged)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, isRestricted, bool, Influence.isRestricted)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, isExtended, bool, Influence.isExtended)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, isOverrideValid, bool, Influence.isOverrideValid)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, isReverse, bool, Influence.isReverse)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, isStartup, bool, Influence.isStartup)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, isOverspeed, bool, Influence.isOverspeed)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, isEmergency, bool, Influence.isEmergency)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, 1000Hz_Time, int32, Influence._1000Hz_Time)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, 500Hz_Distance, int32, Influence._500Hz_Distance)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, SpeedLimit, int32, Influence.SpeedLimit)
    UE_COPY_OUT_STRUCT_INNER_PROPERTY(Influence, EmergencyType, TEnumAsByte<PZB2_EmergencyState::Type>, Influence.EmergencyType)
    UE_END_VOID_FUNCTION()
}


// bool PZB_UnregisterClient(TScriptInterface<class II_PZB_Client_C> Client);
// bool PZB_RegisterClient(TScriptInterface<class II_PZB_Client_C> Client);