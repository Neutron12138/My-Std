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
        if ((arr == Null && size != 0) || (arr != Null && size == 0))
            throw "invalid arr/size";

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
        if (arr == Null || size == 0)
            throw "empty array";

        ElementType *new_arr = new ElementType[size - 1];
        memory_copy(new_arr, arr, size - 1);

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
        SelfType &push_back(const ElementType &value)
        {
            ElementType *new_data = array_push_back(
                ParentType::_get_data(), ParentType::_get_size(), value);
            ParentType::_reset(new_data, ParentType::_get_size() + 1);

            return *this;
        }

        ElementType pop_back()
        {
            if (ParentType::empty())
                throw "vector is empty";

            ElementType result = ParentType::last();
            ElementType *new_data = array_pop_back(
                ParentType::_get_data(), ParentType::_get_size());
            ParentType::_reset(new_data, ParentType::_get_size() - 1);

            return result;
        }
    };

} // namespace MyStd

#endif
