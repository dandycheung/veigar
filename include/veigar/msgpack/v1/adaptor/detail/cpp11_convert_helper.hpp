#ifndef __VEIGAR_MSGPACK_V1_ADAPTOR_DETAIL_CPP11_CONVERT_HELPER_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V1_ADAPTOR_DETAIL_CPP11_CONVERT_HELPER_HPP
//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2017 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V1_CPP11_CONVERT_HELPER_HPP
#define MSGPACK_V1_CPP11_CONVERT_HELPER_HPP

#include <tuple>

#include "veigar/msgpack/object_fwd.hpp"

namespace veigar_msgpack {
/// @cond
MSGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond
namespace type {

template <typename T>
inline typename std::enable_if<
    has_as<T>::value
>::type
convert_helper(veigar_msgpack::object const& o, T& t) {
    t = o.as<T>();
}
template <typename T>
inline typename std::enable_if<
    !has_as<T>::value
>::type
convert_helper(veigar_msgpack::object const& o, T& t) {
    o.convert(t);
}

}  // namespace type

/// @cond
}  // MSGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond
}  // namespace veigar_msgpack

#endif // MSGPACK_V1_CPP11_CONVERT_HELPER_HPP

#endif // !__VEIGAR_MSGPACK_V1_ADAPTOR_DETAIL_CPP11_CONVERT_HELPER_HPP