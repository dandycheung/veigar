#ifndef __VEIGAR_MSGPACK_PREPROCESSOR_DETAIL_DMC_AUTO_REC_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_PREPROCESSOR_DETAIL_DMC_AUTO_REC_HPP
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
# ifndef MSGPACK_PREPROCESSOR_DETAIL_AUTO_REC_HPP
# define MSGPACK_PREPROCESSOR_DETAIL_AUTO_REC_HPP
#
# include <veigar/msgpack/preprocessor/control/iif.hpp>
#
# /* MSGPACK_PP_AUTO_REC */
#
# define MSGPACK_PP_AUTO_REC(pred, n) MSGPACK_PP_NODE_ENTRY_ ## n(pred)
#
# define MSGPACK_PP_NODE_ENTRY_256(p) MSGPACK_PP_NODE_128(p)(p)(p)(p)(p)(p)(p)(p)
# define MSGPACK_PP_NODE_ENTRY_128(p) MSGPACK_PP_NODE_64(p)(p)(p)(p)(p)(p)(p)
# define MSGPACK_PP_NODE_ENTRY_64(p) MSGPACK_PP_NODE_32(p)(p)(p)(p)(p)(p)
# define MSGPACK_PP_NODE_ENTRY_32(p) MSGPACK_PP_NODE_16(p)(p)(p)(p)(p)
# define MSGPACK_PP_NODE_ENTRY_16(p) MSGPACK_PP_NODE_8(p)(p)(p)(p)
# define MSGPACK_PP_NODE_ENTRY_8(p) MSGPACK_PP_NODE_4(p)(p)(p)
# define MSGPACK_PP_NODE_ENTRY_4(p) MSGPACK_PP_NODE_2(p)(p)
# define MSGPACK_PP_NODE_ENTRY_2(p) MSGPACK_PP_NODE_1(p)
#
# define MSGPACK_PP_NODE_128(p) MSGPACK_PP_IIF(p##(128), MSGPACK_PP_NODE_64, MSGPACK_PP_NODE_192)
#    define MSGPACK_PP_NODE_64(p) MSGPACK_PP_IIF(p##(64), MSGPACK_PP_NODE_32, MSGPACK_PP_NODE_96)
#        define MSGPACK_PP_NODE_32(p) MSGPACK_PP_IIF(p##(32), MSGPACK_PP_NODE_16, MSGPACK_PP_NODE_48)
#            define MSGPACK_PP_NODE_16(p) MSGPACK_PP_IIF(p##(16), MSGPACK_PP_NODE_8, MSGPACK_PP_NODE_24)
#                define MSGPACK_PP_NODE_8(p) MSGPACK_PP_IIF(p##(8), MSGPACK_PP_NODE_4, MSGPACK_PP_NODE_12)
#                    define MSGPACK_PP_NODE_4(p) MSGPACK_PP_IIF(p##(4), MSGPACK_PP_NODE_2, MSGPACK_PP_NODE_6)
#                        define MSGPACK_PP_NODE_2(p) MSGPACK_PP_IIF(p##(2), MSGPACK_PP_NODE_1, MSGPACK_PP_NODE_3)
#                            define MSGPACK_PP_NODE_1(p) MSGPACK_PP_IIF(p##(1), 1, 2)
#                            define MSGPACK_PP_NODE_3(p) MSGPACK_PP_IIF(p##(3), 3, 4)
#                        define MSGPACK_PP_NODE_6(p) MSGPACK_PP_IIF(p##(6), MSGPACK_PP_NODE_5, MSGPACK_PP_NODE_7)
#                            define MSGPACK_PP_NODE_5(p) MSGPACK_PP_IIF(p##(5), 5, 6)
#                            define MSGPACK_PP_NODE_7(p) MSGPACK_PP_IIF(p##(7), 7, 8)
#                    define MSGPACK_PP_NODE_12(p) MSGPACK_PP_IIF(p##(12), MSGPACK_PP_NODE_10, MSGPACK_PP_NODE_14)
#                        define MSGPACK_PP_NODE_10(p) MSGPACK_PP_IIF(p##(10), MSGPACK_PP_NODE_9, MSGPACK_PP_NODE_11)
#                            define MSGPACK_PP_NODE_9(p) MSGPACK_PP_IIF(p##(9), 9, 10)
#                            define MSGPACK_PP_NODE_11(p) MSGPACK_PP_IIF(p##(11), 11, 12)
#                        define MSGPACK_PP_NODE_14(p) MSGPACK_PP_IIF(p##(14), MSGPACK_PP_NODE_13, MSGPACK_PP_NODE_15)
#                            define MSGPACK_PP_NODE_13(p) MSGPACK_PP_IIF(p##(13), 13, 14)
#                            define MSGPACK_PP_NODE_15(p) MSGPACK_PP_IIF(p##(15), 15, 16)
#                define MSGPACK_PP_NODE_24(p) MSGPACK_PP_IIF(p##(24), MSGPACK_PP_NODE_20, MSGPACK_PP_NODE_28)
#                    define MSGPACK_PP_NODE_20(p) MSGPACK_PP_IIF(p##(20), MSGPACK_PP_NODE_18, MSGPACK_PP_NODE_22)
#                        define MSGPACK_PP_NODE_18(p) MSGPACK_PP_IIF(p##(18), MSGPACK_PP_NODE_17, MSGPACK_PP_NODE_19)
#                            define MSGPACK_PP_NODE_17(p) MSGPACK_PP_IIF(p##(17), 17, 18)
#                            define MSGPACK_PP_NODE_19(p) MSGPACK_PP_IIF(p##(19), 19, 20)
#                        define MSGPACK_PP_NODE_22(p) MSGPACK_PP_IIF(p##(22), MSGPACK_PP_NODE_21, MSGPACK_PP_NODE_23)
#                            define MSGPACK_PP_NODE_21(p) MSGPACK_PP_IIF(p##(21), 21, 22)
#                            define MSGPACK_PP_NODE_23(p) MSGPACK_PP_IIF(p##(23), 23, 24)
#                    define MSGPACK_PP_NODE_28(p) MSGPACK_PP_IIF(p##(28), MSGPACK_PP_NODE_26, MSGPACK_PP_NODE_30)
#                        define MSGPACK_PP_NODE_26(p) MSGPACK_PP_IIF(p##(26), MSGPACK_PP_NODE_25, MSGPACK_PP_NODE_27)
#                            define MSGPACK_PP_NODE_25(p) MSGPACK_PP_IIF(p##(25), 25, 26)
#                            define MSGPACK_PP_NODE_27(p) MSGPACK_PP_IIF(p##(27), 27, 28)
#                        define MSGPACK_PP_NODE_30(p) MSGPACK_PP_IIF(p##(30), MSGPACK_PP_NODE_29, MSGPACK_PP_NODE_31)
#                            define MSGPACK_PP_NODE_29(p) MSGPACK_PP_IIF(p##(29), 29, 30)
#                            define MSGPACK_PP_NODE_31(p) MSGPACK_PP_IIF(p##(31), 31, 32)
#            define MSGPACK_PP_NODE_48(p) MSGPACK_PP_IIF(p##(48), MSGPACK_PP_NODE_40, MSGPACK_PP_NODE_56)
#                define MSGPACK_PP_NODE_40(p) MSGPACK_PP_IIF(p##(40), MSGPACK_PP_NODE_36, MSGPACK_PP_NODE_44)
#                    define MSGPACK_PP_NODE_36(p) MSGPACK_PP_IIF(p##(36), MSGPACK_PP_NODE_34, MSGPACK_PP_NODE_38)
#                        define MSGPACK_PP_NODE_34(p) MSGPACK_PP_IIF(p##(34), MSGPACK_PP_NODE_33, MSGPACK_PP_NODE_35)
#                            define MSGPACK_PP_NODE_33(p) MSGPACK_PP_IIF(p##(33), 33, 34)
#                            define MSGPACK_PP_NODE_35(p) MSGPACK_PP_IIF(p##(35), 35, 36)
#                        define MSGPACK_PP_NODE_38(p) MSGPACK_PP_IIF(p##(38), MSGPACK_PP_NODE_37, MSGPACK_PP_NODE_39)
#                            define MSGPACK_PP_NODE_37(p) MSGPACK_PP_IIF(p##(37), 37, 38)
#                            define MSGPACK_PP_NODE_39(p) MSGPACK_PP_IIF(p##(39), 39, 40)
#                    define MSGPACK_PP_NODE_44(p) MSGPACK_PP_IIF(p##(44), MSGPACK_PP_NODE_42, MSGPACK_PP_NODE_46)
#                        define MSGPACK_PP_NODE_42(p) MSGPACK_PP_IIF(p##(42), MSGPACK_PP_NODE_41, MSGPACK_PP_NODE_43)
#                            define MSGPACK_PP_NODE_41(p) MSGPACK_PP_IIF(p##(41), 41, 42)
#                            define MSGPACK_PP_NODE_43(p) MSGPACK_PP_IIF(p##(43), 43, 44)
#                        define MSGPACK_PP_NODE_46(p) MSGPACK_PP_IIF(p##(46), MSGPACK_PP_NODE_45, MSGPACK_PP_NODE_47)
#                            define MSGPACK_PP_NODE_45(p) MSGPACK_PP_IIF(p##(45), 45, 46)
#                            define MSGPACK_PP_NODE_47(p) MSGPACK_PP_IIF(p##(47), 47, 48)
#                define MSGPACK_PP_NODE_56(p) MSGPACK_PP_IIF(p##(56), MSGPACK_PP_NODE_52, MSGPACK_PP_NODE_60)
#                    define MSGPACK_PP_NODE_52(p) MSGPACK_PP_IIF(p##(52), MSGPACK_PP_NODE_50, MSGPACK_PP_NODE_54)
#                        define MSGPACK_PP_NODE_50(p) MSGPACK_PP_IIF(p##(50), MSGPACK_PP_NODE_49, MSGPACK_PP_NODE_51)
#                            define MSGPACK_PP_NODE_49(p) MSGPACK_PP_IIF(p##(49), 49, 50)
#                            define MSGPACK_PP_NODE_51(p) MSGPACK_PP_IIF(p##(51), 51, 52)
#                        define MSGPACK_PP_NODE_54(p) MSGPACK_PP_IIF(p##(54), MSGPACK_PP_NODE_53, MSGPACK_PP_NODE_55)
#                            define MSGPACK_PP_NODE_53(p) MSGPACK_PP_IIF(p##(53), 53, 54)
#                            define MSGPACK_PP_NODE_55(p) MSGPACK_PP_IIF(p##(55), 55, 56)
#                    define MSGPACK_PP_NODE_60(p) MSGPACK_PP_IIF(p##(60), MSGPACK_PP_NODE_58, MSGPACK_PP_NODE_62)
#                        define MSGPACK_PP_NODE_58(p) MSGPACK_PP_IIF(p##(58), MSGPACK_PP_NODE_57, MSGPACK_PP_NODE_59)
#                            define MSGPACK_PP_NODE_57(p) MSGPACK_PP_IIF(p##(57), 57, 58)
#                            define MSGPACK_PP_NODE_59(p) MSGPACK_PP_IIF(p##(59), 59, 60)
#                        define MSGPACK_PP_NODE_62(p) MSGPACK_PP_IIF(p##(62), MSGPACK_PP_NODE_61, MSGPACK_PP_NODE_63)
#                            define MSGPACK_PP_NODE_61(p) MSGPACK_PP_IIF(p##(61), 61, 62)
#                            define MSGPACK_PP_NODE_63(p) MSGPACK_PP_IIF(p##(63), 63, 64)
#        define MSGPACK_PP_NODE_96(p) MSGPACK_PP_IIF(p##(96), MSGPACK_PP_NODE_80, MSGPACK_PP_NODE_112)
#            define MSGPACK_PP_NODE_80(p) MSGPACK_PP_IIF(p##(80), MSGPACK_PP_NODE_72, MSGPACK_PP_NODE_88)
#                define MSGPACK_PP_NODE_72(p) MSGPACK_PP_IIF(p##(72), MSGPACK_PP_NODE_68, MSGPACK_PP_NODE_76)
#                    define MSGPACK_PP_NODE_68(p) MSGPACK_PP_IIF(p##(68), MSGPACK_PP_NODE_66, MSGPACK_PP_NODE_70)
#                        define MSGPACK_PP_NODE_66(p) MSGPACK_PP_IIF(p##(66), MSGPACK_PP_NODE_65, MSGPACK_PP_NODE_67)
#                            define MSGPACK_PP_NODE_65(p) MSGPACK_PP_IIF(p##(65), 65, 66)
#                            define MSGPACK_PP_NODE_67(p) MSGPACK_PP_IIF(p##(67), 67, 68)
#                        define MSGPACK_PP_NODE_70(p) MSGPACK_PP_IIF(p##(70), MSGPACK_PP_NODE_69, MSGPACK_PP_NODE_71)
#                            define MSGPACK_PP_NODE_69(p) MSGPACK_PP_IIF(p##(69), 69, 70)
#                            define MSGPACK_PP_NODE_71(p) MSGPACK_PP_IIF(p##(71), 71, 72)
#                    define MSGPACK_PP_NODE_76(p) MSGPACK_PP_IIF(p##(76), MSGPACK_PP_NODE_74, MSGPACK_PP_NODE_78)
#                        define MSGPACK_PP_NODE_74(p) MSGPACK_PP_IIF(p##(74), MSGPACK_PP_NODE_73, MSGPACK_PP_NODE_75)
#                            define MSGPACK_PP_NODE_73(p) MSGPACK_PP_IIF(p##(73), 73, 74)
#                            define MSGPACK_PP_NODE_75(p) MSGPACK_PP_IIF(p##(75), 75, 76)
#                        define MSGPACK_PP_NODE_78(p) MSGPACK_PP_IIF(p##(78), MSGPACK_PP_NODE_77, MSGPACK_PP_NODE_79)
#                            define MSGPACK_PP_NODE_77(p) MSGPACK_PP_IIF(p##(77), 77, 78)
#                            define MSGPACK_PP_NODE_79(p) MSGPACK_PP_IIF(p##(79), 79, 80)
#                define MSGPACK_PP_NODE_88(p) MSGPACK_PP_IIF(p##(88), MSGPACK_PP_NODE_84, MSGPACK_PP_NODE_92)
#                    define MSGPACK_PP_NODE_84(p) MSGPACK_PP_IIF(p##(84), MSGPACK_PP_NODE_82, MSGPACK_PP_NODE_86)
#                        define MSGPACK_PP_NODE_82(p) MSGPACK_PP_IIF(p##(82), MSGPACK_PP_NODE_81, MSGPACK_PP_NODE_83)
#                            define MSGPACK_PP_NODE_81(p) MSGPACK_PP_IIF(p##(81), 81, 82)
#                            define MSGPACK_PP_NODE_83(p) MSGPACK_PP_IIF(p##(83), 83, 84)
#                        define MSGPACK_PP_NODE_86(p) MSGPACK_PP_IIF(p##(86), MSGPACK_PP_NODE_85, MSGPACK_PP_NODE_87)
#                            define MSGPACK_PP_NODE_85(p) MSGPACK_PP_IIF(p##(85), 85, 86)
#                            define MSGPACK_PP_NODE_87(p) MSGPACK_PP_IIF(p##(87), 87, 88)
#                    define MSGPACK_PP_NODE_92(p) MSGPACK_PP_IIF(p##(92), MSGPACK_PP_NODE_90, MSGPACK_PP_NODE_94)
#                        define MSGPACK_PP_NODE_90(p) MSGPACK_PP_IIF(p##(90), MSGPACK_PP_NODE_89, MSGPACK_PP_NODE_91)
#                            define MSGPACK_PP_NODE_89(p) MSGPACK_PP_IIF(p##(89), 89, 90)
#                            define MSGPACK_PP_NODE_91(p) MSGPACK_PP_IIF(p##(91), 91, 92)
#                        define MSGPACK_PP_NODE_94(p) MSGPACK_PP_IIF(p##(94), MSGPACK_PP_NODE_93, MSGPACK_PP_NODE_95)
#                            define MSGPACK_PP_NODE_93(p) MSGPACK_PP_IIF(p##(93), 93, 94)
#                            define MSGPACK_PP_NODE_95(p) MSGPACK_PP_IIF(p##(95), 95, 96)
#            define MSGPACK_PP_NODE_112(p) MSGPACK_PP_IIF(p##(112), MSGPACK_PP_NODE_104, MSGPACK_PP_NODE_120)
#                define MSGPACK_PP_NODE_104(p) MSGPACK_PP_IIF(p##(104), MSGPACK_PP_NODE_100, MSGPACK_PP_NODE_108)
#                    define MSGPACK_PP_NODE_100(p) MSGPACK_PP_IIF(p##(100), MSGPACK_PP_NODE_98, MSGPACK_PP_NODE_102)
#                        define MSGPACK_PP_NODE_98(p) MSGPACK_PP_IIF(p##(98), MSGPACK_PP_NODE_97, MSGPACK_PP_NODE_99)
#                            define MSGPACK_PP_NODE_97(p) MSGPACK_PP_IIF(p##(97), 97, 98)
#                            define MSGPACK_PP_NODE_99(p) MSGPACK_PP_IIF(p##(99), 99, 100)
#                        define MSGPACK_PP_NODE_102(p) MSGPACK_PP_IIF(p##(102), MSGPACK_PP_NODE_101, MSGPACK_PP_NODE_103)
#                            define MSGPACK_PP_NODE_101(p) MSGPACK_PP_IIF(p##(101), 101, 102)
#                            define MSGPACK_PP_NODE_103(p) MSGPACK_PP_IIF(p##(103), 103, 104)
#                    define MSGPACK_PP_NODE_108(p) MSGPACK_PP_IIF(p##(108), MSGPACK_PP_NODE_106, MSGPACK_PP_NODE_110)
#                        define MSGPACK_PP_NODE_106(p) MSGPACK_PP_IIF(p##(106), MSGPACK_PP_NODE_105, MSGPACK_PP_NODE_107)
#                            define MSGPACK_PP_NODE_105(p) MSGPACK_PP_IIF(p##(105), 105, 106)
#                            define MSGPACK_PP_NODE_107(p) MSGPACK_PP_IIF(p##(107), 107, 108)
#                        define MSGPACK_PP_NODE_110(p) MSGPACK_PP_IIF(p##(110), MSGPACK_PP_NODE_109, MSGPACK_PP_NODE_111)
#                            define MSGPACK_PP_NODE_109(p) MSGPACK_PP_IIF(p##(109), 109, 110)
#                            define MSGPACK_PP_NODE_111(p) MSGPACK_PP_IIF(p##(111), 111, 112)
#                define MSGPACK_PP_NODE_120(p) MSGPACK_PP_IIF(p##(120), MSGPACK_PP_NODE_116, MSGPACK_PP_NODE_124)
#                    define MSGPACK_PP_NODE_116(p) MSGPACK_PP_IIF(p##(116), MSGPACK_PP_NODE_114, MSGPACK_PP_NODE_118)
#                        define MSGPACK_PP_NODE_114(p) MSGPACK_PP_IIF(p##(114), MSGPACK_PP_NODE_113, MSGPACK_PP_NODE_115)
#                            define MSGPACK_PP_NODE_113(p) MSGPACK_PP_IIF(p##(113), 113, 114)
#                            define MSGPACK_PP_NODE_115(p) MSGPACK_PP_IIF(p##(115), 115, 116)
#                        define MSGPACK_PP_NODE_118(p) MSGPACK_PP_IIF(p##(118), MSGPACK_PP_NODE_117, MSGPACK_PP_NODE_119)
#                            define MSGPACK_PP_NODE_117(p) MSGPACK_PP_IIF(p##(117), 117, 118)
#                            define MSGPACK_PP_NODE_119(p) MSGPACK_PP_IIF(p##(119), 119, 120)
#                    define MSGPACK_PP_NODE_124(p) MSGPACK_PP_IIF(p##(124), MSGPACK_PP_NODE_122, MSGPACK_PP_NODE_126)
#                        define MSGPACK_PP_NODE_122(p) MSGPACK_PP_IIF(p##(122), MSGPACK_PP_NODE_121, MSGPACK_PP_NODE_123)
#                            define MSGPACK_PP_NODE_121(p) MSGPACK_PP_IIF(p##(121), 121, 122)
#                            define MSGPACK_PP_NODE_123(p) MSGPACK_PP_IIF(p##(123), 123, 124)
#                        define MSGPACK_PP_NODE_126(p) MSGPACK_PP_IIF(p##(126), MSGPACK_PP_NODE_125, MSGPACK_PP_NODE_127)
#                            define MSGPACK_PP_NODE_125(p) MSGPACK_PP_IIF(p##(125), 125, 126)
#                            define MSGPACK_PP_NODE_127(p) MSGPACK_PP_IIF(p##(127), 127, 128)
#    define MSGPACK_PP_NODE_192(p) MSGPACK_PP_IIF(p##(192), MSGPACK_PP_NODE_160, MSGPACK_PP_NODE_224)
#        define MSGPACK_PP_NODE_160(p) MSGPACK_PP_IIF(p##(160), MSGPACK_PP_NODE_144, MSGPACK_PP_NODE_176)
#            define MSGPACK_PP_NODE_144(p) MSGPACK_PP_IIF(p##(144), MSGPACK_PP_NODE_136, MSGPACK_PP_NODE_152)
#                define MSGPACK_PP_NODE_136(p) MSGPACK_PP_IIF(p##(136), MSGPACK_PP_NODE_132, MSGPACK_PP_NODE_140)
#                    define MSGPACK_PP_NODE_132(p) MSGPACK_PP_IIF(p##(132), MSGPACK_PP_NODE_130, MSGPACK_PP_NODE_134)
#                        define MSGPACK_PP_NODE_130(p) MSGPACK_PP_IIF(p##(130), MSGPACK_PP_NODE_129, MSGPACK_PP_NODE_131)
#                            define MSGPACK_PP_NODE_129(p) MSGPACK_PP_IIF(p##(129), 129, 130)
#                            define MSGPACK_PP_NODE_131(p) MSGPACK_PP_IIF(p##(131), 131, 132)
#                        define MSGPACK_PP_NODE_134(p) MSGPACK_PP_IIF(p##(134), MSGPACK_PP_NODE_133, MSGPACK_PP_NODE_135)
#                            define MSGPACK_PP_NODE_133(p) MSGPACK_PP_IIF(p##(133), 133, 134)
#                            define MSGPACK_PP_NODE_135(p) MSGPACK_PP_IIF(p##(135), 135, 136)
#                    define MSGPACK_PP_NODE_140(p) MSGPACK_PP_IIF(p##(140), MSGPACK_PP_NODE_138, MSGPACK_PP_NODE_142)
#                        define MSGPACK_PP_NODE_138(p) MSGPACK_PP_IIF(p##(138), MSGPACK_PP_NODE_137, MSGPACK_PP_NODE_139)
#                            define MSGPACK_PP_NODE_137(p) MSGPACK_PP_IIF(p##(137), 137, 138)
#                            define MSGPACK_PP_NODE_139(p) MSGPACK_PP_IIF(p##(139), 139, 140)
#                        define MSGPACK_PP_NODE_142(p) MSGPACK_PP_IIF(p##(142), MSGPACK_PP_NODE_141, MSGPACK_PP_NODE_143)
#                            define MSGPACK_PP_NODE_141(p) MSGPACK_PP_IIF(p##(141), 141, 142)
#                            define MSGPACK_PP_NODE_143(p) MSGPACK_PP_IIF(p##(143), 143, 144)
#                define MSGPACK_PP_NODE_152(p) MSGPACK_PP_IIF(p##(152), MSGPACK_PP_NODE_148, MSGPACK_PP_NODE_156)
#                    define MSGPACK_PP_NODE_148(p) MSGPACK_PP_IIF(p##(148), MSGPACK_PP_NODE_146, MSGPACK_PP_NODE_150)
#                        define MSGPACK_PP_NODE_146(p) MSGPACK_PP_IIF(p##(146), MSGPACK_PP_NODE_145, MSGPACK_PP_NODE_147)
#                            define MSGPACK_PP_NODE_145(p) MSGPACK_PP_IIF(p##(145), 145, 146)
#                            define MSGPACK_PP_NODE_147(p) MSGPACK_PP_IIF(p##(147), 147, 148)
#                        define MSGPACK_PP_NODE_150(p) MSGPACK_PP_IIF(p##(150), MSGPACK_PP_NODE_149, MSGPACK_PP_NODE_151)
#                            define MSGPACK_PP_NODE_149(p) MSGPACK_PP_IIF(p##(149), 149, 150)
#                            define MSGPACK_PP_NODE_151(p) MSGPACK_PP_IIF(p##(151), 151, 152)
#                    define MSGPACK_PP_NODE_156(p) MSGPACK_PP_IIF(p##(156), MSGPACK_PP_NODE_154, MSGPACK_PP_NODE_158)
#                        define MSGPACK_PP_NODE_154(p) MSGPACK_PP_IIF(p##(154), MSGPACK_PP_NODE_153, MSGPACK_PP_NODE_155)
#                            define MSGPACK_PP_NODE_153(p) MSGPACK_PP_IIF(p##(153), 153, 154)
#                            define MSGPACK_PP_NODE_155(p) MSGPACK_PP_IIF(p##(155), 155, 156)
#                        define MSGPACK_PP_NODE_158(p) MSGPACK_PP_IIF(p##(158), MSGPACK_PP_NODE_157, MSGPACK_PP_NODE_159)
#                            define MSGPACK_PP_NODE_157(p) MSGPACK_PP_IIF(p##(157), 157, 158)
#                            define MSGPACK_PP_NODE_159(p) MSGPACK_PP_IIF(p##(159), 159, 160)
#            define MSGPACK_PP_NODE_176(p) MSGPACK_PP_IIF(p##(176), MSGPACK_PP_NODE_168, MSGPACK_PP_NODE_184)
#                define MSGPACK_PP_NODE_168(p) MSGPACK_PP_IIF(p##(168), MSGPACK_PP_NODE_164, MSGPACK_PP_NODE_172)
#                    define MSGPACK_PP_NODE_164(p) MSGPACK_PP_IIF(p##(164), MSGPACK_PP_NODE_162, MSGPACK_PP_NODE_166)
#                        define MSGPACK_PP_NODE_162(p) MSGPACK_PP_IIF(p##(162), MSGPACK_PP_NODE_161, MSGPACK_PP_NODE_163)
#                            define MSGPACK_PP_NODE_161(p) MSGPACK_PP_IIF(p##(161), 161, 162)
#                            define MSGPACK_PP_NODE_163(p) MSGPACK_PP_IIF(p##(163), 163, 164)
#                        define MSGPACK_PP_NODE_166(p) MSGPACK_PP_IIF(p##(166), MSGPACK_PP_NODE_165, MSGPACK_PP_NODE_167)
#                            define MSGPACK_PP_NODE_165(p) MSGPACK_PP_IIF(p##(165), 165, 166)
#                            define MSGPACK_PP_NODE_167(p) MSGPACK_PP_IIF(p##(167), 167, 168)
#                    define MSGPACK_PP_NODE_172(p) MSGPACK_PP_IIF(p##(172), MSGPACK_PP_NODE_170, MSGPACK_PP_NODE_174)
#                        define MSGPACK_PP_NODE_170(p) MSGPACK_PP_IIF(p##(170), MSGPACK_PP_NODE_169, MSGPACK_PP_NODE_171)
#                            define MSGPACK_PP_NODE_169(p) MSGPACK_PP_IIF(p##(169), 169, 170)
#                            define MSGPACK_PP_NODE_171(p) MSGPACK_PP_IIF(p##(171), 171, 172)
#                        define MSGPACK_PP_NODE_174(p) MSGPACK_PP_IIF(p##(174), MSGPACK_PP_NODE_173, MSGPACK_PP_NODE_175)
#                            define MSGPACK_PP_NODE_173(p) MSGPACK_PP_IIF(p##(173), 173, 174)
#                            define MSGPACK_PP_NODE_175(p) MSGPACK_PP_IIF(p##(175), 175, 176)
#                define MSGPACK_PP_NODE_184(p) MSGPACK_PP_IIF(p##(184), MSGPACK_PP_NODE_180, MSGPACK_PP_NODE_188)
#                    define MSGPACK_PP_NODE_180(p) MSGPACK_PP_IIF(p##(180), MSGPACK_PP_NODE_178, MSGPACK_PP_NODE_182)
#                        define MSGPACK_PP_NODE_178(p) MSGPACK_PP_IIF(p##(178), MSGPACK_PP_NODE_177, MSGPACK_PP_NODE_179)
#                            define MSGPACK_PP_NODE_177(p) MSGPACK_PP_IIF(p##(177), 177, 178)
#                            define MSGPACK_PP_NODE_179(p) MSGPACK_PP_IIF(p##(179), 179, 180)
#                        define MSGPACK_PP_NODE_182(p) MSGPACK_PP_IIF(p##(182), MSGPACK_PP_NODE_181, MSGPACK_PP_NODE_183)
#                            define MSGPACK_PP_NODE_181(p) MSGPACK_PP_IIF(p##(181), 181, 182)
#                            define MSGPACK_PP_NODE_183(p) MSGPACK_PP_IIF(p##(183), 183, 184)
#                    define MSGPACK_PP_NODE_188(p) MSGPACK_PP_IIF(p##(188), MSGPACK_PP_NODE_186, MSGPACK_PP_NODE_190)
#                        define MSGPACK_PP_NODE_186(p) MSGPACK_PP_IIF(p##(186), MSGPACK_PP_NODE_185, MSGPACK_PP_NODE_187)
#                            define MSGPACK_PP_NODE_185(p) MSGPACK_PP_IIF(p##(185), 185, 186)
#                            define MSGPACK_PP_NODE_187(p) MSGPACK_PP_IIF(p##(187), 187, 188)
#                        define MSGPACK_PP_NODE_190(p) MSGPACK_PP_IIF(p##(190), MSGPACK_PP_NODE_189, MSGPACK_PP_NODE_191)
#                            define MSGPACK_PP_NODE_189(p) MSGPACK_PP_IIF(p##(189), 189, 190)
#                            define MSGPACK_PP_NODE_191(p) MSGPACK_PP_IIF(p##(191), 191, 192)
#        define MSGPACK_PP_NODE_224(p) MSGPACK_PP_IIF(p##(224), MSGPACK_PP_NODE_208, MSGPACK_PP_NODE_240)
#            define MSGPACK_PP_NODE_208(p) MSGPACK_PP_IIF(p##(208), MSGPACK_PP_NODE_200, MSGPACK_PP_NODE_216)
#                define MSGPACK_PP_NODE_200(p) MSGPACK_PP_IIF(p##(200), MSGPACK_PP_NODE_196, MSGPACK_PP_NODE_204)
#                    define MSGPACK_PP_NODE_196(p) MSGPACK_PP_IIF(p##(196), MSGPACK_PP_NODE_194, MSGPACK_PP_NODE_198)
#                        define MSGPACK_PP_NODE_194(p) MSGPACK_PP_IIF(p##(194), MSGPACK_PP_NODE_193, MSGPACK_PP_NODE_195)
#                            define MSGPACK_PP_NODE_193(p) MSGPACK_PP_IIF(p##(193), 193, 194)
#                            define MSGPACK_PP_NODE_195(p) MSGPACK_PP_IIF(p##(195), 195, 196)
#                        define MSGPACK_PP_NODE_198(p) MSGPACK_PP_IIF(p##(198), MSGPACK_PP_NODE_197, MSGPACK_PP_NODE_199)
#                            define MSGPACK_PP_NODE_197(p) MSGPACK_PP_IIF(p##(197), 197, 198)
#                            define MSGPACK_PP_NODE_199(p) MSGPACK_PP_IIF(p##(199), 199, 200)
#                    define MSGPACK_PP_NODE_204(p) MSGPACK_PP_IIF(p##(204), MSGPACK_PP_NODE_202, MSGPACK_PP_NODE_206)
#                        define MSGPACK_PP_NODE_202(p) MSGPACK_PP_IIF(p##(202), MSGPACK_PP_NODE_201, MSGPACK_PP_NODE_203)
#                            define MSGPACK_PP_NODE_201(p) MSGPACK_PP_IIF(p##(201), 201, 202)
#                            define MSGPACK_PP_NODE_203(p) MSGPACK_PP_IIF(p##(203), 203, 204)
#                        define MSGPACK_PP_NODE_206(p) MSGPACK_PP_IIF(p##(206), MSGPACK_PP_NODE_205, MSGPACK_PP_NODE_207)
#                            define MSGPACK_PP_NODE_205(p) MSGPACK_PP_IIF(p##(205), 205, 206)
#                            define MSGPACK_PP_NODE_207(p) MSGPACK_PP_IIF(p##(207), 207, 208)
#                define MSGPACK_PP_NODE_216(p) MSGPACK_PP_IIF(p##(216), MSGPACK_PP_NODE_212, MSGPACK_PP_NODE_220)
#                    define MSGPACK_PP_NODE_212(p) MSGPACK_PP_IIF(p##(212), MSGPACK_PP_NODE_210, MSGPACK_PP_NODE_214)
#                        define MSGPACK_PP_NODE_210(p) MSGPACK_PP_IIF(p##(210), MSGPACK_PP_NODE_209, MSGPACK_PP_NODE_211)
#                            define MSGPACK_PP_NODE_209(p) MSGPACK_PP_IIF(p##(209), 209, 210)
#                            define MSGPACK_PP_NODE_211(p) MSGPACK_PP_IIF(p##(211), 211, 212)
#                        define MSGPACK_PP_NODE_214(p) MSGPACK_PP_IIF(p##(214), MSGPACK_PP_NODE_213, MSGPACK_PP_NODE_215)
#                            define MSGPACK_PP_NODE_213(p) MSGPACK_PP_IIF(p##(213), 213, 214)
#                            define MSGPACK_PP_NODE_215(p) MSGPACK_PP_IIF(p##(215), 215, 216)
#                    define MSGPACK_PP_NODE_220(p) MSGPACK_PP_IIF(p##(220), MSGPACK_PP_NODE_218, MSGPACK_PP_NODE_222)
#                        define MSGPACK_PP_NODE_218(p) MSGPACK_PP_IIF(p##(218), MSGPACK_PP_NODE_217, MSGPACK_PP_NODE_219)
#                            define MSGPACK_PP_NODE_217(p) MSGPACK_PP_IIF(p##(217), 217, 218)
#                            define MSGPACK_PP_NODE_219(p) MSGPACK_PP_IIF(p##(219), 219, 220)
#                        define MSGPACK_PP_NODE_222(p) MSGPACK_PP_IIF(p##(222), MSGPACK_PP_NODE_221, MSGPACK_PP_NODE_223)
#                            define MSGPACK_PP_NODE_221(p) MSGPACK_PP_IIF(p##(221), 221, 222)
#                            define MSGPACK_PP_NODE_223(p) MSGPACK_PP_IIF(p##(223), 223, 224)
#            define MSGPACK_PP_NODE_240(p) MSGPACK_PP_IIF(p##(240), MSGPACK_PP_NODE_232, MSGPACK_PP_NODE_248)
#                define MSGPACK_PP_NODE_232(p) MSGPACK_PP_IIF(p##(232), MSGPACK_PP_NODE_228, MSGPACK_PP_NODE_236)
#                    define MSGPACK_PP_NODE_228(p) MSGPACK_PP_IIF(p##(228), MSGPACK_PP_NODE_226, MSGPACK_PP_NODE_230)
#                        define MSGPACK_PP_NODE_226(p) MSGPACK_PP_IIF(p##(226), MSGPACK_PP_NODE_225, MSGPACK_PP_NODE_227)
#                            define MSGPACK_PP_NODE_225(p) MSGPACK_PP_IIF(p##(225), 225, 226)
#                            define MSGPACK_PP_NODE_227(p) MSGPACK_PP_IIF(p##(227), 227, 228)
#                        define MSGPACK_PP_NODE_230(p) MSGPACK_PP_IIF(p##(230), MSGPACK_PP_NODE_229, MSGPACK_PP_NODE_231)
#                            define MSGPACK_PP_NODE_229(p) MSGPACK_PP_IIF(p##(229), 229, 230)
#                            define MSGPACK_PP_NODE_231(p) MSGPACK_PP_IIF(p##(231), 231, 232)
#                    define MSGPACK_PP_NODE_236(p) MSGPACK_PP_IIF(p##(236), MSGPACK_PP_NODE_234, MSGPACK_PP_NODE_238)
#                        define MSGPACK_PP_NODE_234(p) MSGPACK_PP_IIF(p##(234), MSGPACK_PP_NODE_233, MSGPACK_PP_NODE_235)
#                            define MSGPACK_PP_NODE_233(p) MSGPACK_PP_IIF(p##(233), 233, 234)
#                            define MSGPACK_PP_NODE_235(p) MSGPACK_PP_IIF(p##(235), 235, 236)
#                        define MSGPACK_PP_NODE_238(p) MSGPACK_PP_IIF(p##(238), MSGPACK_PP_NODE_237, MSGPACK_PP_NODE_239)
#                            define MSGPACK_PP_NODE_237(p) MSGPACK_PP_IIF(p##(237), 237, 238)
#                            define MSGPACK_PP_NODE_239(p) MSGPACK_PP_IIF(p##(239), 239, 240)
#                define MSGPACK_PP_NODE_248(p) MSGPACK_PP_IIF(p##(248), MSGPACK_PP_NODE_244, MSGPACK_PP_NODE_252)
#                    define MSGPACK_PP_NODE_244(p) MSGPACK_PP_IIF(p##(244), MSGPACK_PP_NODE_242, MSGPACK_PP_NODE_246)
#                        define MSGPACK_PP_NODE_242(p) MSGPACK_PP_IIF(p##(242), MSGPACK_PP_NODE_241, MSGPACK_PP_NODE_243)
#                            define MSGPACK_PP_NODE_241(p) MSGPACK_PP_IIF(p##(241), 241, 242)
#                            define MSGPACK_PP_NODE_243(p) MSGPACK_PP_IIF(p##(243), 243, 244)
#                        define MSGPACK_PP_NODE_246(p) MSGPACK_PP_IIF(p##(246), MSGPACK_PP_NODE_245, MSGPACK_PP_NODE_247)
#                            define MSGPACK_PP_NODE_245(p) MSGPACK_PP_IIF(p##(245), 245, 246)
#                            define MSGPACK_PP_NODE_247(p) MSGPACK_PP_IIF(p##(247), 247, 248)
#                    define MSGPACK_PP_NODE_252(p) MSGPACK_PP_IIF(p##(252), MSGPACK_PP_NODE_250, MSGPACK_PP_NODE_254)
#                        define MSGPACK_PP_NODE_250(p) MSGPACK_PP_IIF(p##(250), MSGPACK_PP_NODE_249, MSGPACK_PP_NODE_251)
#                            define MSGPACK_PP_NODE_249(p) MSGPACK_PP_IIF(p##(249), 249, 250)
#                            define MSGPACK_PP_NODE_251(p) MSGPACK_PP_IIF(p##(251), 251, 252)
#                        define MSGPACK_PP_NODE_254(p) MSGPACK_PP_IIF(p##(254), MSGPACK_PP_NODE_253, MSGPACK_PP_NODE_255)
#                            define MSGPACK_PP_NODE_253(p) MSGPACK_PP_IIF(p##(253), 253, 254)
#                            define MSGPACK_PP_NODE_255(p) MSGPACK_PP_IIF(p##(255), 255, 256)
#
# endif

#endif // !__VEIGAR_MSGPACK_PREPROCESSOR_DETAIL_DMC_AUTO_REC_HPP