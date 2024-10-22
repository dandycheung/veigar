#ifndef __VEIGAR_MSGPACK_PREPROCESSOR_VARIADIC_TO_LIST_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_PREPROCESSOR_VARIADIC_TO_LIST_HPP
# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Edward Diener 2011.                                    *
#  *     (C) Copyright Paul Mensonides 2011.                                  *
#  *     Distributed under the Boost Software License, Version 1.0. (See      *
#  *     accompanying file LICENSE_1_0.txt or copy at                         *
#  *     http://www.boost.org/LICENSE_1_0.txt)                                *
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef MSGPACK_PREPROCESSOR_VARIADIC_TO_LIST_HPP
# define MSGPACK_PREPROCESSOR_VARIADIC_TO_LIST_HPP
#
# include <veigar/msgpack/preprocessor/config/config.hpp>
# include <veigar/msgpack/preprocessor/tuple/to_list.hpp>
#
# /* MSGPACK_PP_VARIADIC_TO_LIST */
#
# if MSGPACK_PP_VARIADICS
#    define MSGPACK_PP_VARIADIC_TO_LIST(...) MSGPACK_PP_TUPLE_TO_LIST((__VA_ARGS__))
# endif
#
# endif

#endif // !__VEIGAR_MSGPACK_PREPROCESSOR_VARIADIC_TO_LIST_HPP