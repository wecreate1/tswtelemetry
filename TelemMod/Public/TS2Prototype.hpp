#pragma once

#include <Unreal/UObject.hpp>
#include <Unreal/AActor.hpp>
#include "MyBPMacros.hpp"

namespace RC::Unreal
{
    class ATS2PrototypePlayerController : public UObject
    {
    DECLARE_EXTERNAL_OBJECT_CLASS(ATS2PrototypePlayerController, TS2Prototype)
    public:
        AActor* GetDrivableActor();
    };

    class ARailVehicle : public UObject
    {
    DECLARE_EXTERNAL_OBJECT_CLASS(ARailVehicle, TS2Prototype)
    public:
        bool FindService(FName Name, UObject*& Service);
    };

    // TS2Prototype_enums.hpp
    enum class EDirectionOfTravel {
        Forwards = 0,
        Backwards = 1,
        EDirectionOfTravel_MAX = 2,
    };
}