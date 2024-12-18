#ifndef __VEIGAR_MSGPACK_V3_ADAPTOR_ADAPTOR_BASE_DECL_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V3_ADAPTOR_ADAPTOR_BASE_DECL_HPP
//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V3_ADAPTOR_BASE_DECL_HPP
#define MSGPACK_V3_ADAPTOR_BASE_DECL_HPP

#include "veigar/msgpack/v2/adaptor/adaptor_base_decl.hpp"

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v3) {
/// @endcond

using v2::packer;

namespace adaptor {

// Adaptor functors

template <typename T, typename Enabler = void>
struct convert;

template <typename T, typename Enabler = void>
struct pack;

template <typename T, typename Enabler = void>
struct object;

template <typename T, typename Enabler = void>
struct object_with_zone;

} // namespace adaptor

// operators

using v2::operator>>;
using v2::operator<<;

/// @cond
} // MSGPACK_API_VERSION_NAMESPACE(v3)
/// @endcond

} // namespace veigar_msgpack

#endif // MSGPACK_V3_ADAPTOR_BASE_DECL_HPP

#endif // !__VEIGAR_MSGPACK_V3_ADAPTOR_ADAPTOR_BASE_DECL_HPP