/*
 * UAVCAN data structure definition for libuavcan.
 *
 * Autogenerated, do not edit.
 *
 * Source file: /home/xiaxin/ardupilot/modules/DroneCAN/DSDL/uavcan/protocol/enumeration/15.Begin.uavcan
 */

#ifndef UAVCAN_PROTOCOL_ENUMERATION_BEGIN_HPP_INCLUDED
#define UAVCAN_PROTOCOL_ENUMERATION_BEGIN_HPP_INCLUDED

#include <uavcan/build_config.hpp>
#include <uavcan/node/global_data_type_registry.hpp>
#include <uavcan/marshal/types.hpp>

/******************************* Source text **********************************
#
# This service instructs the node to begin the process of automated enumeration.
#

#
# The node will automatically leave enumeration mode upon expiration of this timeout.
#
uint16 TIMEOUT_CANCEL   = 0     # Stop enumeration immediately
uint16 TIMEOUT_INFINITE = 65535 # Do not stop until explicitly requested
uint16 timeout_sec              # [Seconds]

#
# Name of the parameter to enumerate, e.g. ESC index.
# If the name is left empty, the node will infer the parameter name automatically (autodetect).
# It is highly recommended to always use autodetection in order to avoid dependency on hard-coded parameter names,
# and also allow the enumeratee to possibly enumerate multiple different parameters at once.
# The rule of thumb is to always leave this parameter empty unless you really know what you're doing.
#
uint8[<=92] parameter_name

---

uint8 ERROR_OK                  = 0     # Success
uint8 ERROR_INVALID_MODE        = 1     # The node cannot perform enumeration in its current operating mode
uint8 ERROR_INVALID_PARAMETER   = 2     # The node cannot enumerate on the requested parameter, or it doesn't exist
uint8 ERROR_UNSUPPORTED         = 3     # The node cannot perform enumeration in its current configuration
uint8 ERROR_UNKNOWN             = 255   # Generic error
uint8 error
******************************************************************************/

/********************* DSDL signature source definition ***********************
uavcan.protocol.enumeration.Begin
saturated uint16 timeout_sec
saturated uint8[<=92] parameter_name
---
saturated uint8 error
******************************************************************************/

#undef timeout_sec
#undef parameter_name
#undef TIMEOUT_CANCEL
#undef TIMEOUT_INFINITE
#undef error
#undef ERROR_OK
#undef ERROR_INVALID_MODE
#undef ERROR_INVALID_PARAMETER
#undef ERROR_UNSUPPORTED
#undef ERROR_UNKNOWN

namespace uavcan
{
namespace protocol
{
namespace enumeration
{

struct UAVCAN_EXPORT Begin_
{
    template <int _tmpl>
    struct Request_
    {
        typedef const Request_<_tmpl>& ParameterType;
        typedef Request_<_tmpl>& ReferenceType;

        struct ConstantTypes
        {
            typedef ::uavcan::IntegerSpec< 16, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > TIMEOUT_CANCEL;
            typedef ::uavcan::IntegerSpec< 16, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > TIMEOUT_INFINITE;
        };

        struct FieldTypes
        {
            typedef ::uavcan::IntegerSpec< 16, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > timeout_sec;
            typedef ::uavcan::Array< ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate >, ::uavcan::ArrayModeDynamic, 92 > parameter_name;
        };

        enum
        {
            MinBitLen
                = FieldTypes::timeout_sec::MinBitLen
                + FieldTypes::parameter_name::MinBitLen
        };

        enum
        {
            MaxBitLen
                = FieldTypes::timeout_sec::MaxBitLen
                + FieldTypes::parameter_name::MaxBitLen
        };

        // Constants
        static const typename ::uavcan::StorageType< typename ConstantTypes::TIMEOUT_CANCEL >::Type TIMEOUT_CANCEL; // 0
        static const typename ::uavcan::StorageType< typename ConstantTypes::TIMEOUT_INFINITE >::Type TIMEOUT_INFINITE; // 65535

        // Fields
        typename ::uavcan::StorageType< typename FieldTypes::timeout_sec >::Type timeout_sec;
        typename ::uavcan::StorageType< typename FieldTypes::parameter_name >::Type parameter_name;

        Request_()
            : timeout_sec()
            , parameter_name()
        {
            ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

    #if UAVCAN_DEBUG
            /*
             * Cross-checking MaxBitLen provided by the DSDL compiler.
             * This check shall never be performed in user code because MaxBitLen value
             * actually depends on the nested types, thus it is not invariant.
             */
            ::uavcan::StaticAssert<759 == MaxBitLen>::check();
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

    };

    template <int _tmpl>
    struct Response_
    {
        typedef const Response_<_tmpl>& ParameterType;
        typedef Response_<_tmpl>& ReferenceType;

