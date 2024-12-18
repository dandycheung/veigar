#ifndef __VEIGAR_MSGPACK_V1_ADAPTOR_ARRAY_REF_DECL_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V1_ADAPTOR_ARRAY_REF_DECL_HPP
//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2008-2016 FURUHASHI Sadayuki and KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V1_TYPE_ARRAY_REF_DECL_HPP
#define MSGPACK_V1_TYPE_ARRAY_REF_DECL_HPP

#include "veigar/msgpack/versioning.hpp"
#include "veigar/msgpack/adaptor/adaptor_base.hpp"
#include "veigar/msgpack/object.hpp"

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

namespace type {

template <typename T>
struct array_ref;

template <typename T>
typename veigar_msgpack::enable_if<
    !veigar_msgpack::is_array<T const>::value,
    array_ref<T const>
>::type
make_array_ref(T const& t);

template <typename T>
typename veigar_msgpack::enable_if<
    !veigar_msgpack::is_array<T>::value,
    array_ref<T>
>::type
make_array_ref(T& t);

template <typename T, std::size_t N>
array_ref<const T[N]> make_array_ref(const T(&t)[N]);

template <typename T, std::size_t N>
array_ref<T[N]> make_array_ref(T(&t)[N]);

} // namespace type

/// @cond
} // MSGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

} // namespace veigar_msgpack

#endif // MSGPACK_V1_TYPE_ARRAY_REF_DECL_HPP

#endif // !__VEIGAR_MSGPACK_V1_ADAPTOR_ARRAY_REF_DECL_HPP