#ifndef MYSTD_CONTAINER
#define MYSTD_CONTAINER

#include "Types.hpp"
#include "Memory.hpp"

namespace MyStd
{
    /// @brief 可以调整大小的容器
    /// @tparam m_ElementType 元素类型
    template <typename m_ElementType>
    class ResizableContainer
    {
    public:
        using ElementType = m_ElementType;
        using SelfType = ResizableContainer<ElementType>;

    private:
        ElementType *m_data = Null;
        Size_T m_size = 0;

    public:
        ResizableContainer() = default;

        ResizableContainer(const SelfType &from)
        {
            *this = from;
        }

        ~ResizableContainer()
        {
            _clean_up();
        }

    public:
        SelfType &operator=(const SelfType &from)
        {
            m_data = memory_copy(from.m_data);
            m_size = from.m_size;
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

        SelfType copy() const
        {
            return *this;
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
            c_std::printf("cleaned\n");

            return *this;
        }
    };

} // namespace MyStd

#endif
