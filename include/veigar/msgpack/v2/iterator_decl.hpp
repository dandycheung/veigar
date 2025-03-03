#ifndef __VEIGAR_MSGPACK_V2_ITERATOR_DECL_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V2_ITERATOR_DECL_HPP
//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//

#ifndef MSGPACK_V2_ITERATOR_DECL_HPP
#define MSGPACK_V2_ITERATOR_DECL_HPP
#if !defined(MSGPACK_USE_CPP03)

#include "veigar/msgpack/v1/iterator_decl.hpp"

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

using v1::begin;
using v1::end;

/// @cond
}
/// @endcond

}

#endif // !defined(MSGPACK_USE_CPP03)
#endif // MSGPACK_V2_ITERATOR_DECL_HPP

#endif // !__VEIGAR_MSGPACK_V2_ITERATOR_DECL_HPP