/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/xiaxin/ardupilot/modules/DroneCAN/DSDL/uavcan/tunnel/2010.Broadcast.uavcan
 */

#ifndef UAVCAN_TUNNEL_BROADCAST_HPP_INCLUDED
#define UAVCAN_TUNNEL_BROADCAST_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

#include <uavcan/tunnel/Protocol.hpp>

/******************************* Source text **********************************
#
# This message struct carries arbitrary data in the format of the specified high-level protocol.
# The data will be delivered to all nodes that are interested in tunneled protocols.
# Finer addressing schemes may be implemented using the means provided by the encapsulated protocol.
# The channelID allows for additional routing between the source and target nodes.

Protocol protocol
uint8 channel_id

uint8[<=60] buffer    # TAO rules apply
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.tunnel.Broadcast
uavcan.tunnel.Protocol protocol
saturated uint8 channel_id
saturated uint8[<=60] buffer
******************************************************************************/

#undef protocol
#undef channel_id
#undef buffer

namespace uavcan
{
namespace tunnel
{

template <int _tmpl>
struct UAVCAN_EXPORT Broadcast_
{
    typedef const Broadcast_<_tmpl>& ParameterType;
    typedef Broadcast_<_tmpl>& ReferenceType;

    struct ConstantTypes
    {
    };

    struct FieldTypes
    {
        typedef ::uavcan::tunnel::Protocol protocol;
        typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > channel_id;
        typedef ::uavcan::Array< ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeDynamic, 60 > buffer;
    };

    enum
    {
        MinBitLen
            = FieldTypes::protocol::MinBitLen
            + FieldTypes::channel_id::MinBitLen
            + FieldTypes::buffer::MinBitLen
    };

    enum
    {
        MaxBitLen
            = FieldTypes::protocol::MaxBitLen
            + FieldTypes::channel_id::MaxBitLen
            + FieldTypes::buffer::MaxBitLen
    };

    // Constants

    // Fields
    typename ::uavcan::StorageType< typename FieldTypes::protocol >::Type protocol;
    typename ::uavcan::StorageType< typename FieldTypes::channel_id >::Type channel_id;
    typename ::uavcan::StorageType< typename FieldTypes::buffer >::Type buffer;

    Broadcast_()
        : protocol()
        , channel_id()
        , buffer()
    {
        ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

#if UAVCAN_DEBUG
        /*
         * Cross-checking MaxBitLen provided by the DSDL compiler.
         * This check shall never be performed in user code because MaxBitLen value
         * actually depends on the nested types, thus it is not invariant.
         */
        ::uavcan::StaticAssert<502 == MaxBitLen>::check();
#endif
    }

    bool operator==(ParameterType rhs) const;
    bool operator!=(ParameterType rhs) const { return !operator==(rhs); }

    /**
     * This comparison is based on @ref uavcan::areClose(), which ensures proper comparison of
     * floating point fields at any depth.
     */
    bool isClose(ParameterType rhs) const;

    static int encode(ParameterType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    static int decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
                      ::uavcan::TailArrayOptimizationMode tao_mode = ::uavcan::TailArrayOptEnabled);

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindMessage };
    enum { DefaultDataTypeID = 2010 };

    static const char* getDataTypeFullName()
    {
        return "uavcan.tunnel.Broadcast";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool Broadcast_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        protocol == rhs.protocol &&
        channel_id == rhs.channel_id &&
        buffer == rhs.buffer;
}

template <int _tmpl>
bool Broadcast_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(protocol, rhs.protocol) &&
        ::uavcan::areClose(channel_id, rhs.channel_id) &&
        ::uavcan::areClose(buffer, rhs.buffer);
}

template <int _tmpl>
int Broadcast_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::protocol::encode(self.protocol, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::channel_id::encode(self.channel_id, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::buffer::encode(self.buffer, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int Broadcast_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::protocol::decode(self.protocol, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::channel_id::decode(self.channel_id, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::buffer::decode(self.buffer, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
template <int _tmpl>
::uavcan::DataTypeSignature Broadcast_<_tmpl>::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0x3961079075C72ABFULL);

    FieldTypes::protocol::extendDataTypeSignature(signature);
    FieldTypes::channel_id::extendDataTypeSignature(signature);
    FieldTypes::buffer::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

/*
 * Final typedef
 */
typedef Broadcast_<0> Broadcast;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::uavcan::tunnel::Broadcast > _uavcan_gdtr_registrator_Broadcast;

}

} // Namespace tunnel
} // Namespace uavcan

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::uavcan::tunnel::Broadcast >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::uavcan::tunnel::Broadcast::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::uavcan::tunnel::Broadcast >::stream(Stream& s, ::uavcan::tunnel::Broadcast::ParameterType obj, const int level)
{
    (void)s;
    (void)obj;
    (void)level;
    if (level > 0)
    {
        s << '\n';
        for (int pos = 0; pos < level; pos++)
        {
            s << "  ";
        }
    }
    s << "protocol: ";
    YamlStreamer< ::uavcan::tunnel::Broadcast::FieldTypes::protocol >::stream(s, obj.protocol, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "channel_id: ";
    YamlStreamer< ::uavcan::tunnel::Broadcast::FieldTypes::channel_id >::stream(s, obj.channel_id, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "buffer: ";
    YamlStreamer< ::uavcan::tunnel::Broadcast::FieldTypes::buffer >::stream(s, obj.buffer, level + 1);
}

}

namespace uavcan
{
namespace tunnel
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::uavcan::tunnel::Broadcast::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::uavcan::tunnel::Broadcast >::stream(s, obj, 0);
    return s;
}

} // Namespace tunnel
} // Namespace uavcan

#endif // UAVCAN_TUNNEL_BROADCAST_HPP_INCLUDED