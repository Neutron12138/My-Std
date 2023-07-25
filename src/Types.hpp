#ifndef MYSTD_TYPES
#define MYSTD_TYPES

namespace MyStd
{
    using Byte_T = signed char;
    using Word_T = signed short;
    using DWord_T = signed int;
    using QWord_T = signed long long;

    using Int8_T = Byte_T;
    using Int16_T = Word_T;
    using Int32_T = DWord_T;
    using Int64_T = QWord_T;

    using UInt8_T = unsigned Int8_T;
    using UInt16_T = unsigned Int16_T;
    using UInt32_T = unsigned Int32_T;
    using UInt64_T = unsigned Int64_T;

    using Size_T = UInt64_T;

    using NullPtr_T = decltype(nullptr);
    const NullPtr_T Null = nullptr;

    using Char_T = char;
    using WChar_T = wchar_t;

    using Float32_T = float;
    using Float64_T = double;

} // namespace MyStd

#endif
