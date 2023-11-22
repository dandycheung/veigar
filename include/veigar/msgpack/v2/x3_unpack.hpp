//
// MessagePack for C++ deserializing routine
//
// Copyright (C) 2017 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V2_X3_UNPACK_HPP
#define MSGPACK_V2_X3_UNPACK_HPP

#if defined(MSGPACK_USE_X3_PARSE)

#include <boost/version.hpp>

#if BOOST_VERSION >= 106100

#include "veigar/msgpack/versioning.hpp"
#include "veigar/msgpack/create_object_visitor.hpp"
#include "veigar/msgpack/x3_unpack_decl.hpp"
#include "veigar/msgpack/x3_parse.hpp"

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

namespace detail {

template <typename Iterator>
inline void
unpack_imp(Iterator&& begin, Iterator&& end,
           veigar_msgpack::zone& result_zone, veigar_msgpack::object& result, bool& referenced,
           unpack_reference_func f, void* user_data,
           unpack_limit const& limit)
{
    create_object_visitor v(f, user_data, limit);
    v.set_zone(result_zone);
    referenced = false;
    v.set_referenced(referenced);
    if (!parse(std::forward<Iterator>(begin), std::forward<Iterator>(end), v)) {
        throw veigar_msgpack::parse_error("parse error");
    }
    referenced = v.referenced();
    result = v.data();
}

} // namespace detail


template <typename Iterator>
inline veigar_msgpack::object_handle unpack(
    Iterator&& begin, Iterator&& end,
    bool& referenced,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    veigar_msgpack::object obj;
    veigar_msgpack::unique_ptr<veigar_msgpack::zone> z(new veigar_msgpack::zone);
    referenced = false;
    detail::unpack_imp(
        std::forward<Iterator>(begin), std::forward<Iterator>(end), *z, obj, referenced, f, user_data, limit);
    return veigar_msgpack::object_handle(obj, veigar_msgpack::move(z));
}

template <typename Iterator>
inline veigar_msgpack::object_handle unpack(
    Iterator&& begin, Iterator&& end,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    bool referenced;
    return unpack(std::forward<Iterator>(begin), std::forward<Iterator>(end), referenced, f, user_data, limit);
}

template <typename Iterator>
inline veigar_msgpack::object unpack(
    veigar_msgpack::zone& z,
    Iterator&& begin, Iterator&& end,
    bool& referenced,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    veigar_msgpack::object obj;
    referenced = false;
    detail::unpack_imp(
        std::forward<Iterator>(begin), std::forward<Iterator>(end), z, obj, referenced, f, user_data, limit);
    return obj;
}

template <typename Iterator>
inline veigar_msgpack::object unpack(
    veigar_msgpack::zone& z,
    Iterator&& begin, Iterator&& end,
    unpack_reference_func f, void* user_data,
    unpack_limit const& limit)
{
    bool referenced;
    return unpack(
        z, std::forward<Iterator>(begin), std::forward<Iterator>(end), referenced, f, user_data, limit);
}


/// @cond
}  // MSGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

}  // namespace veigar_msgpack

#else  // BOOST_VERSION >= 106100

#error Boost 1.61.0 or later is required to use x3 parse

#endif // BOOST_VERSION >= 106100

#endif // defined(MSGPACK_USE_X3_PARSE)

#endif // MSGPACK_V2_X3_UNPACK_HPP