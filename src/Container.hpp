#ifndef MYSTD_CONTAINER
#define MYSTD_CONTAINER

#include <initializer_list>
#include "Types.hpp"
#include "Memory.hpp"

namespace MyStd
{
    /// @brief 查找数组第一个符合条件的元素索引，没有则返回size
    /// @tparam ElementType 元素类型
    /// @tparam FuncType 查找函数类型
    /// @param arr 数组
    /// @param size 大小
    /// @param func 查找函数
    /// @return 索引
    template <typename ElementType, typename FuncType>
    Size_T array_find_first(const ElementType *arr, Size_T size, FuncType func)
    {
        for (Size_T i = 0; i < size; i++)
            if (func(arr[i]))
                return i;
        return size;
    }

    template <typename ElementType, typename FuncType>
    ElementType *array_find_first(ElementType *begin, ElementType *end, FuncType func)
    {
        for (ElementType *iter = begin; iter != end; iter++)
            if (func(*iter))
                return iter;
        return end;
    }

    template <typename ElementType, typename FuncType>
    const ElementType *array_find_first(const ElementType *begin, const ElementType *end, FuncType func)
    {
        for (ElementType *iter = begin; iter != end; iter++)
            if (func(*iter))
                return iter;
        return end;
    }

    /// @brief 可以调整大小的容器
    /// @tparam m_ElementType 元素类型
    template <typename m_ElementType>
    class ArrayContainer
    {
    public:
        using ElementType = m_ElementType;
        using SelfType = ArrayContainer<ElementType>;

    private:
        ElementType *m_data = Null;
        Size_T m_size = 0;

    public:
        ArrayContainer() = default;

        ArrayContainer(Size_T size)
        {
            allocate(size);
        }

        ArrayContainer(const std::initializer_list<ElementType> &c)
        {
            *this = c;
        }

        ArrayContainer(const SelfType &c)
        {
            *this = c;
        }

        ~ArrayContainer()
        {
            _clean_up();
            c_std::printf("cleaned\n");
        }

    public:
        SelfType &operator=(const std::initializer_list<ElementType> &c)
        {
            m_size = c.size();
            m_data = memory_copy(c.begin(), c.size());
            return *this;
        }

        SelfType &operator=(const SelfType &c)
        {
            m_size = c.m_size;
            m_data = memory_copy(c.m_data);
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
        bool empty() const
        {
            return m_size == 0;
        }

        Size_T size() const
        {
            return m_size;
        }

        SelfType &allocate(Size_T size)
        {
            if (size == 0)
                _clean_up();

            m_size = size;
            m_data = new ElementType[size];

            return *this;
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

        ElementType &last()
        {
            return m_data[m_size - 1];
        }

        const ElementType &last() const
        {
            return m_data[m_size - 1];
        }

        ElementType &first()
        {
            return m_data[0];
        }

        const ElementType &first() const
        {
            return m_data[0];
        }

        SelfType copy() const
        {
            return *this;
        }

    public:
        template <typename FuncType>
        Size_T find_first(FuncType func)
        {
            return array_find_first(m_data, m_size, func);
        }

    protected:
        ElementType *_get_data()
        {
            return m_data;
        }

        Size_T &_get_size()
        {
            return m_size;
        }

        SelfType &_clean_up()
        {
            if (m_data != Null)
                delete[] m_data;
            m_size = 0;

            return *this;
        }

        SelfType &_reset(ElementType *new_data, Size_T new_size)
        {
            _clean_up();

            m_data = new_data;
            m_size = new_size;

            return *this;
        }
    };

} // namespace MyStd

#endif
