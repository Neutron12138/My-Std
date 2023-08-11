#ifndef MYSTD_QUEUE
#define MYSTD_QUEUE

#include "Deque.hpp"

namespace MyStd
{
    /// @brief 队列类
    /// @tparam m_ElementType 元素类型
    template <typename m_ElementType>
    class Queue : public Deque<m_ElementType>
    {
    public:
        using ElementType = m_ElementType;
        using SelfType = Queue<ElementType>;
        using ParentType = Deque<ElementType>;

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
            return ParentType::pop_front();
        }

    public:
        SelfType &append(const ElementType &value) = delete;
        SelfType &append(const std::initializer_list<ElementType> &vec) = delete;
        SelfType &append(const SelfType &vec) = delete;
        SelfType &push_back(const ElementType &value) = delete;
        ElementType pop_back() = delete;
        SelfType &push_front(const ElementType &value) = delete;
        ElementType pop_front() = delete;

    public:
        SelfType copy() const
        {
            return static_cast<SelfType>(*this);
        }
    };

} // namespace MyStd

#endif
