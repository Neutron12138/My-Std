#ifndef MYSTD_MATH
#define MYSTD_MATH

#include "c_std.hpp"

namespace MyStd
{
    /*struct Zero
    {
        template <typename T>
        operator T() const
        {
            return static_cast<T>(0);
        }
    };*/

    /*template <typename T>
    struct LinearFunction
    {
        /// @brief 斜率
        T k;

        /// @brief 截距
        T b;

        LinearFunction(const T &x = Zero(), const T &y = Zero())
            : k(x), b(y) {}

        LinearFunction(const T &x1, const T &y1, const T &x2, const T &y2)
        {
            k = (y1 - y2) / (x1 - x2);
            b = y1 - x1 * k;
        }
    };

    template <typename T>
    T calculate_linear_function(const T &x)
    {
    }*/

    template <typename T>
    T min(const T &a, const T &b)
    {
        return a < b ? a : b;
    }

    template <typename Ta, typename Tb, typename... Ts>
    Ta min(const Ta &a, const Tb &b, const Ts &...args)
    {
        return min(min(a, b), args...);
    }

    template <typename T>
    T max(const T &a, const T &b)
    {
        return a > b ? a : b;
    }

    template <typename Ta, typename Tb, typename... Ts>
    Ta max(const Ta &a, const Tb &b, const Ts &...args)
    {
        return max(max(a, b), args...);
    }

    template <typename T>
    T clamp(const T &value, const T &_min, const T &_max)
    {
        return max(min(value, _max), _min);
    }

    template <typename T>
    T abs(const T &value)
    {
        return value > static_cast<T>(0) ? value : -value;
    }

    template <typename T>
    T map_range(
        const T &value,
        const T &from_min,
        const T &from_max,
        const T &to_min,
        const T &to_max)
    {
        if (from_min == from_max ||
            to_min == to_max)
            throw "the max and min values cannot be equal";

        /*T from_range = from_max - from_min;
        T to_range = to_max - to_min;
        T rate = (value - from_min) / from_range;
        return rate * to_range + to_min;*/

        T k = (to_max - to_min) / (from_max - from_min);
        return value * k;
    }

} // namespace MyStd

#endif
