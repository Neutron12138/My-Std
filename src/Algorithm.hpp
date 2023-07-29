#ifndef MYSTD_ALGORITHM
#define MYSTD_ALGORITHM

namespace MyStd
{
    template <typename ElementType, ElementType target>
    struct Equal
    {
        bool operator()(const ElementType &value) const
        {
            return value == target;
        }
    };

    template <typename ElementType, ElementType target>
    struct NotEqual
    {
        bool operator()(const ElementType &value) const
        {
            return value != target;
        }
    };

    template <typename ElementType, ElementType target>
    struct Less
    {
        bool operator()(const ElementType &value) const
        {
            return value < target;
        }
    };

    template <typename ElementType, ElementType target>
    struct LEqual
    {
        bool operator()(const ElementType &value) const
        {
            return value <= target;
        }
    };

    template <typename ElementType, ElementType target>
    struct Greater
    {
        bool operator()(const ElementType &value) const
        {
            return value > target;
        }
    };

    template <typename ElementType, ElementType target>
    struct GEqual
    {
        bool operator()(const ElementType &value) const
        {
            return value >= target;
        }
    };

} // namespace MyStd

#endif
