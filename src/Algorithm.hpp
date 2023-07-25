#ifndef MYSTD_ALGORITHM
#define MYSTD_ALGORITHM

namespace MyStd
{
    template <typename ElementType, ElementType target>
    struct Equal
    {
        bool operator()(const ElementType &value)
        {
            return value == target;
        }
    };

} // namespace MyStd

#endif
