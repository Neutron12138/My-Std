#ifndef MYSTD_STACK
#define MYSTD_STACK

#include "Vector.hpp"

namespace MyStd
{
    /// @brief 栈类
    /// @tparam m_ElementType 元素类型
    template <typename m_ElementType>
    class Stack : public Vector<m_ElementType>
    {
    public:
        using ElementType = m_ElementType;
        using SelfType = Stack<ElementType>;
        using ParentType = Vector<ElementType>;

    public:
        SelfType operator+(const ElementType &value) const = delete;
        SelfType &operator+=(const ElementType &value) = delete;
        SelfType operator+(const std::initializer_list<ElementType> &vec) const = delete;
        SelfType &operator+=(const std::initializer_list<ElementType> &vec) = delete;
        SelfType operator+(const SelfType &vec) const = delete;
        SelfType &operator+=(const SelfType &vec) = delete;

    public:
        SelfType &push(const ElementType &value)
        {
            ParentType::push_back(value);
            return *this;
        }

        ElementType pop()
        {
            return ParentType::pop_back();
        }

    public:
        SelfType &append(const ElementType &value) = delete;
        SelfType &append(const std::initializer_list<ElementType> &vec) = delete;
        SelfType &append(const SelfType &vec) = delete;
        SelfType &push_back(const ElementType &value) = delete;
        ElementType pop_back() = delete;

    public:
        SelfType copy() const
        {
            return static_cast<SelfType>(*this);
        }
    };

} // namespace MyStd

#endif
