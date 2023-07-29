#ifndef MYSTD_FUNCTION
#define MYSTD_FUNCTION

namespace MyStd
{
    /// @brief 基础函数类
    /// @tparam m_FunctionType 函数类型
    template <typename m_FunctionType>
    class BasicFunction
    {
    public:
        using FunctionType = m_FunctionType;
        using SelfType = BasicFunction<FunctionType>;

    private:
        FunctionType *m_func = Null;

    public:
        BasicFunction(FunctionType *func = Null) : m_func(func) {}

    public:
        SelfType &operator=(FunctionType *func)
        {
            m_func = func;
            return *this;
        }

    public:
        SelfType &set_func(FunctionType *func)
        {
            m_func = func;
            return *this;
        }

        const FunctionType *get_func() const
        {
            return m_func;
        }
    };

    /// @brief 函数类
    /// @tparam m_FunctionType 函数类型
    template <typename FunctionType>
    class Function;

    /// @brief 函数类
    /// @tparam m_ResultType 返回值类型
    /// @tparam ...ArgsType 参数类型
    template <typename m_ResultType, typename... ArgsType>
    class Function<m_ResultType(ArgsType...)> : public BasicFunction<m_ResultType(ArgsType...)>
    {
    public:
        using ResultType = m_ResultType;
        using FunctionType = ResultType(ArgsType...);
        using SelfType = Function<FunctionType>;
        using ParentType = BasicFunction<FunctionType>;

    public:
        Function(FunctionType *func = Null) : ParentType(func) {}

    public:
        ResultType operator()(const ArgsType... args) const
        {
            if (ParentType::get_func() == Null)
                throw "func is Null";

            return ParentType::get_func()(args...);
        }
    };

    template <typename m_ResultType, typename m_ClassType, typename... ArgsType>
    class Function<m_ResultType (m_ClassType::*)(ArgsType...)>
        : public BasicFunction<m_ResultType (m_ClassType::*)(ArgsType...)>
    {
    public:
        using ResultType = m_ResultType;
        using ClassType = m_ClassType;
        using FunctionType = ResultType (ClassType::*)(ArgsType...);
        using SelfType = Function<FunctionType>;
        using ParentType = BasicFunction<FunctionType>;

    public:
        Function(FunctionType func = Null) : ParentType(func) {}

    public:
        ResultType operator()(ClassType &cls, const ArgsType... args) const
        {
            if (ParentType::get_func() == Null)
                throw "func is Null";

            return (cls.*ParentType::get_func())(args...);
        }
    };

} // namespace MyStd

#endif
