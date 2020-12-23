#ifndef EX13_39
#define EX13_39

#include <string>
#include <memory>
#include <iostream>

class StrVec
{
public:
    using size_type = std::string::size_type;
    
    StrVec();

    StrVec(StrVec &sv);

    StrVec(StrVec &&sv);

    friend bool operator==(const StrVec &, const StrVec &);

    friend bool operator!=(const StrVec &, const StrVec &);
    friend bool operator>(const StrVec &, const StrVec &);
    friend bool operator<(const StrVec &, const StrVec &);

    std::string *operator[](size_type);

    StrVec &operator=(StrVec &sv);

    StrVec &operator=(StrVec &&sv);

    StrVec(std::initializer_list<std::string> li);

    ~StrVec();

    size_type size() const
    {
        return first_free - elements;
    }

    size_type capacity()
    {
        return cap - elements;
    }
    std::string *begin() const
    {
        return elements;
    }

    std::string *end() const
    {
        return first_free;
    }

    void push_back(const std::string &s) &;

    void push_back(std::string &&s) &;

    void push_back(std::string &s) &&;

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