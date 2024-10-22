#ifndef __VEIGAR_MSGPACK_V1_ADAPTOR_SIZE_EQUAL_ONLY_DECL_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V1_ADAPTOR_SIZE_EQUAL_ONLY_DECL_HPP
//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V1_TYPE_SIZE_EQUAL_ONLY_DECL_HPP
#define MSGPACK_V1_TYPE_SIZE_EQUAL_ONLY_DECL_HPP

#include "veigar/msgpack/versioning.hpp"
#include "veigar/msgpack/adaptor/adaptor_base.hpp"
#include "veigar/msgpack/object.hpp"
#include "veigar/msgpack/adaptor/msgpack_tuple.hpp"

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace type {

template <typename T>
struct size_equal_only;

template <typename T>
size_equal_only<T> make_size_equal_only(T& t);

template <typename T>
std::size_t size(T const& t);

template <typename T, std::size_t N>
std::size_t size(const T(&)[N]);

#if !defined(MSGPACK_USE_CPP03)

template <typename... T>
std::size_t size(std::tuple<T...> const&);

#endif // !defined(MSGPACK_USE_CPP03)

} // namespace type

/// @cond
} // MSGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace veigar_msgpack

#endif // MSGPACK_V1_TYPE_SIZE_EQUAL_ONLY_DECL_HPP

#endif // !__VEIGAR_MSGPACK_V1_ADAPTOR_SIZE_EQUAL_ONLY_DECL_HPP