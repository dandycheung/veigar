#ifndef __VEIGAR_MSGPACK_PREPROCESSOR_SEQ_FIRST_N_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_PREPROCESSOR_SEQ_FIRST_N_HPP
# /* **************************************************************************
#  *                                                                          *
#  *     (C) Copyright Paul Mensonides 2002.
#  *     Distributed under the Boost Software License, Version 1.0. (See
#  *     accompanying file LICENSE_1_0.txt or copy at
#  *     http://www.boost.org/LICENSE_1_0.txt)
#  *                                                                          *
#  ************************************************************************** */
#
# /* See http://www.boost.org for most recent version. */
#
# ifndef MSGPACK_PREPROCESSOR_SEQ_FIRST_N_HPP
# define MSGPACK_PREPROCESSOR_SEQ_FIRST_N_HPP
#
# include <veigar/msgpack/preprocessor/config/config.hpp>
# include <veigar/msgpack/preprocessor/control/if.hpp>
# include <veigar/msgpack/preprocessor/seq/detail/split.hpp>
# include <veigar/msgpack/preprocessor/tuple/eat.hpp>
# include <veigar/msgpack/preprocessor/tuple/elem.hpp>
#
# /* MSGPACK_PP_SEQ_FIRST_N */
#
# if ~MSGPACK_PP_CONFIG_FLAGS() & MSGPACK_PP_CONFIG_EDG()
#    define MSGPACK_PP_SEQ_FIRST_N(n, seq) MSGPACK_PP_IF(n, MSGPACK_PP_TUPLE_ELEM, MSGPACK_PP_TUPLE_EAT_3)(2, 0, MSGPACK_PP_SEQ_SPLIT(n, seq (nil)))
# else
#    define MSGPACK_PP_SEQ_FIRST_N(n, seq) MSGPACK_PP_SEQ_FIRST_N_I(n, seq)
#    define MSGPACK_PP_SEQ_FIRST_N_I(n, seq) MSGPACK_PP_IF(n, MSGPACK_PP_TUPLE_ELEM, MSGPACK_PP_TUPLE_EAT_3)(2, 0, MSGPACK_PP_SEQ_SPLIT(n, seq (nil)))
# endif
#
# endif

#endif // !__VEIGAR_MSGPACK_PREPROCESSOR_SEQ_FIRST_N_HPP