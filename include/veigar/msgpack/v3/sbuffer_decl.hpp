#ifndef __VEIGAR_MSGPACK_V3_SBUFFER_DECL_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V3_SBUFFER_DECL_HPP
//
// MessagePack for C++ simple buffer implementation
//
// Copyright (C) 2018 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V3_SBUFFER_DECL_HPP
#define MSGPACK_V3_SBUFFER_DECL_HPP

#include "veigar/msgpack/versioning.hpp"

#ifndef MSGPACK_SBUFFER_INIT_SIZE
#define MSGPACK_SBUFFER_INIT_SIZE 8192
#endif

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v3) {
/// @endcond

using v2::sbuffer;

/// @cond
}  // MSGPACK_API_VERSION_NAMESPACE(v3)
/// @endcond

}  // namespace veigar_msgpack

#endif // MSGPACK_V3_SBUFFER_DECL_HPP

#endif // !__VEIGAR_MSGPACK_V3_SBUFFER_DECL_HPP