        struct ConstantTypes
        {
            typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > ERROR_OK;
            typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > ERROR_INVALID_MODE;
            typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > ERROR_INVALID_PARAMETER;
            typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > ERROR_UNSUPPORTED;
            typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > ERROR_UNKNOWN;
        };

        struct FieldTypes
        {
            typedef ::uavcan::IntegerSpec< 8, ::uavcan::SignednessUnsigned, ::uavcan::CastModeSaturate > error;
        };

        enum
        {
            MinBitLen
                = FieldTypes::error::MinBitLen
        };

        enum
        {
            MaxBitLen
                = FieldTypes::error::MaxBitLen
        };

        // Constants
        static const typename ::uavcan::StorageType< typename ConstantTypes::ERROR_OK >::Type ERROR_OK; // 0
        static const typename ::uavcan::StorageType< typename ConstantTypes::ERROR_INVALID_MODE >::Type ERROR_INVALID_MODE; // 1
        static const typename ::uavcan::StorageType< typename ConstantTypes::ERROR_INVALID_PARAMETER >::Type ERROR_INVALID_PARAMETER; // 2
        static const typename ::uavcan::StorageType< typename ConstantTypes::ERROR_UNSUPPORTED >::Type ERROR_UNSUPPORTED; // 3
        static const typename ::uavcan::StorageType< typename ConstantTypes::ERROR_UNKNOWN >::Type ERROR_UNKNOWN; // 255

        // Fields
        typename ::uavcan::StorageType< typename FieldTypes::error >::Type error;

        Response_()
            : error()
        {
            ::uavcan::StaticAssert<_tmpl == 0>::check();  // Usage check

    #if UAVCAN_DEBUG
            /*
             * Cross-checking MaxBitLen provided by the DSDL compiler.
             * This check shall never be performed in user code because MaxBitLen value
             * actually depends on the nested types, thus it is not invariant.
             */
            ::uavcan::StaticAssert<8 == MaxBitLen>::check();
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

    };

    typedef Request_<0> Request;
    typedef Response_<0> Response;

    /*
     * Static type info
     */
    enum { DataTypeKind = ::uavcan::DataTypeKindService };
    enum { DefaultDataTypeID = 15 };

    static const char* getDataTypeFullName()
    {
        return "uavcan.protocol.enumeration.Begin";
    }

    static void extendDataTypeSignature(::uavcan::DataTypeSignature& signature)
    {
        signature.extend(getDataTypeSignature());
    }

