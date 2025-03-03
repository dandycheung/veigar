#ifndef __VEIGAR_MSGPACK_V3_CREATE_OBJECT_VISITOR_DECL_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V3_CREATE_OBJECT_VISITOR_DECL_HPP
//
// MessagePack for C++ deserializing routine
//
// Copyright (C) 2018 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V3_CREATE_OBJECT_VISITOR_DECL_HPP
#define MSGPACK_V3_CREATE_OBJECT_VISITOR_DECL_HPP

#include "veigar/msgpack/v2/create_object_visitor_decl.hpp"

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v3) {
/// @endcond

namespace detail {

using v2::detail::create_object_visitor;

} // detail

/// @cond
}  // MSGPACK_API_VERSION_NAMESPACE(v3)
/// @endcond

}  // namespace veigar_msgpack

#endif // MSGPACK_V3_CREATE_OBJECT_VISITOR_DECL_HPP

#endif // !__VEIGAR_MSGPACK_V3_CREATE_OBJECT_VISITOR_DECL_HPP