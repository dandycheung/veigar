#ifndef __VEIGAR_MSGPACK_V1_ADAPTOR_CPP11_ARRAY_CHAR_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V1_ADAPTOR_CPP11_ARRAY_CHAR_HPP
//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2014-2015 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V1_TYPE_CPP11_ARRAY_CHAR_HPP
#define MSGPACK_V1_TYPE_CPP11_ARRAY_CHAR_HPP

#include "veigar/msgpack/versioning.hpp"
#include "veigar/msgpack/adaptor/adaptor_base.hpp"
#include "veigar/msgpack/object.hpp"
#include "veigar/msgpack/adaptor/check_container_size.hpp"

#include <array>
#include <cstring>

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <std::size_t N>
struct convert<std::array<char, N>> {
    veigar_msgpack::object const& operator()(veigar_msgpack::object const& o, std::array<char, N>& v) const {
        switch (o.type) {
        case veigar_msgpack::type::BIN:
            if(o.via.bin.size > N) { throw veigar_msgpack::type_error(); }
            std::memcpy(v.data(), o.via.bin.ptr, o.via.bin.size);
            break;
        case veigar_msgpack::type::STR:
            if(o.via.str.size > N) { throw veigar_msgpack::type_error(); }
            std::memcpy(v.data(), o.via.str.ptr, N);
            break;
        default:
            throw veigar_msgpack::type_error();
            break;
        }
        return o;
    }
};

template <>
struct convert<std::array<char, 0>> {
    veigar_msgpack::object const& operator()(veigar_msgpack::object const& o, std::array<char, 0>&) const {
        return o;
    }
};

template <std::size_t N>
struct pack<std::array<char, N>> {
    template <typename Stream>
    veigar_msgpack::packer<Stream>& operator()(veigar_msgpack::packer<Stream>& o, const std::array<char, N>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.pack_bin(size);
        o.pack_bin_body(v.data(), size);

        return o;
    }
};

template <std::size_t N>
struct object<std::array<char, N>> {
    void operator()(veigar_msgpack::object& o, const std::array<char, N>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.type = veigar_msgpack::type::BIN;
        o.via.bin.ptr = v.data();
        o.via.bin.size = size;
    }
};

template <std::size_t N>
struct object_with_zone<std::array<char, N>> {
    void operator()(veigar_msgpack::object::with_zone& o, const std::array<char, N>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.type = veigar_msgpack::type::BIN;
        char* ptr = static_cast<char*>(o.zone.allocate_align(size, MSGPACK_ZONE_ALIGNOF(char)));
        o.via.bin.ptr = ptr;
        o.via.bin.size = size;
        std::memcpy(ptr, v.data(), size);
    }
};

} // namespace adaptor

/// @cond
} // MSGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace veigar_msgpack

#endif // MSGPACK_V1_TYPE_CPP11_ARRAY_CHAR_HPP

#endif // !__VEIGAR_MSGPACK_V1_ADAPTOR_CPP11_ARRAY_CHAR_HPP