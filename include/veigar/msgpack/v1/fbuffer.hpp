#ifndef __VEIGAR_MSGPACK_V1_FBUFFER_HPP // Add by msgpack.py
#define __VEIGAR_MSGPACK_V1_FBUFFER_HPP
//
// MessagePack for C++ FILE* buffer adaptor
//
// Copyright (C) 2013 Vladimir Volodko
//
//    Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//    http://www.boost.org/LICENSE_1_0.txt)
//
#ifndef MSGPACK_V1_FBUFFER_HPP
#define MSGPACK_V1_FBUFFER_HPP

#include "veigar/msgpack/v1/fbuffer_decl.hpp"
#include "veigar/msgpack/assert.hpp"

#include <cstdio>
#include <stdexcept>

namespace veigar_msgpack {

/// @cond
MSGPACK_API_VERSION_NAMESPACE(v1) {
/// @endcond

class fbuffer {
public:
    explicit fbuffer(FILE* file) : m_file(file) { }

public:
    void write(const char* buf, unsigned int len)
    {
        MSGPACK_ASSERT(buf || len == 0);
        if (!buf) return;
        if (1 != fwrite(buf, len, 1, m_file)) {
            throw std::runtime_error("fwrite() failed");
        }
    }

    FILE* file() const
    {
        return m_file;
    }

#if defined(MSGPACK_USE_CPP03)
private:
    fbuffer(const fbuffer&);
    fbuffer& operator=(const fbuffer&);
#else  // defined(MSGPACK_USE_CPP03)
    fbuffer(const fbuffer&) = delete;
    fbuffer& operator=(const fbuffer&) = delete;
#endif // defined(MSGPACK_USE_CPP03)

private:
    FILE* m_file;
};

/// @cond
}  // MSGPACK_API_VERSION_NAMESPACE(v1)
/// @endcond

}  // namespace veigar_msgpack

#endif // MSGPACK_V1_FBUFFER_HPP

#endif // !__VEIGAR_MSGPACK_V1_FBUFFER_HPP