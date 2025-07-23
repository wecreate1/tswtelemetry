#include "TS2Prototype.hpp"
#include <Unreal/UObjectGlobals.hpp>
#include <Unreal/UObject.hpp>
#include <Unreal/UClass.hpp>

using namespace RC;
using namespace RC::Unreal;

IMPLEMENT_EXTERNAL_OBJECT_CLASS(ATS2PrototypePlayerController)

class AActor* ATS2PrototypePlayerController::GetDrivableActor()
{
    UE_BEGIN_SCRIPT_FUNCTION_BODY("/Script/TS2Prototype.TS2PrototypePlayerController:GetDrivableActor")
    UE_CALL_FUNCTION()
    UE_RETURN_PROPERTY(AActor*)
}

IMPLEMENT_EXTERNAL_OBJECT_CLASS(ARailVehicle)

bool ARailVehicle::FindService(FName Name, UObject*& Service)
{
    UE_BEGIN_VIRTUAL_FUNCTION_BODY("FindService")
    UE_COPY_PROPERTY(Name, FName)
    UE_CALL_FUNCTION()
    UE_COPY_OUT_PROPERTY(Service, UObject*)
    UE_RETURN_PROPERTY(bool)
}