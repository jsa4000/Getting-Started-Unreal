//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a RdGen v1.07.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------
#ifndef UNREALLOGEVENT_GENERATED_H
#define UNREALLOGEVENT_GENERATED_H


#include "protocol/Protocol.h"
#include "types/DateTime.h"
#include "impl/RdSignal.h"
#include "impl/RdProperty.h"
#include "impl/RdList.h"
#include "impl/RdSet.h"
#include "impl/RdMap.h"
#include "base/ISerializersOwner.h"
#include "base/IUnknownInstance.h"
#include "serialization/ISerializable.h"
#include "serialization/Polymorphic.h"
#include "serialization/NullableSerializer.h"
#include "serialization/ArraySerializer.h"
#include "serialization/InternedSerializer.h"
#include "serialization/SerializationCtx.h"
#include "serialization/Serializers.h"
#include "ext/RdExtBase.h"
#include "task/RdCall.h"
#include "task/RdEndpoint.h"
#include "task/RdSymmetricCall.h"
#include "std/to_string.h"
#include "std/hash.h"
#include "std/allocator.h"
#include "util/enum.h"
#include "util/gen_util.h"

#include <cstring>
#include <cstdint>
#include <vector>
#include <ctime>

#include "thirdparty.hpp"
#include "instantiations_UE4Library.h"

#include "UE4Library/LogMessageInfo.Generated.h"
#include "Runtime/Core/Public/Containers/UnrealString.h"
#include "UE4Library/StringRange.Generated.h"

#include "UE4TypesMarshallers.h"
#include "Runtime/Core/Public/Containers/Array.h"
#include "Runtime/Core/Public/Containers/ContainerAllocationPolicies.h"


#ifdef _MSC_VER
#pragma warning( push )
#pragma warning( disable:4250 )
#pragma warning( disable:4307 )
#pragma warning( disable:4267 )
#pragma warning( disable:4244 )
#pragma warning( disable:4100 )
#endif

/// <summary>
/// <p>Generated from: UE4Library.kt:120</p>
/// </summary>
namespace JetBrains {
namespace EditorPlugin {

// data
class RIDERLINK_API UnrealLogEvent : public rd::IPolymorphicSerializable {

private:
    // custom serializers

public:
    // constants

protected:
    // fields
    rd::Wrapper<LogMessageInfo> info_;
    FString text_;
    TArray<rd::Wrapper<StringRange>> bpPathRanges_;
    TArray<rd::Wrapper<StringRange>> methodRanges_;
    

private:
    // initializer
    void initialize();

public:
    // primary ctor
    UnrealLogEvent(rd::Wrapper<LogMessageInfo> info_, FString text_, TArray<rd::Wrapper<StringRange>> bpPathRanges_, TArray<rd::Wrapper<StringRange>> methodRanges_);
    
    // deconstruct trait
    #ifdef __cpp_structured_bindings
    template <size_t I>
    decltype(auto) get() const
    {
        if constexpr (I < 0 || I >= 4) static_assert (I < 0 || I >= 4, "I < 0 || I >= 4");
        else if constexpr (I==0)  return static_cast<const LogMessageInfo&>(get_info());
        else if constexpr (I==1)  return static_cast<const FString&>(get_text());
        else if constexpr (I==2)  return static_cast<const TArray<rd::Wrapper<StringRange>>&>(get_bpPathRanges());
        else if constexpr (I==3)  return static_cast<const TArray<rd::Wrapper<StringRange>>&>(get_methodRanges());
    }
    #endif
    
    // default ctors and dtors
    
    UnrealLogEvent() = delete;
    
    UnrealLogEvent(UnrealLogEvent const &) = default;
    
    UnrealLogEvent& operator=(UnrealLogEvent const &) = default;
    
    UnrealLogEvent(UnrealLogEvent &&) = default;
    
    UnrealLogEvent& operator=(UnrealLogEvent &&) = default;
    
    virtual ~UnrealLogEvent() = default;
    
    // reader
    static UnrealLogEvent read(rd::SerializationCtx& ctx, rd::Buffer & buffer);
    
    // writer
    void write(rd::SerializationCtx& ctx, rd::Buffer& buffer) const override;
    
    // virtual init
    
    // identify
    
    // getters
    LogMessageInfo const & get_info() const;
    FString const & get_text() const;
    TArray<rd::Wrapper<StringRange>> const & get_bpPathRanges() const;
    TArray<rd::Wrapper<StringRange>> const & get_methodRanges() const;
    
    // intern

private:
    // equals trait
    bool equals(rd::ISerializable const& object) const override;

public:
    // equality operators
    friend bool operator==(const UnrealLogEvent &lhs, const UnrealLogEvent &rhs);
    friend bool operator!=(const UnrealLogEvent &lhs, const UnrealLogEvent &rhs);
    // hash code trait
    size_t hashCode() const noexcept override;
    // type name trait
    std::string type_name() const override;
    // static type name trait
    static std::string static_type_name();

private:
    // polymorphic to string
    std::string toString() const override;

public:
    // external to string
    friend std::string to_string(const UnrealLogEvent & value);
};

}
}

// hash code trait
namespace rd {

template <>
struct hash<JetBrains::EditorPlugin::UnrealLogEvent> {
    size_t operator()(const JetBrains::EditorPlugin::UnrealLogEvent & value) const noexcept {
        return value.hashCode();
    }
};

}

#ifdef __cpp_structured_bindings
// tuple trait
namespace std {

template <>
class tuple_size<JetBrains::EditorPlugin::UnrealLogEvent> : public integral_constant<size_t, 4> {};

template <size_t I>
class tuple_element<I, JetBrains::EditorPlugin::UnrealLogEvent> {
public:
    using type = decltype (declval<JetBrains::EditorPlugin::UnrealLogEvent>().get<I>());
};

}
#endif

#ifdef _MSC_VER
#pragma warning( pop )
#endif



#endif // UNREALLOGEVENT_GENERATED_H
