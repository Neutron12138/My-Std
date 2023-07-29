#ifndef MYSTD_STRING
#define MYSTD_STRING

#include "Deque.hpp"

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

    /// @brief 向str末尾追加字符c
    /// @tparam CharType 字符类型
    /// @param str 字符串
    /// @param c 待追加字符
    /// @return 新字符串
    template <typename CharType>
    CharType *string_append(const CharType *str, const CharType &c)
    {
        const Size_T length = string_length(str);

        CharType *new_str = new CharType[length + 1 + 1];
        if (str != Null)
            memory_copy(new_str, str, length);
        new_str[length] = c;
        new_str[length + 1] = '\0';

        return new_str;
    }
    /// @brief 向str1末尾追加str2
    /// @tparam CharType 字符类型
    /// @param str1 字符串1
    /// @param str2 字符串2
    /// @return 新字符串
    template <typename CharType>
    CharType *string_append(const CharType *str1, const CharType *str2)
    {
        const Size_T length1 = string_length(str1);
        const Size_T length2 = string_length(str2);

        CharType *new_str = new CharType[length1 + length2 + 1];
        if (str1 != Null)
            memory_copy(new_str, str1, length1);
        if (str2 != Null)
            memory_copy(new_str + length1, str2, length2 + 1);

        return new_str;
    }

    /// @brief 字符串类
    /// @tparam m_CharType 字符类型
    template <typename m_CharType = char>
    class String : public Deque<m_CharType>
    {
    public:
        using CharType = m_CharType;
        using SelfType = String<CharType>;
        using ParentType = Deque<CharType>;

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

    public:
        SelfType &operator=(const CharType *str)
        {
            ParentType::_reset(string_copy(str), string_length(str));
            return *this;
        }

        SelfType &operator=(const SelfType &str)
        {
            ParentType::_reset(string_copy(str.data()), str.length());
            return *this;
        }

        SelfType operator+(const CharType &c) const
        {
            return copy().append(c);
        }

        SelfType &operator+=(const CharType &c)
        {
            append(c);
            return *this;
        }

        SelfType operator+(const CharType *str) const
        {
            return copy().append(str);
        }

        SelfType &operator+=(const CharType *str)
        {
            append(str);
            return *this;
        }

        SelfType operator+(const SelfType &str) const
        {
            return copy().append(str);
        }

        SelfType &operator+=(const SelfType &str)
        {
            append(str);
            return *this;
        }

    public:
        Size_T length() const
        {
            return ParentType::size();
        }

    public:
        SelfType &append(const CharType &c)
        {
            CharType *new_str = string_append(
                ParentType::data(), c);
            ParentType::_reset(new_str, length() + 1);

            return *this;
        }

        SelfType &append(const CharType *str)
        {
            CharType *new_str = string_append(
                ParentType::data(), str);
            ParentType::_reset(new_str, string_length(new_str));

            return *this;
        }

        SelfType &append(const SelfType &str)
        {
            CharType *new_str = string_append(
                ParentType::data(), str.data());
            ParentType::_reset(new_str, length() + str.length());

            return *this;
        }

        SelfType copy() const
        {
            return static_cast<SelfType>(*this);
        }
    };

} // namespace MyStd

#endif
