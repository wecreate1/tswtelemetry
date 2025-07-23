#pragma once

#include "TS2Prototype.hpp"
#include "json.hpp"
#include <Unreal/Core/Containers/EnumAsByte.hpp>

namespace E_ACSES_ATC_DisplayMessages {
    enum Type {
        NewEnumerator0 = 0, // ACSES Overspeed Penalty
        NewEnumerator1 = 1, // ATC Overspeed Penalty
        E_ACSES_ATC_MAX = 2,
    };
}

namespace E_ATC_Type {
    enum Type {
        NewEnumerator1 = 0, // PRR (4 Code)
        NewEnumerator3 = 1, // PRR (8 Code)
        NewEnumerator2 = 2, // LIRR (6 Code)
        E_ATC_MAX = 3,
    };
}

namespace E_ATC_ACSES_CabAspect {
    enum Type {
        NewEnumerator9 = 0, // Clear (150Mph)
        NewEnumerator8 = 1, // Clear (125Mph)
        NewEnumerator0 = 2, // Clear (100Mph)
        NewEnumerator1 = 3, // Cab Speed (80Mph)
        NewEnumerator2 = 4, // Cab Speed (60Mph)
        NewEnumerator10 = 5, // Approach Limited (45Mph)
        NewEnumerator4 = 6, // Approach Medium (45Mph)
        NewEnumerator5 = 7, // Approach (30Mph)
        NewEnumerator6 = 8, // Restricting (20Mph)
        E_ATC_ACSES_MAX = 9
    };
}

NLOHMANN_JSON_NAMESPACE_BEGIN
template <>
struct adl_serializer<RC::Unreal::TEnumAsByte<E_ATC_Type::Type>> {
    static void to_json(json& j, const RC::Unreal::TEnumAsByte<E_ATC_Type::Type>& opt) {
        j = opt.GetIntValue();
    }
};
NLOHMANN_JSON_NAMESPACE_END

namespace RC::Unreal {

    class II_ACSES_ATC_Service_C : public UObject
    {
    public:
        void ATC_GetAspectTerritory(int32& TerritoryID);

        void ATC_GetIsOverspeed(bool& bIsOverspeed);

        void ACSES_GetIsOverspeed(bool& bIsOverspeed);

        void ACSES_ATC_GetDisplayMessages(TEnumAsByte<E_ACSES_ATC_DisplayMessages::Type>& Messages);

        void ACSES_ATC_GetDisplayMessage(TEnumAsByte<E_ACSES_ATC_DisplayMessages::Type> Message, bool& bIsSet);

        void ACSES_ATC_GetAudio(bool& bAlarm);

        void ACSES_ATC_GetMaxPermittedSpeed(float& MaxSpeed_ms, float& WarningSpeed_ms, bool& bIsActive);

        void ACSES_GetAudio(bool& bAlarm);

        void ACSES_GetStopAspect(bool& bNearStopSignal, bool& bCanPass);

        void ACSES_GetPassStop(bool& bPassStop);

        void ATC_GetAudio(bool& bAlarm);

        void ATC_GetType(TEnumAsByte<E_ATC_Type::Type>& Type);

        void ATC_GetAuthorisedSpeed(float& Speed_mps);

        void ATC_GetAspect(uint8& CabAspect);

        void ATC_GetHasValidSignal(bool& bHasValidSignal);

        void ACSES_ATC_GetIsZeroVelocity(bool& bIsZeroVelocity);

        void ACSES_ATC_GetIsInSuppresion(bool& bIsInSuppresion);

        void ACSES_ATC_GetBrakePipeSuppresion(bool& bIsValid);

        void ACSES_ATC_GetDecelerationRateSuppresion(bool& bIsValid, bool& bIsPermanent);

        void ACSES_ATC_GetIsBraking(bool& bIsRequired, bool& bIsEnforced, bool& bIsPermanent);

        void ACSES_ATC_GetMaxLocoSpeed(float& Speed_mps);

        void ACSES_ATC_GetWarningSpeed(float& Speed_mps);

        void ACSES_ATC_GetMaxAuthorisedSpeed(float& Speed_mps, bool& bIsACSES, bool& bIsATC);

        void ACSES_GetTimeToPenalty(float& Time_seconds);

        void ACSES_GetAuthorisedSpeed(float& Speed_mps);

        void ACSES_GetIsInActiveTerritory(bool& bActiveTerritory);

        void ACSES_GetIsActiveSpeedCurve(bool& bIsActive, bool& bIsOverspeed);

        void ACSES_ATC_GetAcknowledgement(bool& bIsRequired, bool& bIsAcknowledged);

        void ACSES_ATC_GetBrakeState(bool& bIsInSuppresion);

        void ACSES_GetHasValidTSR_Data(bool& bHasData);

        void ACSES_GetIsActive(bool& bIsActive);

        void ATC_GetIsCabTerritoryCutIn(bool& bIsCutIn, bool& bIsRequired);

        void ATC_SetIsCabTerritoryCutIn(bool bIsCutIn, bool& bHandled);

        void ATC_GetIsActive(bool& bIsActive);

        void ATC_GetIsCutIn(bool& bIsCutIn);

        void ATC_SetIsCutIn(bool bIsCutIn, bool& bHandled);

        void ACSES_GetIsCutIn(bool& bIsCutIn);

        void ACSES_SetIsCutIn(bool bIsCutIn, bool& bHandled);

        void ACSES_PassStop(bool bIsPressed, bool& bHandled);

        void ACSES_ATC_GetIsEnabled(bool& bIsEnabled);

        void ACSES_ATC_SetBrakeState(bool bIsInSuppression, bool& bHandled);

        void ACSES_ATC_SetThrottleState(bool bIsInIdle, bool& bHandled);

        void ACSES_ATC_SetReverserState(EDirectionOfTravel Direction, bool bIsReverserEngaged, int32 CabFlags, bool& bHandled);

        void ACSES_ATC_SetIsEnabled(bool bIsEnabled, bool& bHandled);

        void ACSES_ATC_Acknowledge(bool bIsPressed, bool& bHandled);

        // void ACSES_ATC_UnregisterClient(TScriptInterface<class II_ACSES_ATC_Client_C> Client, bool& bUnregistered);
        // void ACSES_ATC_RegisterClient(TScriptInterface<class II_ACSES_ATC_Client_C> Client, bool& bRegistered);
    };
}