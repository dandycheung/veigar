#ifndef __VEIGAR_MSGPACK_PREPROCESSOR_TUPLE_INSERT_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_PREPROCESSOR_TUPLE_INSERT_HPP
# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2013.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef MSGPACK_PREPROCESSOR_TUPLE_INSERT_HPP
# define MSGPACK_PREPROCESSOR_TUPLE_INSERT_HPP
#
# include <veigar/msgpack/preprocessor/config/config.hpp>
#
# if MSGPACK_PP_VARIADICS
#
# include <veigar/msgpack/preprocessor/array/insert.hpp>
# include <veigar/msgpack/preprocessor/array/to_tuple.hpp>
# include <veigar/msgpack/preprocessor/tuple/to_array.hpp>
#
# /* MSGPACK_PP_TUPLE_INSERT */
#
# define MSGPACK_PP_TUPLE_INSERT(tuple, i, elem) \
	MSGPACK_PP_ARRAY_TO_TUPLE(MSGPACK_PP_ARRAY_INSERT(MSGPACK_PP_TUPLE_TO_ARRAY(tuple), i, elem)) \
/**/
#
# /* MSGPACK_PP_TUPLE_INSERT_D */
#
# define MSGPACK_PP_TUPLE_INSERT_D(d, tuple, i, elem) \
	MSGPACK_PP_ARRAY_TO_TUPLE(MSGPACK_PP_ARRAY_INSERT_D(d, MSGPACK_PP_TUPLE_TO_ARRAY(tuple), i, elem)) \
/**/
#
# endif // MSGPACK_PP_VARIADICS
#
# endif // MSGPACK_PREPROCESSOR_TUPLE_INSERT_HPP

#endif // !__VEIGAR_MSGPACK_PREPROCESSOR_TUPLE_INSERT_HPP