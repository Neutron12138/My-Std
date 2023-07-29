#ifndef MYSTD_MEMORY
#define MYSTD_MEMORY

#include "Types.hpp"

namespace MyStd
{
    class Exception;

    /// @brief 把src拷贝到dst中
    /// @tparam MemoryType 内存块类型
    /// @param dst 目标地址
    /// @param src 源地址
    /// @param size 内存大小，单位：字节
    template <typename MemoryType = Int64_T>
    void memory_copy(void *dst, const void *src, Size_T size)
    {
        if (dst == Null || src == Null)
            throw "dst/src cannot be Null";
        if (size == 0)
            throw "size cannot be 0";

        // MemoryType类型的指针，指向目标地址
        MemoryType *dst2 = reinterpret_cast<MemoryType *>(dst);
        // MemoryType类型的指针，指向源地址
        const MemoryType *src2 = reinterpret_cast<const MemoryType *>(src);

        // Byte_T类型的指针，指向目标地址
        Byte_T *dst3 = reinterpret_cast<Byte_T *>(dst);
        // Byte_T类型的指针，指向源地址
        const Byte_T *src3 = reinterpret_cast<const Byte_T *>(src);

        // 需要进行的复制次数
        const Size_T size2 = size / sizeof(MemoryType);
        // 按MemoryType复制完后的内存末尾
        const Size_T end = size2 * sizeof(MemoryType);
        // 按Byte_T复制所需的次数
        const Size_T size3 = size - end;

        // 用MemoryType进行复制以增快速度
        for (Size_T i = 0; i < size2; i++)
            dst2[i] = src2[i];

        // 以字节方式复制
        for (Size_T i = 0; i < size3; i++)
            dst3[end + i] = src3[end + i];
    }

    /// @brief 把src拷贝到dst中
    /// @tparam ElementType 元素类型
    /// @tparam MemoryType 内存块类型
    /// @param dst 目标地址
    /// @param src 源地址
    /// @param size 元素数量
    template <typename ElementType, typename MemoryType = Int64_T>
    void memory_copy(ElementType *dst, const ElementType *src, Size_T size)
    {
        memory_copy<MemoryType>(
            reinterpret_cast<void *>(dst),
            reinterpret_cast<const void *>(src),
            size * sizeof(ElementType));
    }

    /// @brief 拷贝并返回新数组
    /// @tparam ElementType 元素类型
    /// @tparam MemoryType 内存块类型
    /// @param src 源地址
    /// @param size 元素数量
    /// @return 新数组地址
    template <typename ElementType, typename MemoryType = Int64_T>
    ElementType *memory_copy(const ElementType *src, Size_T size)
    {
        if (src == Null)
            throw "src cannot be Null";
        if (size == 0)
            throw "size cannot be 0";

        ElementType *result = new ElementType[size];
        memory_copy(result, src, size);
        return result;
    }

    template <typename ElementType>
    void memory_set(ElementType *mem, const ElementType &value, Size_T size)
    {
        if (mem == Null)
            throw "mem cannot be Null";

        for (Size_T i = 0; i < size; i++)
            mem[i] = value;
    }

} // namespace MyStd

#endif
