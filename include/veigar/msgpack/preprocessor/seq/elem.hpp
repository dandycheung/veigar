#ifndef __VEIGAR_MSGPACK_PREPROCESSOR_SEQ_ELEM_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_PREPROCESSOR_SEQ_ELEM_HPP
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
# ifndef MSGPACK_PREPROCESSOR_SEQ_ELEM_HPP
# define MSGPACK_PREPROCESSOR_SEQ_ELEM_HPP
#
# include <veigar/msgpack/preprocessor/cat.hpp>
# include <veigar/msgpack/preprocessor/config/config.hpp>
# include <veigar/msgpack/preprocessor/facilities/empty.hpp>
#
# /* MSGPACK_PP_SEQ_ELEM */
#
# if ~MSGPACK_PP_CONFIG_FLAGS() & MSGPACK_PP_CONFIG_MWCC()
#    define MSGPACK_PP_SEQ_ELEM(i, seq) MSGPACK_PP_SEQ_ELEM_I(i, seq)
# else
#    define MSGPACK_PP_SEQ_ELEM(i, seq) MSGPACK_PP_SEQ_ELEM_I((i, seq))
# endif
#
# if MSGPACK_PP_CONFIG_FLAGS() & MSGPACK_PP_CONFIG_MSVC()
#    define MSGPACK_PP_SEQ_ELEM_I(i, seq) MSGPACK_PP_SEQ_ELEM_II((MSGPACK_PP_SEQ_ELEM_ ## i seq))
#    define MSGPACK_PP_SEQ_ELEM_II(res) MSGPACK_PP_SEQ_ELEM_IV(MSGPACK_PP_SEQ_ELEM_III res)
#    define MSGPACK_PP_SEQ_ELEM_III(x, _) x MSGPACK_PP_EMPTY()
#    define MSGPACK_PP_SEQ_ELEM_IV(x) x
# elif MSGPACK_PP_CONFIG_FLAGS() & MSGPACK_PP_CONFIG_MWCC()
#    define MSGPACK_PP_SEQ_ELEM_I(par) MSGPACK_PP_SEQ_ELEM_II ## par
#    define MSGPACK_PP_SEQ_ELEM_II(i, seq) MSGPACK_PP_SEQ_ELEM_III(MSGPACK_PP_SEQ_ELEM_ ## i ## seq)
#    define MSGPACK_PP_SEQ_ELEM_III(im) MSGPACK_PP_SEQ_ELEM_IV(im)
#    define MSGPACK_PP_SEQ_ELEM_IV(x, _) x
# else
#    if defined(__IBMC__) || defined(__IBMCPP__)
#        define MSGPACK_PP_SEQ_ELEM_I(i, seq) MSGPACK_PP_SEQ_ELEM_II(MSGPACK_PP_CAT(MSGPACK_PP_SEQ_ELEM_ ## i, seq))
#    else
#        define MSGPACK_PP_SEQ_ELEM_I(i, seq) MSGPACK_PP_SEQ_ELEM_II(MSGPACK_PP_SEQ_ELEM_ ## i seq)
#    endif
#    define MSGPACK_PP_SEQ_ELEM_II(im) MSGPACK_PP_SEQ_ELEM_III(im)
#    define MSGPACK_PP_SEQ_ELEM_III(x, _) x
# endif
#
# define MSGPACK_PP_SEQ_ELEM_0(x) x, MSGPACK_PP_NIL
# define MSGPACK_PP_SEQ_ELEM_1(_) MSGPACK_PP_SEQ_ELEM_0
# define MSGPACK_PP_SEQ_ELEM_2(_) MSGPACK_PP_SEQ_ELEM_1
# define MSGPACK_PP_SEQ_ELEM_3(_) MSGPACK_PP_SEQ_ELEM_2
# define MSGPACK_PP_SEQ_ELEM_4(_) MSGPACK_PP_SEQ_ELEM_3
# define MSGPACK_PP_SEQ_ELEM_5(_) MSGPACK_PP_SEQ_ELEM_4
# define MSGPACK_PP_SEQ_ELEM_6(_) MSGPACK_PP_SEQ_ELEM_5
# define MSGPACK_PP_SEQ_ELEM_7(_) MSGPACK_PP_SEQ_ELEM_6
# define MSGPACK_PP_SEQ_ELEM_8(_) MSGPACK_PP_SEQ_ELEM_7
# define MSGPACK_PP_SEQ_ELEM_9(_) MSGPACK_PP_SEQ_ELEM_8
# define MSGPACK_PP_SEQ_ELEM_10(_) MSGPACK_PP_SEQ_ELEM_9
# define MSGPACK_PP_SEQ_ELEM_11(_) MSGPACK_PP_SEQ_ELEM_10
# define MSGPACK_PP_SEQ_ELEM_12(_) MSGPACK_PP_SEQ_ELEM_11
# define MSGPACK_PP_SEQ_ELEM_13(_) MSGPACK_PP_SEQ_ELEM_12
# define MSGPACK_PP_SEQ_ELEM_14(_) MSGPACK_PP_SEQ_ELEM_13
# define MSGPACK_PP_SEQ_ELEM_15(_) MSGPACK_PP_SEQ_ELEM_14
# define MSGPACK_PP_SEQ_ELEM_16(_) MSGPACK_PP_SEQ_ELEM_15
# define MSGPACK_PP_SEQ_ELEM_17(_) MSGPACK_PP_SEQ_ELEM_16
# define MSGPACK_PP_SEQ_ELEM_18(_) MSGPACK_PP_SEQ_ELEM_17
# define MSGPACK_PP_SEQ_ELEM_19(_) MSGPACK_PP_SEQ_ELEM_18
# define MSGPACK_PP_SEQ_ELEM_20(_) MSGPACK_PP_SEQ_ELEM_19
# define MSGPACK_PP_SEQ_ELEM_21(_) MSGPACK_PP_SEQ_ELEM_20
# define MSGPACK_PP_SEQ_ELEM_22(_) MSGPACK_PP_SEQ_ELEM_21
# define MSGPACK_PP_SEQ_ELEM_23(_) MSGPACK_PP_SEQ_ELEM_22
# define MSGPACK_PP_SEQ_ELEM_24(_) MSGPACK_PP_SEQ_ELEM_23
# define MSGPACK_PP_SEQ_ELEM_25(_) MSGPACK_PP_SEQ_ELEM_24
# define MSGPACK_PP_SEQ_ELEM_26(_) MSGPACK_PP_SEQ_ELEM_25
# define MSGPACK_PP_SEQ_ELEM_27(_) MSGPACK_PP_SEQ_ELEM_26
# define MSGPACK_PP_SEQ_ELEM_28(_) MSGPACK_PP_SEQ_ELEM_27
# define MSGPACK_PP_SEQ_ELEM_29(_) MSGPACK_PP_SEQ_ELEM_28
# define MSGPACK_PP_SEQ_ELEM_30(_) MSGPACK_PP_SEQ_ELEM_29
# define MSGPACK_PP_SEQ_ELEM_31(_) MSGPACK_PP_SEQ_ELEM_30
# define MSGPACK_PP_SEQ_ELEM_32(_) MSGPACK_PP_SEQ_ELEM_31
# define MSGPACK_PP_SEQ_ELEM_33(_) MSGPACK_PP_SEQ_ELEM_32
# define MSGPACK_PP_SEQ_ELEM_34(_) MSGPACK_PP_SEQ_ELEM_33
# define MSGPACK_PP_SEQ_ELEM_35(_) MSGPACK_PP_SEQ_ELEM_34
# define MSGPACK_PP_SEQ_ELEM_36(_) MSGPACK_PP_SEQ_ELEM_35
# define MSGPACK_PP_SEQ_ELEM_37(_) MSGPACK_PP_SEQ_ELEM_36
# define MSGPACK_PP_SEQ_ELEM_38(_) MSGPACK_PP_SEQ_ELEM_37
# define MSGPACK_PP_SEQ_ELEM_39(_) MSGPACK_PP_SEQ_ELEM_38
# define MSGPACK_PP_SEQ_ELEM_40(_) MSGPACK_PP_SEQ_ELEM_39
# define MSGPACK_PP_SEQ_ELEM_41(_) MSGPACK_PP_SEQ_ELEM_40
# define MSGPACK_PP_SEQ_ELEM_42(_) MSGPACK_PP_SEQ_ELEM_41
# define MSGPACK_PP_SEQ_ELEM_43(_) MSGPACK_PP_SEQ_ELEM_42
# define MSGPACK_PP_SEQ_ELEM_44(_) MSGPACK_PP_SEQ_ELEM_43
# define MSGPACK_PP_SEQ_ELEM_45(_) MSGPACK_PP_SEQ_ELEM_44
# define MSGPACK_PP_SEQ_ELEM_46(_) MSGPACK_PP_SEQ_ELEM_45
# define MSGPACK_PP_SEQ_ELEM_47(_) MSGPACK_PP_SEQ_ELEM_46
# define MSGPACK_PP_SEQ_ELEM_48(_) MSGPACK_PP_SEQ_ELEM_47
# define MSGPACK_PP_SEQ_ELEM_49(_) MSGPACK_PP_SEQ_ELEM_48
# define MSGPACK_PP_SEQ_ELEM_50(_) MSGPACK_PP_SEQ_ELEM_49
# define MSGPACK_PP_SEQ_ELEM_51(_) MSGPACK_PP_SEQ_ELEM_50
# define MSGPACK_PP_SEQ_ELEM_52(_) MSGPACK_PP_SEQ_ELEM_51
# define MSGPACK_PP_SEQ_ELEM_53(_) MSGPACK_PP_SEQ_ELEM_52
# define MSGPACK_PP_SEQ_ELEM_54(_) MSGPACK_PP_SEQ_ELEM_53
# define MSGPACK_PP_SEQ_ELEM_55(_) MSGPACK_PP_SEQ_ELEM_54
# define MSGPACK_PP_SEQ_ELEM_56(_) MSGPACK_PP_SEQ_ELEM_55
# define MSGPACK_PP_SEQ_ELEM_57(_) MSGPACK_PP_SEQ_ELEM_56
# define MSGPACK_PP_SEQ_ELEM_58(_) MSGPACK_PP_SEQ_ELEM_57
# define MSGPACK_PP_SEQ_ELEM_59(_) MSGPACK_PP_SEQ_ELEM_58
# define MSGPACK_PP_SEQ_ELEM_60(_) MSGPACK_PP_SEQ_ELEM_59
# define MSGPACK_PP_SEQ_ELEM_61(_) MSGPACK_PP_SEQ_ELEM_60
# define MSGPACK_PP_SEQ_ELEM_62(_) MSGPACK_PP_SEQ_ELEM_61
# define MSGPACK_PP_SEQ_ELEM_63(_) MSGPACK_PP_SEQ_ELEM_62
# define MSGPACK_PP_SEQ_ELEM_64(_) MSGPACK_PP_SEQ_ELEM_63
# define MSGPACK_PP_SEQ_ELEM_65(_) MSGPACK_PP_SEQ_ELEM_64
# define MSGPACK_PP_SEQ_ELEM_66(_) MSGPACK_PP_SEQ_ELEM_65
# define MSGPACK_PP_SEQ_ELEM_67(_) MSGPACK_PP_SEQ_ELEM_66
# define MSGPACK_PP_SEQ_ELEM_68(_) MSGPACK_PP_SEQ_ELEM_67
# define MSGPACK_PP_SEQ_ELEM_69(_) MSGPACK_PP_SEQ_ELEM_68
# define MSGPACK_PP_SEQ_ELEM_70(_) MSGPACK_PP_SEQ_ELEM_69
# define MSGPACK_PP_SEQ_ELEM_71(_) MSGPACK_PP_SEQ_ELEM_70
# define MSGPACK_PP_SEQ_ELEM_72(_) MSGPACK_PP_SEQ_ELEM_71
# define MSGPACK_PP_SEQ_ELEM_73(_) MSGPACK_PP_SEQ_ELEM_72
# define MSGPACK_PP_SEQ_ELEM_74(_) MSGPACK_PP_SEQ_ELEM_73
# define MSGPACK_PP_SEQ_ELEM_75(_) MSGPACK_PP_SEQ_ELEM_74
# define MSGPACK_PP_SEQ_ELEM_76(_) MSGPACK_PP_SEQ_ELEM_75
# define MSGPACK_PP_SEQ_ELEM_77(_) MSGPACK_PP_SEQ_ELEM_76
# define MSGPACK_PP_SEQ_ELEM_78(_) MSGPACK_PP_SEQ_ELEM_77
# define MSGPACK_PP_SEQ_ELEM_79(_) MSGPACK_PP_SEQ_ELEM_78
# define MSGPACK_PP_SEQ_ELEM_80(_) MSGPACK_PP_SEQ_ELEM_79
# define MSGPACK_PP_SEQ_ELEM_81(_) MSGPACK_PP_SEQ_ELEM_80
# define MSGPACK_PP_SEQ_ELEM_82(_) MSGPACK_PP_SEQ_ELEM_81
# define MSGPACK_PP_SEQ_ELEM_83(_) MSGPACK_PP_SEQ_ELEM_82
# define MSGPACK_PP_SEQ_ELEM_84(_) MSGPACK_PP_SEQ_ELEM_83
# define MSGPACK_PP_SEQ_ELEM_85(_) MSGPACK_PP_SEQ_ELEM_84
# define MSGPACK_PP_SEQ_ELEM_86(_) MSGPACK_PP_SEQ_ELEM_85
# define MSGPACK_PP_SEQ_ELEM_87(_) MSGPACK_PP_SEQ_ELEM_86
# define MSGPACK_PP_SEQ_ELEM_88(_) MSGPACK_PP_SEQ_ELEM_87
# define MSGPACK_PP_SEQ_ELEM_89(_) MSGPACK_PP_SEQ_ELEM_88
# define MSGPACK_PP_SEQ_ELEM_90(_) MSGPACK_PP_SEQ_ELEM_89
# define MSGPACK_PP_SEQ_ELEM_91(_) MSGPACK_PP_SEQ_ELEM_90
# define MSGPACK_PP_SEQ_ELEM_92(_) MSGPACK_PP_SEQ_ELEM_91
# define MSGPACK_PP_SEQ_ELEM_93(_) MSGPACK_PP_SEQ_ELEM_92
# define MSGPACK_PP_SEQ_ELEM_94(_) MSGPACK_PP_SEQ_ELEM_93
# define MSGPACK_PP_SEQ_ELEM_95(_) MSGPACK_PP_SEQ_ELEM_94
# define MSGPACK_PP_SEQ_ELEM_96(_) MSGPACK_PP_SEQ_ELEM_95
# define MSGPACK_PP_SEQ_ELEM_97(_) MSGPACK_PP_SEQ_ELEM_96
# define MSGPACK_PP_SEQ_ELEM_98(_) MSGPACK_PP_SEQ_ELEM_97
# define MSGPACK_PP_SEQ_ELEM_99(_) MSGPACK_PP_SEQ_ELEM_98
# define MSGPACK_PP_SEQ_ELEM_100(_) MSGPACK_PP_SEQ_ELEM_99
# define MSGPACK_PP_SEQ_ELEM_101(_) MSGPACK_PP_SEQ_ELEM_100
# define MSGPACK_PP_SEQ_ELEM_102(_) MSGPACK_PP_SEQ_ELEM_101
# define MSGPACK_PP_SEQ_ELEM_103(_) MSGPACK_PP_SEQ_ELEM_102
# define MSGPACK_PP_SEQ_ELEM_104(_) MSGPACK_PP_SEQ_ELEM_103
# define MSGPACK_PP_SEQ_ELEM_105(_) MSGPACK_PP_SEQ_ELEM_104
# define MSGPACK_PP_SEQ_ELEM_106(_) MSGPACK_PP_SEQ_ELEM_105
# define MSGPACK_PP_SEQ_ELEM_107(_) MSGPACK_PP_SEQ_ELEM_106
# define MSGPACK_PP_SEQ_ELEM_108(_) MSGPACK_PP_SEQ_ELEM_107
# define MSGPACK_PP_SEQ_ELEM_109(_) MSGPACK_PP_SEQ_ELEM_108
# define MSGPACK_PP_SEQ_ELEM_110(_) MSGPACK_PP_SEQ_ELEM_109
# define MSGPACK_PP_SEQ_ELEM_111(_) MSGPACK_PP_SEQ_ELEM_110
# define MSGPACK_PP_SEQ_ELEM_112(_) MSGPACK_PP_SEQ_ELEM_111
# define MSGPACK_PP_SEQ_ELEM_113(_) MSGPACK_PP_SEQ_ELEM_112
# define MSGPACK_PP_SEQ_ELEM_114(_) MSGPACK_PP_SEQ_ELEM_113
# define MSGPACK_PP_SEQ_ELEM_115(_) MSGPACK_PP_SEQ_ELEM_114
# define MSGPACK_PP_SEQ_ELEM_116(_) MSGPACK_PP_SEQ_ELEM_115
# define MSGPACK_PP_SEQ_ELEM_117(_) MSGPACK_PP_SEQ_ELEM_116
# define MSGPACK_PP_SEQ_ELEM_118(_) MSGPACK_PP_SEQ_ELEM_117
# define MSGPACK_PP_SEQ_ELEM_119(_) MSGPACK_PP_SEQ_ELEM_118
# define MSGPACK_PP_SEQ_ELEM_120(_) MSGPACK_PP_SEQ_ELEM_119
# define MSGPACK_PP_SEQ_ELEM_121(_) MSGPACK_PP_SEQ_ELEM_120
# define MSGPACK_PP_SEQ_ELEM_122(_) MSGPACK_PP_SEQ_ELEM_121
# define MSGPACK_PP_SEQ_ELEM_123(_) MSGPACK_PP_SEQ_ELEM_122
# define MSGPACK_PP_SEQ_ELEM_124(_) MSGPACK_PP_SEQ_ELEM_123
# define MSGPACK_PP_SEQ_ELEM_125(_) MSGPACK_PP_SEQ_ELEM_124
# define MSGPACK_PP_SEQ_ELEM_126(_) MSGPACK_PP_SEQ_ELEM_125
# define MSGPACK_PP_SEQ_ELEM_127(_) MSGPACK_PP_SEQ_ELEM_126
# define MSGPACK_PP_SEQ_ELEM_128(_) MSGPACK_PP_SEQ_ELEM_127
# define MSGPACK_PP_SEQ_ELEM_129(_) MSGPACK_PP_SEQ_ELEM_128
# define MSGPACK_PP_SEQ_ELEM_130(_) MSGPACK_PP_SEQ_ELEM_129
# define MSGPACK_PP_SEQ_ELEM_131(_) MSGPACK_PP_SEQ_ELEM_130
# define MSGPACK_PP_SEQ_ELEM_132(_) MSGPACK_PP_SEQ_ELEM_131
# define MSGPACK_PP_SEQ_ELEM_133(_) MSGPACK_PP_SEQ_ELEM_132
# define MSGPACK_PP_SEQ_ELEM_134(_) MSGPACK_PP_SEQ_ELEM_133
# define MSGPACK_PP_SEQ_ELEM_135(_) MSGPACK_PP_SEQ_ELEM_134
# define MSGPACK_PP_SEQ_ELEM_136(_) MSGPACK_PP_SEQ_ELEM_135
# define MSGPACK_PP_SEQ_ELEM_137(_) MSGPACK_PP_SEQ_ELEM_136
# define MSGPACK_PP_SEQ_ELEM_138(_) MSGPACK_PP_SEQ_ELEM_137
# define MSGPACK_PP_SEQ_ELEM_139(_) MSGPACK_PP_SEQ_ELEM_138
# define MSGPACK_PP_SEQ_ELEM_140(_) MSGPACK_PP_SEQ_ELEM_139
# define MSGPACK_PP_SEQ_ELEM_141(_) MSGPACK_PP_SEQ_ELEM_140
# define MSGPACK_PP_SEQ_ELEM_142(_) MSGPACK_PP_SEQ_ELEM_141
# define MSGPACK_PP_SEQ_ELEM_143(_) MSGPACK_PP_SEQ_ELEM_142
# define MSGPACK_PP_SEQ_ELEM_144(_) MSGPACK_PP_SEQ_ELEM_143
# define MSGPACK_PP_SEQ_ELEM_145(_) MSGPACK_PP_SEQ_ELEM_144
# define MSGPACK_PP_SEQ_ELEM_146(_) MSGPACK_PP_SEQ_ELEM_145
# define MSGPACK_PP_SEQ_ELEM_147(_) MSGPACK_PP_SEQ_ELEM_146
# define MSGPACK_PP_SEQ_ELEM_148(_) MSGPACK_PP_SEQ_ELEM_147
# define MSGPACK_PP_SEQ_ELEM_149(_) MSGPACK_PP_SEQ_ELEM_148
# define MSGPACK_PP_SEQ_ELEM_150(_) MSGPACK_PP_SEQ_ELEM_149
# define MSGPACK_PP_SEQ_ELEM_151(_) MSGPACK_PP_SEQ_ELEM_150
# define MSGPACK_PP_SEQ_ELEM_152(_) MSGPACK_PP_SEQ_ELEM_151
# define MSGPACK_PP_SEQ_ELEM_153(_) MSGPACK_PP_SEQ_ELEM_152
# define MSGPACK_PP_SEQ_ELEM_154(_) MSGPACK_PP_SEQ_ELEM_153
# define MSGPACK_PP_SEQ_ELEM_155(_) MSGPACK_PP_SEQ_ELEM_154
# define MSGPACK_PP_SEQ_ELEM_156(_) MSGPACK_PP_SEQ_ELEM_155
# define MSGPACK_PP_SEQ_ELEM_157(_) MSGPACK_PP_SEQ_ELEM_156
# define MSGPACK_PP_SEQ_ELEM_158(_) MSGPACK_PP_SEQ_ELEM_157
# define MSGPACK_PP_SEQ_ELEM_159(_) MSGPACK_PP_SEQ_ELEM_158
# define MSGPACK_PP_SEQ_ELEM_160(_) MSGPACK_PP_SEQ_ELEM_159
# define MSGPACK_PP_SEQ_ELEM_161(_) MSGPACK_PP_SEQ_ELEM_160
# define MSGPACK_PP_SEQ_ELEM_162(_) MSGPACK_PP_SEQ_ELEM_161
# define MSGPACK_PP_SEQ_ELEM_163(_) MSGPACK_PP_SEQ_ELEM_162
# define MSGPACK_PP_SEQ_ELEM_164(_) MSGPACK_PP_SEQ_ELEM_163
# define MSGPACK_PP_SEQ_ELEM_165(_) MSGPACK_PP_SEQ_ELEM_164
# define MSGPACK_PP_SEQ_ELEM_166(_) MSGPACK_PP_SEQ_ELEM_165
# define MSGPACK_PP_SEQ_ELEM_167(_) MSGPACK_PP_SEQ_ELEM_166
# define MSGPACK_PP_SEQ_ELEM_168(_) MSGPACK_PP_SEQ_ELEM_167
# define MSGPACK_PP_SEQ_ELEM_169(_) MSGPACK_PP_SEQ_ELEM_168
# define MSGPACK_PP_SEQ_ELEM_170(_) MSGPACK_PP_SEQ_ELEM_169
# define MSGPACK_PP_SEQ_ELEM_171(_) MSGPACK_PP_SEQ_ELEM_170
# define MSGPACK_PP_SEQ_ELEM_172(_) MSGPACK_PP_SEQ_ELEM_171
# define MSGPACK_PP_SEQ_ELEM_173(_) MSGPACK_PP_SEQ_ELEM_172
# define MSGPACK_PP_SEQ_ELEM_174(_) MSGPACK_PP_SEQ_ELEM_173
# define MSGPACK_PP_SEQ_ELEM_175(_) MSGPACK_PP_SEQ_ELEM_174
# define MSGPACK_PP_SEQ_ELEM_176(_) MSGPACK_PP_SEQ_ELEM_175
# define MSGPACK_PP_SEQ_ELEM_177(_) MSGPACK_PP_SEQ_ELEM_176
# define MSGPACK_PP_SEQ_ELEM_178(_) MSGPACK_PP_SEQ_ELEM_177
# define MSGPACK_PP_SEQ_ELEM_179(_) MSGPACK_PP_SEQ_ELEM_178
# define MSGPACK_PP_SEQ_ELEM_180(_) MSGPACK_PP_SEQ_ELEM_179
# define MSGPACK_PP_SEQ_ELEM_181(_) MSGPACK_PP_SEQ_ELEM_180
# define MSGPACK_PP_SEQ_ELEM_182(_) MSGPACK_PP_SEQ_ELEM_181
# define MSGPACK_PP_SEQ_ELEM_183(_) MSGPACK_PP_SEQ_ELEM_182
# define MSGPACK_PP_SEQ_ELEM_184(_) MSGPACK_PP_SEQ_ELEM_183
# define MSGPACK_PP_SEQ_ELEM_185(_) MSGPACK_PP_SEQ_ELEM_184
# define MSGPACK_PP_SEQ_ELEM_186(_) MSGPACK_PP_SEQ_ELEM_185
# define MSGPACK_PP_SEQ_ELEM_187(_) MSGPACK_PP_SEQ_ELEM_186
# define MSGPACK_PP_SEQ_ELEM_188(_) MSGPACK_PP_SEQ_ELEM_187
# define MSGPACK_PP_SEQ_ELEM_189(_) MSGPACK_PP_SEQ_ELEM_188
# define MSGPACK_PP_SEQ_ELEM_190(_) MSGPACK_PP_SEQ_ELEM_189
# define MSGPACK_PP_SEQ_ELEM_191(_) MSGPACK_PP_SEQ_ELEM_190
# define MSGPACK_PP_SEQ_ELEM_192(_) MSGPACK_PP_SEQ_ELEM_191
# define MSGPACK_PP_SEQ_ELEM_193(_) MSGPACK_PP_SEQ_ELEM_192
# define MSGPACK_PP_SEQ_ELEM_194(_) MSGPACK_PP_SEQ_ELEM_193
# define MSGPACK_PP_SEQ_ELEM_195(_) MSGPACK_PP_SEQ_ELEM_194
# define MSGPACK_PP_SEQ_ELEM_196(_) MSGPACK_PP_SEQ_ELEM_195
# define MSGPACK_PP_SEQ_ELEM_197(_) MSGPACK_PP_SEQ_ELEM_196
# define MSGPACK_PP_SEQ_ELEM_198(_) MSGPACK_PP_SEQ_ELEM_197
# define MSGPACK_PP_SEQ_ELEM_199(_) MSGPACK_PP_SEQ_ELEM_198
# define MSGPACK_PP_SEQ_ELEM_200(_) MSGPACK_PP_SEQ_ELEM_199
# define MSGPACK_PP_SEQ_ELEM_201(_) MSGPACK_PP_SEQ_ELEM_200
# define MSGPACK_PP_SEQ_ELEM_202(_) MSGPACK_PP_SEQ_ELEM_201
# define MSGPACK_PP_SEQ_ELEM_203(_) MSGPACK_PP_SEQ_ELEM_202
# define MSGPACK_PP_SEQ_ELEM_204(_) MSGPACK_PP_SEQ_ELEM_203
# define MSGPACK_PP_SEQ_ELEM_205(_) MSGPACK_PP_SEQ_ELEM_204
# define MSGPACK_PP_SEQ_ELEM_206(_) MSGPACK_PP_SEQ_ELEM_205
# define MSGPACK_PP_SEQ_ELEM_207(_) MSGPACK_PP_SEQ_ELEM_206
# define MSGPACK_PP_SEQ_ELEM_208(_) MSGPACK_PP_SEQ_ELEM_207
# define MSGPACK_PP_SEQ_ELEM_209(_) MSGPACK_PP_SEQ_ELEM_208
# define MSGPACK_PP_SEQ_ELEM_210(_) MSGPACK_PP_SEQ_ELEM_209
# define MSGPACK_PP_SEQ_ELEM_211(_) MSGPACK_PP_SEQ_ELEM_210
# define MSGPACK_PP_SEQ_ELEM_212(_) MSGPACK_PP_SEQ_ELEM_211
# define MSGPACK_PP_SEQ_ELEM_213(_) MSGPACK_PP_SEQ_ELEM_212
# define MSGPACK_PP_SEQ_ELEM_214(_) MSGPACK_PP_SEQ_ELEM_213
# define MSGPACK_PP_SEQ_ELEM_215(_) MSGPACK_PP_SEQ_ELEM_214
# define MSGPACK_PP_SEQ_ELEM_216(_) MSGPACK_PP_SEQ_ELEM_215
# define MSGPACK_PP_SEQ_ELEM_217(_) MSGPACK_PP_SEQ_ELEM_216
# define MSGPACK_PP_SEQ_ELEM_218(_) MSGPACK_PP_SEQ_ELEM_217
# define MSGPACK_PP_SEQ_ELEM_219(_) MSGPACK_PP_SEQ_ELEM_218
# define MSGPACK_PP_SEQ_ELEM_220(_) MSGPACK_PP_SEQ_ELEM_219
# define MSGPACK_PP_SEQ_ELEM_221(_) MSGPACK_PP_SEQ_ELEM_220
# define MSGPACK_PP_SEQ_ELEM_222(_) MSGPACK_PP_SEQ_ELEM_221
# define MSGPACK_PP_SEQ_ELEM_223(_) MSGPACK_PP_SEQ_ELEM_222
# define MSGPACK_PP_SEQ_ELEM_224(_) MSGPACK_PP_SEQ_ELEM_223
# define MSGPACK_PP_SEQ_ELEM_225(_) MSGPACK_PP_SEQ_ELEM_224
# define MSGPACK_PP_SEQ_ELEM_226(_) MSGPACK_PP_SEQ_ELEM_225
# define MSGPACK_PP_SEQ_ELEM_227(_) MSGPACK_PP_SEQ_ELEM_226
# define MSGPACK_PP_SEQ_ELEM_228(_) MSGPACK_PP_SEQ_ELEM_227
# define MSGPACK_PP_SEQ_ELEM_229(_) MSGPACK_PP_SEQ_ELEM_228
# define MSGPACK_PP_SEQ_ELEM_230(_) MSGPACK_PP_SEQ_ELEM_229
# define MSGPACK_PP_SEQ_ELEM_231(_) MSGPACK_PP_SEQ_ELEM_230
# define MSGPACK_PP_SEQ_ELEM_232(_) MSGPACK_PP_SEQ_ELEM_231
# define MSGPACK_PP_SEQ_ELEM_233(_) MSGPACK_PP_SEQ_ELEM_232
# define MSGPACK_PP_SEQ_ELEM_234(_) MSGPACK_PP_SEQ_ELEM_233
# define MSGPACK_PP_SEQ_ELEM_235(_) MSGPACK_PP_SEQ_ELEM_234
# define MSGPACK_PP_SEQ_ELEM_236(_) MSGPACK_PP_SEQ_ELEM_235
# define MSGPACK_PP_SEQ_ELEM_237(_) MSGPACK_PP_SEQ_ELEM_236
# define MSGPACK_PP_SEQ_ELEM_238(_) MSGPACK_PP_SEQ_ELEM_237
# define MSGPACK_PP_SEQ_ELEM_239(_) MSGPACK_PP_SEQ_ELEM_238
# define MSGPACK_PP_SEQ_ELEM_240(_) MSGPACK_PP_SEQ_ELEM_239
# define MSGPACK_PP_SEQ_ELEM_241(_) MSGPACK_PP_SEQ_ELEM_240
# define MSGPACK_PP_SEQ_ELEM_242(_) MSGPACK_PP_SEQ_ELEM_241
# define MSGPACK_PP_SEQ_ELEM_243(_) MSGPACK_PP_SEQ_ELEM_242
# define MSGPACK_PP_SEQ_ELEM_244(_) MSGPACK_PP_SEQ_ELEM_243
# define MSGPACK_PP_SEQ_ELEM_245(_) MSGPACK_PP_SEQ_ELEM_244
# define MSGPACK_PP_SEQ_ELEM_246(_) MSGPACK_PP_SEQ_ELEM_245
# define MSGPACK_PP_SEQ_ELEM_247(_) MSGPACK_PP_SEQ_ELEM_246
# define MSGPACK_PP_SEQ_ELEM_248(_) MSGPACK_PP_SEQ_ELEM_247
# define MSGPACK_PP_SEQ_ELEM_249(_) MSGPACK_PP_SEQ_ELEM_248
# define MSGPACK_PP_SEQ_ELEM_250(_) MSGPACK_PP_SEQ_ELEM_249
# define MSGPACK_PP_SEQ_ELEM_251(_) MSGPACK_PP_SEQ_ELEM_250
# define MSGPACK_PP_SEQ_ELEM_252(_) MSGPACK_PP_SEQ_ELEM_251
# define MSGPACK_PP_SEQ_ELEM_253(_) MSGPACK_PP_SEQ_ELEM_252
# define MSGPACK_PP_SEQ_ELEM_254(_) MSGPACK_PP_SEQ_ELEM_253
# define MSGPACK_PP_SEQ_ELEM_255(_) MSGPACK_PP_SEQ_ELEM_254
#
# endif

#endif // !__VEIGAR_MSGPACK_PREPROCESSOR_SEQ_ELEM_HPP