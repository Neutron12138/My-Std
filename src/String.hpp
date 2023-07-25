#ifndef MYSTD_STRING
#define MYSTD_STRING

#include "Types.hpp"
#include "Memory.hpp"

namespace MyStd
{

    /// @brief 测量字符串长度，不包括'\0'
    /// @tparam CharType 字符类型
    /// @param str 字符串
    /// @return 字符串长度
    template <typename CharType>
    Size_T string_length(const CharType *str)
    {
        if (str == Null)
            return 0;

        Size_T i = 0;
        for (; static_cast<int>(str[i]) != 0; i++)
            ;
        return i;
    }

    /// @brief 把字符串src拷贝到dst中
    /// @tparam CharType 字符类型
    /// @param dst 目标字符串
    /// @param src 源字符串
    /// @return 错误码
    template <typename CharType, typename MemoryType = Int64_T>
    void string_copy(CharType *dst, const CharType *src)
    {
        Size_T length = string_length(src);
        memory_copy<CharType, MemoryType>(dst, src, length + 1);
    }

    /// @brief 复制str并返回新字符串
    /// @tparam CharType 字符类型
    /// @tparam MemoryType 内存块类型
    /// @param str 源字符串
    /// @return 新字符串
    template <typename CharType, typename MemoryType = Int64_T>
    CharType *string_copy(const CharType *str)
    {
        Size_T length = string_length(str);
        return memory_copy<CharType, MemoryType>(str, length + 1);
    }

    /// @brief 字符串类
    /// @tparam m_CharType 字符类型
    template <typename m_CharType = char>
    class String
    {
    public:
        using CharType = m_CharType;
        using SelfType = String<CharType>;

    private:
        CharType *m_data = Null;
        Size_T m_length = 0;

    public:
        String() = default;

        String(const CharType *str)
        {
            *this = str;
        }

        String(const SelfType &str)
        {
            *this = str;
        }

        ~String()
        {
            if (m_data != Null)
                delete[] m_data;

            m_length = 0;
        }

    public:
        SelfType &operator=(const CharType *str)
        {
            m_length = string_length(str);
            m_data = string_copy(str);
            return *this;
        }

        SelfType &operator=(const SelfType &str)
        {
            m_length = str.m_length;
            m_data = string_copy(str.m_data);
            return *this;
        }

        CharType &operator[](Size_T index)
        {
            if (index >= m_length)
                throw "index out of range";

            return m_data[index];
        }

        const CharType &operator[](Size_T index) const
        {
            if (index >= m_length)
                throw "index out of range";

            return m_data[index];
        }

    public:
        Size_T length() const
        {
            return m_length;
        }

        const CharType *data() const
        {
            return m_data;
        }

        CharType *begin()
        {
            return m_data;
        }

        const CharType *begin() const
        {
            return m_data;
        }

        CharType *end()
        {
            return m_data + m_length;
        }

        const CharType *end() const
        {
            return m_data + m_length;
        }

        SelfType copy() const
        {
            return *this;
        }
    };

} // namespace MyStd

#endif
