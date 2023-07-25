#ifndef MYSTD_EXCEPTION
#define MYSTD_EXCEPTION

#include "Types.hpp"

namespace MyStd
{
    template <typename CharType, typename MemoryType>
    CharType *string_copy(const CharType *src);

    struct ExceptionPosition
    {
        Size_T line;
        char *file = Null;

        ExceptionPosition(Size_T l, const char *f)
        {
            line = l;
            file = string_copy(f);
        }

        ~ExceptionPosition()
        {
            if (file != Null)
                delete[] file;
        }

        ExceptionPosition &operator=(const ExceptionPosition &from)
        {
            line = from.line;
            file = string_copy(from.file);
            return *this;
        }
    };

    class Exception
    {
    private:
        ExceptionPosition m_ep;
        char *m_what = Null;

    public:
        Exception(Size_T line, const char *file, const char *what)
            : m_ep(line, file)
        {
            m_what = string_copy(what);
        }

        ~Exception()
        {
            if (m_what != Null)
                delete[] m_what;
        }

    public:
        Exception &operator=(const Exception &from)
        {
            m_ep = from.m_ep;
            m_what = string_copy(from.m_what);
            return *this;
        }

    public:
        Size_T line() const
        {
            return m_ep.line;
        }

        const char *file() const
        {
            return m_ep.file;
        }

        const char *what() const
        {
            return m_what;
        }
    };

} // namespace MyStd

#endif
