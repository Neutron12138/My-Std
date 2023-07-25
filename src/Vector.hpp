#ifndef MYSTD_VECTOR
#define MYSTD_VECTOR

#include "c_std.hpp"
#include "Types.hpp"
#include "Memory.hpp"
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
        return Null;
    }

    /// @brief 向量类
    /// @tparam m_ElementType 元素类型
    template <typename m_ElementType>
    class Vector : public ResizableContainer<m_ElementType>
    {
    public:
        using ElementType = m_ElementType;
        using SelfType = Vector<ElementType>;
        using ParentType = ResizableContainer<m_ElementType>;

    private:
        ElementType *m_data = Null;
        Size_T m_size = 0;

    public:
        Vector() = default;

        Vector(Size_T size)
        {
            ParentType::resize(size);
        }

        Vector(const std::initializer_list<ElementType> &vec)
        {
            *this = vec;
        }

        Vector(const SelfType &vec)
        {
            *this = vec;
        }

    public:
        SelfType &operator=(const std::initializer_list<ElementType> &vec)
        {
            m_size = vec.size();
            m_data = memory_copy(vec.begin(), vec.size());
            return *this;
        }

        SelfType &operator=(const SelfType &vec)
        {
            m_size = vec.size();
            m_data = memory_copy(vec.begin(), vec.size());
            return *this;
        }

    public:
        SelfType &push_back(const ElementType &value)
        {
            ElementType *new_data = array_push_back(m_data, m_size, value);
            delete[] m_data;
            m_data = new_data;
            m_size++;

            return *this;
        }

        ElementType pop()
        {
            if (ParentType::empty())
                throw "vector is empty";

            ElementType result = ParentType::last();
            ElementType *new_data = array_pop_back(m_data, m_size);
            delete[] m_data;
            m_data = new_data;
            m_size--;

            return result;
        }
    };

} // namespace MyStd

#endif
