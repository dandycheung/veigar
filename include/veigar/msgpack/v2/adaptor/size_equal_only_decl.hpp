#ifndef __VEIGAR_MSGPACK_V2_ADAPTOR_SIZE_EQUAL_ONLY_DECL_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V2_ADAPTOR_SIZE_EQUAL_ONLY_DECL_HPP
//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V2_TYPE_SIZE_EQUAL_ONLY_DECL_HPP
#define MSGPACK_V2_TYPE_SIZE_EQUAL_ONLY_DECL_HPP

#include "veigar/msgpack/v1/adaptor/size_equal_only_decl.hpp"

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

namespace type {

using v1::type::size_equal_only;
using v1::type::make_size_equal_only;
using v1::type::size;

} // namespace type

/// @cond
} // MSGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

} // namespace veigar_msgpack

#endif // MSGPACK_V2_TYPE_SIZE_EQUAL_ONLY_DECL_HPP

#endif // !__VEIGAR_MSGPACK_V2_ADAPTOR_SIZE_EQUAL_ONLY_DECL_HPP