    static ::uavcan::DataTypeSignature getDataTypeSignature();

private:
    Begin_(); // Don't create objects of this type. Use Request/Response instead.
};

/*
 * Out of line struct method definitions
 */

template <int _tmpl>
bool Begin_::Request_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        timeout_sec == rhs.timeout_sec &&
        parameter_name == rhs.parameter_name;
}

template <int _tmpl>
bool Begin_::Request_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(timeout_sec, rhs.timeout_sec) &&
        ::uavcan::areClose(parameter_name, rhs.parameter_name);
}

template <int _tmpl>
int Begin_::Request_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::timeout_sec::encode(self.timeout_sec, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::parameter_name::encode(self.parameter_name, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int Begin_::Request_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::timeout_sec::decode(self.timeout_sec, codec,  ::uavcan::TailArrayOptDisabled);
    if (res <= 0)
    {
        return res;
    }
    res = FieldTypes::parameter_name::decode(self.parameter_name, codec,  tao_mode);
    return res;
}

template <int _tmpl>
bool Begin_::Response_<_tmpl>::operator==(ParameterType rhs) const
{
    return
        error == rhs.error;
}

template <int _tmpl>
bool Begin_::Response_<_tmpl>::isClose(ParameterType rhs) const
{
    return
        ::uavcan::areClose(error, rhs.error);
}

template <int _tmpl>
int Begin_::Response_<_tmpl>::encode(ParameterType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::error::encode(self.error, codec,  tao_mode);
    return res;
}

template <int _tmpl>
int Begin_::Response_<_tmpl>::decode(ReferenceType self, ::uavcan::ScalarCodec& codec,
    ::uavcan::TailArrayOptimizationMode tao_mode)
{
    (void)self;
    (void)codec;
    (void)tao_mode;
    int res = 1;
    res = FieldTypes::error::decode(self.error, codec,  tao_mode);
    return res;
}

/*
 * Out of line type method definitions
 */
inline ::uavcan::DataTypeSignature Begin_::getDataTypeSignature()
{
    ::uavcan::DataTypeSignature signature(0x196AE06426A3B5D8ULL);

    Request::FieldTypes::timeout_sec::extendDataTypeSignature(signature);
    Request::FieldTypes::parameter_name::extendDataTypeSignature(signature);

    Response::FieldTypes::error::extendDataTypeSignature(signature);

    return signature;
}

/*
 * Out of line constant definitions
 */

template <int _tmpl>
const typename ::uavcan::StorageType< typename Begin_::Request_<_tmpl>::ConstantTypes::TIMEOUT_CANCEL >::Type
    Begin_::Request_<_tmpl>::TIMEOUT_CANCEL = 0U; // 0

template <int _tmpl>
const typename ::uavcan::StorageType< typename Begin_::Request_<_tmpl>::ConstantTypes::TIMEOUT_INFINITE >::Type
    Begin_::Request_<_tmpl>::TIMEOUT_INFINITE = 65535U; // 65535

template <int _tmpl>
const typename ::uavcan::StorageType< typename Begin_::Response_<_tmpl>::ConstantTypes::ERROR_OK >::Type
    Begin_::Response_<_tmpl>::ERROR_OK = 0U; // 0

template <int _tmpl>
const typename ::uavcan::StorageType< typename Begin_::Response_<_tmpl>::ConstantTypes::ERROR_INVALID_MODE >::Type
    Begin_::Response_<_tmpl>::ERROR_INVALID_MODE = 1U; // 1

template <int _tmpl>
const typename ::uavcan::StorageType< typename Begin_::Response_<_tmpl>::ConstantTypes::ERROR_INVALID_PARAMETER >::Type
    Begin_::Response_<_tmpl>::ERROR_INVALID_PARAMETER = 2U; // 2

template <int _tmpl>
const typename ::uavcan::StorageType< typename Begin_::Response_<_tmpl>::ConstantTypes::ERROR_UNSUPPORTED >::Type
    Begin_::Response_<_tmpl>::ERROR_UNSUPPORTED = 3U; // 3

template <int _tmpl>
const typename ::uavcan::StorageType< typename Begin_::Response_<_tmpl>::ConstantTypes::ERROR_UNKNOWN >::Type
    Begin_::Response_<_tmpl>::ERROR_UNKNOWN = 255U; // 255

/*
 * Final typedef
 */
typedef Begin_ Begin;

namespace
{

const ::uavcan::DefaultDataTypeRegistrator< ::uavcan::protocol::enumeration::Begin > _uavcan_gdtr_registrator_Begin;

}

} // Namespace enumeration
} // Namespace protocol
} // Namespace uavcan

/*
 * YAML streamer specialization
 */
namespace uavcan
{

template <>
class UAVCAN_EXPORT YamlStreamer< ::uavcan::protocol::enumeration::Begin::Request >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::uavcan::protocol::enumeration::Begin::Request::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::uavcan::protocol::enumeration::Begin::Request >::stream(Stream& s, ::uavcan::protocol::enumeration::Begin::Request::ParameterType obj, const int level)
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
    s << "timeout_sec: ";
    YamlStreamer< ::uavcan::protocol::enumeration::Begin::Request::FieldTypes::timeout_sec >::stream(s, obj.timeout_sec, level + 1);
    s << '\n';
    for (int pos = 0; pos < level; pos++)
    {
        s << "  ";
    }
    s << "parameter_name: ";
    YamlStreamer< ::uavcan::protocol::enumeration::Begin::Request::FieldTypes::parameter_name >::stream(s, obj.parameter_name, level + 1);
}

template <>
class UAVCAN_EXPORT YamlStreamer< ::uavcan::protocol::enumeration::Begin::Response >
{
public:
    template <typename Stream>
    static void stream(Stream& s, ::uavcan::protocol::enumeration::Begin::Response::ParameterType obj, const int level);
};

template <typename Stream>
void YamlStreamer< ::uavcan::protocol::enumeration::Begin::Response >::stream(Stream& s, ::uavcan::protocol::enumeration::Begin::Response::ParameterType obj, const int level)
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
    s << "error: ";
    YamlStreamer< ::uavcan::protocol::enumeration::Begin::Response::FieldTypes::error >::stream(s, obj.error, level + 1);
}

}

namespace uavcan
{
namespace protocol
{
namespace enumeration
{

template <typename Stream>
inline Stream& operator<<(Stream& s, ::uavcan::protocol::enumeration::Begin::Request::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::uavcan::protocol::enumeration::Begin::Request >::stream(s, obj, 0);
    return s;
}

template <typename Stream>
inline Stream& operator<<(Stream& s, ::uavcan::protocol::enumeration::Begin::Response::ParameterType obj)
{
    ::uavcan::YamlStreamer< ::uavcan::protocol::enumeration::Begin::Response >::stream(s, obj, 0);
    return s;
}

} // Namespace enumeration
} // Namespace protocol
} // Namespace uavcan

#endif // UAVCAN_PROTOCOL_ENUMERATION_BEGIN_HPP_INCLUDED