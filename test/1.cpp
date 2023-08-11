#include "../src/MyStd.hpp"

void test();
struct Test
{
    void test();
};

int main()
{
    // 测试memory_copy()
    c_std::printf("\n-----memory_copy()\n");
    int a[10];
    const int b[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    MyStd::memory_copy(a, b, 10);
    for (int i = 0; i < 10; i++)
        c_std::printf("%d ", a[i]);

    // 测试string_copy()
    c_std::printf("\n-----string_copy()\n");
    c_std::printf("%d ", MyStd::string_length("123"));
    char str1[4];
    const char *str2 = "abc";
    MyStd::string_copy(str1, str2);
    c_std::printf("%s\n", str1);

    // 测试异常
    c_std::printf("\n-----exception\n");
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

    // 测试Array
    c_std::printf("\n-----Array\n");
    MyStd::Array<int, 5> arr = {5, 4, 3, 2, 1};
    c_std::printf("%d ", arr.size());
    for (auto iter = arr.begin(); iter != arr.end(); iter++)
        c_std::printf("%d ", *iter);

    // 测试Container
    {
        c_std::printf("\n-----Container\n");
        MyStd::ArrayContainer<int> c = {15, 11, 11, 9, 7, 5, 3, 1};
        c.resize(5);
        c.resize(10);
        c_std::printf("%d ", c.find_first(MyStd::Equal<int, 11>()));
        c_std::printf("%d ", c.find_last(MyStd::Equal<int, 11>()));
        for (auto iter = c.begin(); iter != c.end(); iter++)
            c_std::printf("%d ", *iter);
    }

    // 测试Vector
    {
        c_std::printf("\n-----Vector\n");
        MyStd::Vector<int> vec;
        for (int i = 0; i < 5; i++)
            vec.push_back(-i);
        vec += vec;
        c_std::printf("\n%d ", vec.size());
        for (auto iter = vec.begin(); iter != vec.end(); iter++)
            c_std::printf("%d ", *iter);
    }

    // 测试Deque
    {
        c_std::printf("\n-----Deque\n");
        MyStd::Deque<int> deq;
        for (int i = 0; i < 5; i++)
            deq.push_front(-i);
        c_std::printf("\n%d ", deq.size());
        for (auto iter = deq.begin(); iter != deq.end(); iter++)
            c_std::printf("%d ", *iter);
    }

    // 测试String
    {
        c_std::printf("\n-----String\n");
        MyStd::String str3 = "aabbcc";
        ((str3 += "123") += 'z') += str3;
        c_std::printf("%s\n", str3.data());
    }

    // 测试Function
    c_std::printf("\n-----Function\n");
    MyStd::Function<void()> func1 = test;
    /*func1();
    MyStd::Function<void()> func2 = []()
    { c_std::printf("%s\n", "good job,lambda"); };
    func2();*/
    /*MyStd::Function<void (Test::*)()> func3 = &Test::test;
    Test t;
    func3(t);*/

    // 测试Stack
    {
        c_std::printf("\n-----Stack\n");
        MyStd::Stack<int> s;
        for (int i = 0; i < 10; i++)
            s.push(i);
        c_std::printf("\n%d ", s.size());
        try
        {
            for (; !s.empty();)
                c_std::printf("%d ", s.pop());
        }
        catch (const char *e)
        {
            c_std::printf("[%s]", e);
        }
    }

    // 测试数学
    c_std::printf("\n-----Math\n");
    c_std::printf("%d %d %d %d %d %d %f\n",
                  MyStd::min(10, 12, 25, 3, 47, 5),
                  MyStd::max(17, 45, 20, 5, 53, 12),
                  MyStd::clamp(3, 10, 20),
                  MyStd::clamp(27, 10, 20),
                  MyStd::abs(-10),
                  MyStd::abs(10),
                  MyStd::map_range<float>(10, 0, 100, 0, 10));
    // c_std::printf("%f ",MyStd::LinearFunction(0,0,100,100).b);

    return 0;
}

void test()
{
    c_std::printf("%s\n", "good job,test()");
}

void Test::test()
{
    c_std::printf("%s\n", "good job,Test::test()");
}
