#include "13.44.h"
#include <algorithm>

using namespace std;

String::String(const char *s)
{
    auto end = const_cast<char *>(s);

    while (*end)
        end++;

    range_initializer(s, end);
}

String::String(String &s)
{
    auto ret = alloc_n_copy(s.elements, s.end);
    elements = ret.first;
    end = ret.second;
}

String::String(String &&s) : elements(s.elements), end(s.end)
{
    s.elements = s.end = nullptr;
}

String &String::operator=(String &s)
{
    range_initializer(s.elements, s.end);
    return *this;
}

String &String::operator=(String &&s)
{
    if (this != &s)
    {
        elements = s.elements;
        end = s.end;
        s.elements = s.end = nullptr;
    }

    return *this;
}

std::ostream &operator<<(std::ostream &out, String &s)
{
    for (auto b = s.elements; b != s.end; b++)
    {
        out << *b;
    }

    return out;
}

pair<char *, char *> String::alloc_n_copy(const char *first, const char *last)
{
    auto newData = alloc.allocate(last - first);

    auto end = uninitialized_copy(first, last, newData);

    return {newData, end};
}

void String::range_initializer(const char *b, const char *e)
{
    auto ret = alloc_n_copy(b, e);
    elements = ret.first;
    end = ret.second;
}

void String::free()
{
    if (elements)
    {
        for_each(elements, end, [this](char *s) {
            alloc.destroy(s);
        });
        alloc.deallocate(elements, end - elements);
    }
}