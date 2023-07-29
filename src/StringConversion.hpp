#ifndef MYSTD_STRINGCONVERSION
#define MYSTD_STRINGCONVERSION

#include "Types.hpp"

namespace MyStd
{
    /// @brief 默认的大写基数表
    const char DEFAULT_BASE_CAP[] =
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    /// @brief 默认的小写基数表
    const char DEFAULT_BASE_SMA[] =
        {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    /// @brief 将字符串转换为整数
    /// @tparam ReturnType 返回值类型
    /// @tparam CharType 字符类型
    /// @param str 待转换字符串
    /// @param index 开始索引
    /// @param base 基数（进制）
    /// @return 返回值
    template <typename ReturnType, typename CharType>
    ReturnType string_to_integer(
        const CharType *str, Size_T index = 0, Size_T base = 10)
    {
    }

    /// @brief 把整数转换为字符串
    /// @tparam CharType 字符类型
    /// @tparam ValueType 值类型
    /// @param value 待转换整数
    /// @param base 基数（进制）
    /// @return 返回值
    template <typename CharType, typename ValueType>
    CharType *integer_to_string(
        const ValueType &value, Size_T base = 10)
    {
    }

} // namespace MyStd

#endif
