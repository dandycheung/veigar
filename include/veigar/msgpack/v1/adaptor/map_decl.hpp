#ifndef __VEIGAR_MSGPACK_V1_ADAPTOR_MAP_DECL_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V1_ADAPTOR_MAP_DECL_HPP
//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V1_TYPE_MAP_DECL_HPP
#define MSGPACK_V1_TYPE_MAP_DECL_HPP

#include "veigar/msgpack/versioning.hpp"

#include <algorithm>

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace type {

template <typename K, typename V, typename Compare = std::less<K>, typename Alloc = std::allocator<std::pair<K, V> > >
class assoc_vector;

}  //namespace type

/// @cond
}  // MSGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace veigar_msgpack

#endif // MSGPACK_V1_TYPE_MAP_DECL_HPP

#endif // !__VEIGAR_MSGPACK_V1_ADAPTOR_MAP_DECL_HPP