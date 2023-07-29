#ifndef MYSTD_VECTOR
#define MYSTD_VECTOR

#include "Container.hpp"

namespace MyStd
{
    /// @brief 向数组添加新元素
    /// @tparam ElementType 元素类型
    /// @param arr 源数组
    /// @param size 源数组大小
    /// @param value 新增值
    /// @return 新数组
    template <typename ElementType>
    ElementType *array_push_back(const ElementType *arr, Size_T size, const ElementType &value)
    {
        array_check(arr, size);

        // 分配新数组
        ElementType *new_arr = new ElementType[size + 1];

        // 判断旧数组是否不为空
        if (arr != Null)
            memory_copy(new_arr, arr, size);

        // 第size个元素设置为新值
        new_arr[size] = value;

        return new_arr;
    }

    /// @brief 去除数组的最后一个元素
    /// @tparam ElementType 元素类型
    /// @param arr 源数组
    /// @param size 源数组大小
    /// @return 新数组
    template <typename ElementType>
    ElementType *array_pop_back(const ElementType *arr, Size_T size)
    {
        if (array_is_empty(arr, size))
            throw "empty array";

        ElementType *new_arr = new ElementType[size - 1];
        memory_copy(new_arr, arr, size - 1);

        return new_arr;
    }

    /// @brief 向arr1末尾追加arr2
    /// @tparam ElementType 元素类型
    /// @param arr1 数组1
    /// @param size1 数组大小1
    /// @param arr2 数组2
    /// @param size2 数组大小2
    /// @return 新数组
    template <typename ElementType>
    ElementType *array_append(const ElementType *arr1, Size_T size1, const ElementType *arr2, Size_T size2)
    {
        array_check(arr1, size1);
        array_check(arr2, size2);

        ElementType *new_arr = new ElementType[size1 + size2];
        if (size1 != 0)
            memory_copy(new_arr, arr1, size1);
        if (size2 != 0)
            memory_copy(new_arr + size1, arr2, size2);

        return new_arr;
    }

    /// @brief 向量类
    /// @tparam m_ElementType 元素类型
    template <typename m_ElementType>
    class Vector : public ArrayContainer<m_ElementType>
    {
    public:
        using ElementType = m_ElementType;
        using SelfType = Vector<ElementType>;
        using ParentType = ArrayContainer<m_ElementType>;

    public:
        Vector() = default;

        Vector(Size_T size) : ParentType(size) {}

        Vector(const std::initializer_list<ElementType> &vec) : ParentType(vec) {}

        Vector(const SelfType &vec) : ParentType(vec) {}

    public:
        SelfType operator+(const ElementType &value) const
        {
            return copy().append(value);
        }

        SelfType &operator+=(const ElementType &value)
        {
            append(value);
            return *this;
        }

        SelfType operator+(const std::initializer_list<ElementType> &vec) const
        {
            return copy().append(vec);
        }

        SelfType &operator+=(const std::initializer_list<ElementType> &vec)
        {
            append(vec);
            return *this;
        }

        SelfType operator+(const SelfType &vec) const
        {
            return copy().append(vec);
        }

        SelfType &operator+=(const SelfType &vec)
        {
            append(vec);
            return *this;
        }

    public:
        SelfType &append(const ElementType &value)
        {
            push_back(value);
            return *this;
        }

        SelfType &append(const std::initializer_list<ElementType> &vec)
        {
            ElementType *new_data = array_append(
                ParentType::data(), ParentType::size(),
                vec.begin(), vec.size());
            ParentType::_reset(new_data, ParentType::size() + vec.size());

            return *this;
        }

        SelfType &append(const SelfType &vec)
        {
            ElementType *new_data = array_append(
                ParentType::data(), ParentType::size(),
                vec.data(), vec.size());
            ParentType::_reset(new_data, ParentType::size() + vec.size());

            return *this;
        }

        SelfType &push_back(const ElementType &value)
        {
            ElementType *new_data = array_push_back(
                ParentType::data(), ParentType::size(), value);
            ParentType::_reset(new_data, ParentType::size() + 1);

            return *this;
        }

        ElementType pop_back()
        {
            if (ParentType::empty())
                throw "vector is empty";

            ElementType result = ParentType::last();
            ElementType *new_data = array_pop_back(
                ParentType::data(), ParentType::size());
            ParentType::_reset(new_data, ParentType::size() - 1);

            return result;
        }

    public:
        SelfType copy() const
        {
            return static_cast<SelfType>(*this);
        }
    };

} // namespace MyStd

#endif
