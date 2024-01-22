﻿/*
 * Copyright (c) winsoft666.
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */
#ifndef VEIGAR_STRING_HELPER_HPP__
#define VEIGAR_STRING_HELPER_HPP__
#pragma once

#include "os_platform.h"
#include <string>
#include <vector>

namespace veigar {
class StringHelper {
   public:
    // format a string
    static bool StringPrintfV(const char* format, va_list argList, std::string& output) noexcept;
    static bool StringPrintfV(const wchar_t* format, va_list argList, std::wstring& output) noexcept;

    static std::string StringPrintf(const char* format, ...) noexcept;
    static std::wstring StringPrintf(const wchar_t* format, ...) noexcept;

    static std::string StringPrintfV(const char* format, va_list argList) noexcept;
    static std::wstring StringPrintfV(const wchar_t* format, va_list argList) noexcept;
};
}  // namespace veigar
#endif  // !VEIGAR_STRING_HELPER_HPP__
