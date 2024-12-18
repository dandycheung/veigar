#ifndef __VEIGAR_MSGPACK_V2_OBJECT_DECL_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V2_OBJECT_DECL_HPP
//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V2_OBJECT_DECL_HPP
#define MSGPACK_V2_OBJECT_DECL_HPP

#include "veigar/msgpack/v1/object_decl.hpp"
#include "veigar/msgpack/adaptor/adaptor_base.hpp"

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

using v1::object_handle;

namespace detail {

using v1::detail::add_ext_type_size;

} // namespace detail

using v1::aligned_zone_size;

using v1::clone;

namespace detail {

using v1::detail::packer_serializer;

} // namespace detail

using v1::object_parser;
using v1::object_pack_visitor;
using v1::object_stringize_visitor;

using v1::operator==;
using v1::operator!=;

/// @cond
}  // MSGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

}  // namespace veigar_msgpack

#endif // MSGPACK_V2_OBJECT_DECL_HPP

#endif // !__VEIGAR_MSGPACK_V2_OBJECT_DECL_HPP