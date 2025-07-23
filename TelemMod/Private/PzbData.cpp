#include "PzbData.hpp"
#include <Mod/CppUserModBase.hpp>


void PzbData::FromService(PzbData& data, RC::Unreal::II_PZB_Service_C* service)
{
    service->PZB_GetRestrictionMaxSpeed(data.PZB_GetRestrictionMaxSpeed__CurrentRestrictionSpeedMS);
    service->PZB_GetIsLZBActive(data.PZB_GetIsLZBActive__bIsLZBActive);
    service->PZB_GetIsReady(data.PZB_GetIsReady__bIsReady);
    service->PZB_GetOverspeed(data.PZB_GetOverspeed__IsOverspeed, data.PZB_GetOverspeed__IsForcedBrake);
    service->PZB_GetEmergency(data.PZB_GetEmergency__IsEmergency);
    service->PZB_GetActiveState(data.PZB_GetActiveState__IsActive);
    service->PZB_GetProgramMode(data.PZB_GetProgramMode__mode);
    service->PZB_GetDataStruct(data.PZB_GetDataStruct__Influence);
}

PzbData PzbData::FromService(RC::Unreal::II_PZB_Service_C* service)
{
    PzbData data;
    FromService(data, service);
    return data;
}
