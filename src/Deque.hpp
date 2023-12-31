#ifndef MYSTD_DEQUE
#define MYSTD_DEQUE

#include "Container.hpp"
#include "Vector.hpp"

namespace MyStd
{
    template <typename ElementType>
    ElementType *array_push_front(const ElementType *arr, Size_T size, const ElementType &value)
    {
        if ((arr == Null && size != 0) || (arr != Null && size == 0))
            throw "invalid arr/size";

        const Size_T new_size = size + 1;

        // 分配新数组
        ElementType *new_arr = new ElementType[new_size];

        // 判断旧数组是否不为空
        if (arr != Null)
            memory_copy(new_arr + 1, arr, size);

        // 第0个元素设置为新值
        new_arr[0] = value;

        return new_arr;
    }

    template <typename ElementType>
    ElementType *array_pop_front(const ElementType *arr, Size_T size)
    {
        if (arr == Null || size == 0)
            throw "empty array";

        const Size_T new_size = size - 1;

        ElementType *new_arr = new ElementType[new_size];
        memory_copy(new_arr, arr + 1, new_size);

        return new_arr;
    }

    /// @brief 双向队列类
    /// @tparam m_ElementType 元素类型
    template <typename m_ElementType>
    class Deque : public Vector<m_ElementType>
    {
    public:
        using ElementType = m_ElementType;
        using SelfType = Deque<ElementType>;
        using ParentType = Vector<ElementType>;

    public:
        Deque() = default;

        Deque(Size_T size) : ParentType(size) {}

        Deque(const std::initializer_list<ElementType> &deq) : ParentType(deq) {}

        Deque(const SelfType &deq) : ParentType(deq) {}

    public:
        SelfType &push_front(const ElementType &value)
        {
            ElementType *new_data = array_push_front(
                ParentType::data(), ParentType::size(), value);
            ParentType::_reset(new_data, ParentType::size() + 1);
            return *this;
        }

        ElementType pop_front()
        {
            if (ParentType::empty())
                throw "deque is empty";

            ElementType result = ParentType::first();
            ElementType *new_data = array_pop_front(
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
