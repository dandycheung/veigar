#ifndef __VEIGAR_MSGPACK_V1_ADAPTOR_CPP17_ARRAY_BYTE_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V1_ADAPTOR_CPP17_ARRAY_BYTE_HPP
//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2021 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V1_TYPE_ARRAY_BYTE_HPP
#define MSGPACK_V1_TYPE_ARRAY_BYTE_HPP

#include "veigar/msgpack/cpp_version.hpp"

#if MSGPACK_CPP_VERSION >= 201703

#include "veigar/msgpack/versioning.hpp"
#include "veigar/msgpack/adaptor/adaptor_base.hpp"
#include "veigar/msgpack/object.hpp"
#include "veigar/msgpack/adaptor/check_container_size.hpp"

#include <array>
#include <cstring>
#include <cstddef>

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace adaptor {

template <std::size_t N>
struct convert<std::array<std::byte, N> > {
    veigar_msgpack::object const& operator()(veigar_msgpack::object const& o, std::array<std::byte, N>& v) const {
        switch (o.type) {
        case veigar_msgpack::type::BIN:
            if (o.via.bin.size != N)
                throw veigar_msgpack::type_error();
            if (N != 0) {
#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif // defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
                std::memcpy(&v.front(), o.via.bin.ptr, o.via.bin.size);
#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
            }
            break;
        case veigar_msgpack::type::STR:
            if (o.via.bin.size != N)
                throw veigar_msgpack::type_error();
            if (N != 0) {
#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif // defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
                std::memcpy(&v.front(), o.via.str.ptr, o.via.str.size);
#if defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif // defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7)) && !defined(__clang__)
            }
            break;
        default:
            throw veigar_msgpack::type_error();
            break;
        }
        return o;
    }
};

template <std::size_t N>
struct pack<std::array<std::byte, N> > {
    template <typename Stream>
    veigar_msgpack::packer<Stream>& operator()(veigar_msgpack::packer<Stream>& o, const std::array<std::byte, N>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.pack_bin(size);
        if (size != 0) {
            o.pack_bin_body(reinterpret_cast<char const*>(&v.front()), size);
        }

        return o;
    }
};

template <std::size_t N>
struct object<std::array<std::byte, N> > {
    void operator()(veigar_msgpack::object& o, const std::array<std::byte, N>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.type = veigar_msgpack::type::BIN;
        if (size != 0) {
            o.via.bin.ptr = reinterpret_cast<char const*>(&v.front());
        }
        o.via.bin.size = size;
    }
};

template <std::size_t N>
struct object_with_zone<std::array<std::byte, N> > {
    void operator()(veigar_msgpack::object::with_zone& o, const std::array<std::byte, N>& v) const {
        uint32_t size = checked_get_container_size(v.size());
        o.type = veigar_msgpack::type::BIN;
        o.via.bin.size = size;
        if (size != 0) {
            char* ptr = static_cast<char*>(o.zone.allocate_align(size, MSGPACK_ZONE_ALIGNOF(char)));
            o.via.bin.ptr = ptr;
            std::memcpy(ptr, &v.front(), size);
        }
    }
};

} // namespace adaptor

/// @cond
} // MSGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace veigar_msgpack

#endif // MSGPACK_CPP_VERSION >= 201703

#endif // MSGPACK_V1_TYPE_ARRAY_BYTE_HPP

#endif // !__VEIGAR_MSGPACK_V1_ADAPTOR_CPP17_ARRAY_BYTE_HPP