#pragma once

#include <Unreal/BPMacros.hpp>

#define UE_BEGIN_VIRTUAL_FUNCTION_BODY(FunctionPath) \
auto Function = GetFunctionByNameInChain(STR(FunctionPath)); \
UE_BEGIN_FUNCTION_BODY_INTERNAL(FunctionPath)

#define UE_COPY_OUT_PROPERTY_INTERNAL(PropertyName) \
auto Out##PropertyName##Property = Function->FindProperty(FName(STR(#PropertyName))); \
if (!Out##PropertyName##Property) { throw std::runtime_error{"Out property not found: '"#PropertyName"'"}; } \

#define UE_COPY_OUT_STRUCT_PROPERTY_BEGIN(PropertyName) \
UE_COPY_OUT_PROPERTY_INTERNAL(PropertyName) \
auto Out##PropertyName##Struct = static_cast<FStructProperty*>(Out##PropertyName##Property)->GetStruct();

#define UE_COPY_OUT_STRUCT_INNER_PROPERTY(StructName, PropertyName, TypeName, CXXValue) \
FProperty* Out##StructName##PropertyName##Property = nullptr; \
for (FProperty* prop : Out##StructName##Struct->ForEachProperty()) { \
    if (prop->GetName().starts_with(STR(#PropertyName))) { \
        Out##StructName##PropertyName##Property = prop; \
        break; \
    } \
} \
CXXValue = *std::bit_cast<TypeName*>(&ParamData[Out##StructName##Property->GetOffset_Internal() + Out##StructName##PropertyName##Property->GetOffset_Internal()]);