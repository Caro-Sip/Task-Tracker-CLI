#pragma once
#include <string>

constexpr unsigned long hash_cstr(const char* s)
{
    unsigned long h = 5381;
    while (*s) {
        h = ((h << 5) + h) + static_cast<unsigned char>(*s++);
    }
    return h;
}