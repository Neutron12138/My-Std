#ifndef MYSTD_ARRAY
#define MYSTD_ARRAY

#include "c_std.hpp"
#include "Types.hpp"
#include "Memory.hpp"

namespace MyStd
{
    /// @brief 数组类
    /// @tparam m_ElementType 元素类型
    /// @tparam m_size 数组大小
    template <typename m_ElementType, Size_T m_size>
    class Array
    {
    public:
        using ElementType = m_ElementType;
        using SelfType = Array<ElementType, m_size>;

    private:
        ElementType m_data[m_size];

    public:
        Array() = default;

        Array(const std::initializer_list<ElementType> &arr)
        {
            *this = arr;
        }

        Array(const SelfType &arr)
        {
            *this = arr;
        }

    public:
        SelfType &operator=(const std::initializer_list<ElementType> &arr)
        {
            for (Size_T i = 0; i < arr.size(); i++)
                m_data[i] = *(arr.begin() + i);
            return *this;
        }

        SelfType &operator=(const SelfType &arr)
        {
            memory_copy(m_data, arr.m_data, m_size);
            return *this;
        }

        ElementType &operator[](Size_T index)
        {
            if (index >= m_size)
                throw "index out of range";

            return m_data[index];
        }

        const ElementType &operator[](Size_T index) const
        {
            if (index >= m_size)
                throw "index out of range";

            return m_data[index];
        }

    public:
        Size_T size() const
        {
            return m_size;
        }

        const ElementType *data() const
        {
            return m_data;
        }

        ElementType *begin()
        {
            return m_data;
        }

        const ElementType *begin() const
        {
            return m_data;
        }

        ElementType *end()
        {
            return m_data + m_size;
        }

        const ElementType *end() const
        {
            return m_data + m_size;
        }
    };

} // namespace MyStd

#endif
