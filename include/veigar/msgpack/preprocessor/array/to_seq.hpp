#ifndef __VEIGAR_MSGPACK_PREPROCESSOR_ARRAY_TO_SEQ_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_PREPROCESSOR_ARRAY_TO_SEQ_HPP
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
# ifndef MSGPACK_PREPROCESSOR_ARRAY_TO_SEQ_HPP
# define MSGPACK_PREPROCESSOR_ARRAY_TO_SEQ_HPP
#
# include <veigar/msgpack/preprocessor/cat.hpp>
# include <veigar/msgpack/preprocessor/config/config.hpp>
# include <veigar/msgpack/preprocessor/array/size.hpp>
# include <veigar/msgpack/preprocessor/control/if.hpp>
# include <veigar/msgpack/preprocessor/tuple/to_seq.hpp>
#
# /* MSGPACK_PP_ARRAY_TO_SEQ */
#
#    define MSGPACK_PP_ARRAY_TO_SEQ(array) \
		MSGPACK_PP_IF \
			( \
			MSGPACK_PP_ARRAY_SIZE(array), \
			MSGPACK_PP_ARRAY_TO_SEQ_DO, \
			MSGPACK_PP_ARRAY_TO_SEQ_EMPTY \
			) \
		(array) \
/**/
#    define MSGPACK_PP_ARRAY_TO_SEQ_EMPTY(array)
#
# if MSGPACK_PP_CONFIG_FLAGS() & MSGPACK_PP_CONFIG_MSVC()
#    define MSGPACK_PP_ARRAY_TO_SEQ_DO(array) MSGPACK_PP_ARRAY_TO_SEQ_I(MSGPACK_PP_TUPLE_TO_SEQ, array)
#    define MSGPACK_PP_ARRAY_TO_SEQ_I(m, args) MSGPACK_PP_ARRAY_TO_SEQ_II(m, args)
#    define MSGPACK_PP_ARRAY_TO_SEQ_II(m, args) MSGPACK_PP_CAT(m ## args,)
# elif MSGPACK_PP_CONFIG_FLAGS() & MSGPACK_PP_CONFIG_MWCC()
#    define MSGPACK_PP_ARRAY_TO_SEQ_DO(array) MSGPACK_PP_ARRAY_TO_SEQ_I(array)
#    define MSGPACK_PP_ARRAY_TO_SEQ_I(array) MSGPACK_PP_TUPLE_TO_SEQ ## array
# else
#    define MSGPACK_PP_ARRAY_TO_SEQ_DO(array) MSGPACK_PP_TUPLE_TO_SEQ array
# endif
#
# endif

#endif // !__VEIGAR_MSGPACK_PREPROCESSOR_ARRAY_TO_SEQ_HPP