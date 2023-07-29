#ifndef MYSTD_MATH
#define MYSTD_MATH

#include "c_std.hpp"

namespace MyStd
{
    template <typename T>
    T min(const T &a, const T &b)
    {
        return a < b ? a : b;
    }

    template <typename T>
    T max(const T &a, const T &b)
    {
        return a > b ? a : b;
    }

} // namespace MyStd

#endif
