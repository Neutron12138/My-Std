#include "../src/MyStd.hpp"

int main()
{
    // 测试memory_copy()
    int a[10];
    const int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    MyStd::memory_copy(a, b, 10);
    for (int i = 0; i < 10; i++)
        c_std::printf("%d ", a[i]);

    // 测试string_copy()
    c_std::printf("\n%d\n", MyStd::string_length("123"));
    char str1[4];
    const char *str2 = "abc";
    MyStd::string_copy(str1, str2);
    c_std::printf("%s\n", str1);

    // 测试异常
    MyStd::ExceptionPosition ep(__LINE__, __FILE__);
    c_std::printf("%d %s\n", ep.line, ep.file);
    try
    {
        int a;
        MyStd::memory_copy(&a, 0);
    }
    catch (const char *exception)
    {
        c_std::printf("%s\n", exception);
    }

    // 测试String
    MyStd::String str3 = "aabbcc";
    c_std::printf("%s\n", str3.data());

    // 测试Array
    MyStd::Array<int, 5> arr = {5, 4, 3, 2, 1};
    c_std::printf("%d ", arr.size());
    for (auto iter = arr.begin(); iter != arr.end(); iter++)
        c_std::printf("%d ", *iter);

    // 测试Vector
    MyStd::Vector<int> vec;
    for (auto i = 0; i < 5; i++)
        vec.push_back(5 - i);
    c_std::printf("%d ", vec.size());
    for (auto iter = vec.begin(); iter != vec.end(); iter++)
        c_std::printf("%d ", *iter);

    return 0;
}
