#ifndef __VEIGAR_MSGPACK_V2_UNPACK_DECL_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V2_UNPACK_DECL_HPP
//
// MessagePack for C++ deserializing routine
//
// Copyright (C) 2016 KONDO Takatoshi
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V2_UNPACK_DECL_HPP
#define MSGPACK_V2_UNPACK_DECL_HPP

#include "veigar/msgpack/v1/unpack_decl.hpp"

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v2) {
/// @endcond

using v1::unpack_reference_func;

using v1::unpack_error;
using v1::parse_error;
using v1::insufficient_bytes;
using v1::size_overflow;
using v1::array_size_overflow;
using v1::map_size_overflow;
using v1::str_size_overflow;
using v1::bin_size_overflow;
using v1::ext_size_overflow;
using v1::depth_size_overflow;
using v1::unpack_limit;

namespace detail {

using v1::detail::unpack_user;

using v1::detail::unpack_uint8;
using v1::detail::unpack_uint16;
using v1::detail::unpack_uint32;
using v1::detail::unpack_uint64;

using v1::detail::unpack_int8;
using v1::detail::unpack_int16;
using v1::detail::unpack_int32;
using v1::detail::unpack_int64;

using v1::detail::unpack_float;
using v1::detail::unpack_double;

using v1::detail::unpack_nil;

using v1::detail::unpack_true;
using v1::detail::unpack_false;

using v1::detail::unpack_array;
using v1::detail::unpack_array_item;
using v1::detail::unpack_map;
using v1::detail::unpack_map_item;
using v1::detail::unpack_str;
using v1::detail::unpack_bin;
using v1::detail::unpack_ext;

using  v1::detail::unpack_stack;

using v1::detail::init_count;
using v1::detail::decr_count;
using v1::detail::incr_count;

using v1::detail::get_count;

using v1::detail::fix_tag;

using v1::detail::value;

using v1::detail::load;

} // detail


using v1::unpacked;

/// Unpacking class for a stream deserialization.
class unpacker;

template <typename unpack_visitor, typename referenced_buffer_hook>
class basic_unpacker;

/// Unpack veigar_msgpack::object from a buffer.
/**
 * @param data The pointer to the buffer.
 * @param len The length of the buffer.
 * @param off The offset position of the buffer. It is read and overwritten.
 * @param referenced If the unpacked object contains reference of the buffer, then set as true, otherwise false.
 * @param f A judging function that veigar_msgpack::object refer to the buffer.
 * @param user_data This parameter is passed to f.
 * @param limit The size limit information of veigar_msgpack::object.
 *
 * @return object_handle that contains unpacked data.
 *
 */
veigar_msgpack::object_handle unpack(
    const char* data, std::size_t len, std::size_t& off, bool& referenced,
    unpack_reference_func f = MSGPACK_NULLPTR, void* user_data = MSGPACK_NULLPTR, unpack_limit const& limit = unpack_limit());

/// Unpack veigar_msgpack::object from a buffer.
/**
 * @param data The pointer to the buffer.
 * @param len The length of the buffer.
 * @param off The offset position of the buffer. It is read and overwritten.
 * @param f A judging function that veigar_msgpack::object refer to the buffer.
 * @param user_data This parameter is passed to f.
 * @param limit The size limit information of veigar_msgpack::object.
 *
 * @return object_handle that contains unpacked data.
 *
 */
veigar_msgpack::object_handle unpack(
    const char* data, std::size_t len, std::size_t& off,
    unpack_reference_func f = MSGPACK_NULLPTR, void* user_data = MSGPACK_NULLPTR, unpack_limit const& limit = unpack_limit());

/// Unpack veigar_msgpack::object from a buffer.
/**
 * @param data The pointer to the buffer.
 * @param len The length of the buffer.
 * @param referenced If the unpacked object contains reference of the buffer, then set as true, otherwise false.
 * @param f A judging function that veigar_msgpack::object refer to the buffer.
 * @param user_data This parameter is passed to f.
 * @param limit The size limit information of veigar_msgpack::object.
 *
 * @return object_handle that contains unpacked data.
 *
 */
veigar_msgpack::object_handle unpack(
    const char* data, std::size_t len, bool& referenced,
    unpack_reference_func f = MSGPACK_NULLPTR, void* user_data = MSGPACK_NULLPTR, unpack_limit const& limit = unpack_limit());

/// Unpack veigar_msgpack::object from a buffer.
/**
 * @param data The pointer to the buffer.
 * @param len The length of the buffer.
 * @param f A judging function that veigar_msgpack::object refer to the buffer.
 * @param user_data This parameter is passed to f.
 * @param limit The size limit information of veigar_msgpack::object.
 *
 * @return object_handle that contains unpacked data.
 *
 */
veigar_msgpack::object_handle unpack(
    const char* data, std::size_t len,
    unpack_reference_func f = MSGPACK_NULLPTR, void* user_data = MSGPACK_NULLPTR, unpack_limit const& limit = unpack_limit());


/// Unpack veigar_msgpack::object from a buffer.
/**
 * @param result The object_handle that contains unpacked data.
 * @param data The pointer to the buffer.
 * @param len The length of the buffer.
 * @param off The offset position of the buffer. It is read and overwritten.
 * @param referenced If the unpacked object contains reference of the buffer, then set as true, otherwise false.
 * @param f A judging function that veigar_msgpack::object refer to the buffer.
 * @param user_data This parameter is passed to f.
 * @param limit The size limit information of veigar_msgpack::object.
 *
 *
 */
void unpack(
    veigar_msgpack::object_handle& result,
    const char* data, std::size_t len, std::size_t& off, bool& referenced,
    unpack_reference_func f = MSGPACK_NULLPTR, void* user_data = MSGPACK_NULLPTR, unpack_limit const& limit = unpack_limit());

/// Unpack veigar_msgpack::object from a buffer.
/**
 * @param result The object_handle that contains unpacked data.
 * @param data The pointer to the buffer.
 * @param len The length of the buffer.
 * @param off The offset position of the buffer. It is read and overwritten.
 * @param f A judging function that veigar_msgpack::object refer to the buffer.
 * @param user_data This parameter is passed to f.
 * @param limit The size limit information of veigar_msgpack::object.
 *
 *
 */
void unpack(
    veigar_msgpack::object_handle& result,
    const char* data, std::size_t len, std::size_t& off,
    unpack_reference_func f = MSGPACK_NULLPTR, void* user_data = MSGPACK_NULLPTR, unpack_limit const& limit = unpack_limit());

/// Unpack veigar_msgpack::object from a buffer.
/**
 * @param result The object_handle that contains unpacked data.
 * @param data The pointer to the buffer.
 * @param len The length of the buffer.
 * @param referenced If the unpacked object contains reference of the buffer, then set as true, otherwise false.
 * @param f A judging function that veigar_msgpack::object refer to the buffer.
 * @param user_data This parameter is passed to f.
 * @param limit The size limit information of veigar_msgpack::object.
 *
 *
 */
void unpack(
    veigar_msgpack::object_handle& result,
    const char* data, std::size_t len, bool& referenced,
    unpack_reference_func f = MSGPACK_NULLPTR, void* user_data = MSGPACK_NULLPTR, unpack_limit const& limit = unpack_limit());

/// Unpack veigar_msgpack::object from a buffer.
/**
 * @param result The object_handle that contains unpacked data.
 * @param data The pointer to the buffer.
 * @param len The length of the buffer.
 * @param f A judging function that veigar_msgpack::object refer to the buffer.
 * @param user_data This parameter is passed to f.
 * @param limit The size limit information of veigar_msgpack::object.
 *
 *
 */
void unpack(
    veigar_msgpack::object_handle& result,
    const char* data, std::size_t len,
    unpack_reference_func f = MSGPACK_NULLPTR, void* user_data = MSGPACK_NULLPTR, unpack_limit const& limit = unpack_limit());

/// Unpack veigar_msgpack::object from a buffer.
/**
 * @param z The veigar_msgpack::zone that is used as a memory of unpacked msgpack objects.
 * @param data The pointer to the buffer.
 * @param len The length of the buffer.
 * @param off The offset position of the buffer. It is read and overwritten.
 * @param referenced If the unpacked object contains reference of the buffer, then set as true, otherwise false.
 * @param f A judging function that veigar_msgpack::object refer to the buffer.
 * @param user_data This parameter is passed to f.
 * @param limit The size limit information of veigar_msgpack::object.
 *
 * @return veigar_msgpack::object that contains unpacked data.
 *
 */
veigar_msgpack::object unpack(
    veigar_msgpack::zone& z,
    const char* data, std::size_t len, std::size_t& off, bool& referenced,
    unpack_reference_func f = MSGPACK_NULLPTR, void* user_data = MSGPACK_NULLPTR, unpack_limit const& limit = unpack_limit());

/// Unpack veigar_msgpack::object from a buffer.
/**
 * @param z The veigar_msgpack::zone that is used as a memory of unpacked msgpack objects.
 * @param data The pointer to the buffer.
 * @param len The length of the buffer.
 * @param off The offset position of the buffer. It is read and overwritten.
 * @param f A judging function that veigar_msgpack::object refer to the buffer.
 * @param user_data This parameter is passed to f.
 * @param limit The size limit information of veigar_msgpack::object.
 *
 * @return veigar_msgpack::object that contains unpacked data.
 *
 */
veigar_msgpack::object unpack(
    veigar_msgpack::zone& z,
    const char* data, std::size_t len, std::size_t& off,
    unpack_reference_func f = MSGPACK_NULLPTR, void* user_data = MSGPACK_NULLPTR, unpack_limit const& limit = unpack_limit());

/// Unpack veigar_msgpack::object from a buffer.
/**
 * @param z The veigar_msgpack::zone that is used as a memory of unpacked msgpack objects.
 * @param data The pointer to the buffer.
 * @param len The length of the buffer.
 * @param referenced If the unpacked object contains reference of the buffer, then set as true, otherwise false.
 * @param f A judging function that veigar_msgpack::object refer to the buffer.
 * @param user_data This parameter is passed to f.
 * @param limit The size limit information of veigar_msgpack::object.
 *
 * @return veigar_msgpack::object that contains unpacked data.
 *
 */
veigar_msgpack::object unpack(
    veigar_msgpack::zone& z,
    const char* data, std::size_t len, bool& referenced,
    unpack_reference_func f = MSGPACK_NULLPTR, void* user_data = MSGPACK_NULLPTR, unpack_limit const& limit = unpack_limit());

/// Unpack veigar_msgpack::object from a buffer.
/**
 * @param z The veigar_msgpack::zone that is used as a memory of unpacked msgpack objects.
 * @param data The pointer to the buffer.
 * @param len The length of the buffer.
 * @param f A judging function that veigar_msgpack::object refer to the buffer.
 * @param user_data This parameter is passed to f.
 * @param limit The size limit information of veigar_msgpack::object.
 *
 * @return veigar_msgpack::object that contains unpacked data.
 *
 */
veigar_msgpack::object unpack(
    veigar_msgpack::zone& z,
    const char* data, std::size_t len,
    unpack_reference_func f = MSGPACK_NULLPTR, void* user_data = MSGPACK_NULLPTR, unpack_limit const& limit = unpack_limit());

namespace detail {

parse_return
unpack_imp(const char* data, std::size_t len, std::size_t& off,
           veigar_msgpack::zone& result_zone, veigar_msgpack::object& result, bool& referenced,
           unpack_reference_func f, void* user_data,
           unpack_limit const& limit);


} // detail

/// @cond
}  // MSGPACK_API_VERSION_NAMESPACE(v2)
/// @endcond

}  // namespace veigar_msgpack

#endif // MSGPACK_V2_UNPACK_DECL_HPP

#endif // !__VEIGAR_MSGPACK_V2_UNPACK_DECL_HPP