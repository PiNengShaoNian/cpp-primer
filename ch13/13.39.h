#ifndef EX13_39
#define EX13_39

#include <string>
#include <memory>
#include <iostream>

class StrVec
{
public:
    StrVec();

    StrVec(StrVec &sv);

    StrVec(StrVec &&sv);

    StrVec &operator=(StrVec &sv);
    
    StrVec &operator=(StrVec &&sv);

    StrVec(std::initializer_list<std::string> li);

    ~StrVec();

    using size_type = std::string::size_type;

    size_type size()
    {
        return first_free - elements;
    }

    size_type capacity()
    {
        return cap - elements;
    }
    std::string *begin()
    {
        return elements;
    }

    std::string *end()
    {
        return first_free;
    }

    void push_back(const std::string &s);

private:
    std::allocator<std::string> alloc;
    std::string *elements;
    std::string *first_free;
    std::string *cap;
    void check_n_alloc();

    void free();

    std::pair<std::string *, std::string *> alloc_n_copy(const std::string *b, const std::string *e);

    void reallocate();
};

#endif