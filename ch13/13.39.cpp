#include "13.39.h"

using namespace std;

StrVec::StrVec() : elements(nullptr), cap(nullptr), first_free(nullptr) {}
StrVec::StrVec(initializer_list<string> li)
{
    auto newData = alloc_n_copy(li.begin(), li.end());

    elements = newData.first;

    cap = first_free = newData.second;
}
StrVec::StrVec(StrVec &sv)
{
    auto newData = alloc_n_copy(sv.begin(), sv.end());
    cout << "StrVec(StrVec &sv)" << endl;
    elements = newData.first;
    cap = first_free = newData.second;
}

StrVec::StrVec(StrVec &&sv) : elements(sv.elements), cap(sv.cap), first_free(sv.first_free)
{
    sv.elements = sv.cap = sv.first_free = nullptr;
}

StrVec &StrVec::operator=(StrVec &sv)
{
    auto newData = alloc_n_copy(sv.begin(), sv.end());
    cout << "operator=(StrVec &sv)" << endl;
    free();
    elements = newData.first;
    cap = first_free = newData.second;
}

StrVec &StrVec::operator=(StrVec &&sv)
{
    cap = sv.cap;
    elements = sv.elements;
    first_free = sv.first_free;

    sv.elements = sv.cap = sv.first_free = nullptr;
}
StrVec::~StrVec()
{
    free();
}

void StrVec::push_back(const string &s) &
{
    check_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::push_back(string &&s) &
{
    check_n_alloc();
    alloc.construct(first_free++, std::move(s));
}

void StrVec::push_back(string &s) &&
{
    check_n_alloc();
    alloc.construct(first_free++, s);
}

void StrVec::check_n_alloc()
{
    if (size() == capacity())
    {
        reallocate();
    }
}

void StrVec::free()
{
    if (elements)
    {
        auto b = begin();
        auto e = first_free;

        for (; b != e; b++)
        {
            alloc.destroy(b);
        }

        alloc.deallocate(elements, cap - elements);
    }
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    auto newData = alloc.allocate(e - b);

    return {
        newData, uninitialized_copy(b, e, newData)};
}

void StrVec::reallocate()
{
    size_type newCapacity = size() ? size() * 2 : 1;

    auto newData = alloc.allocate(newCapacity);

    auto dest = newData;
    auto origin = elements;

    while (origin != first_free)
    {
        alloc.construct(dest++, move(*origin++));
    }

    free();
    elements = newData;
    first_free = dest;
    cap = elements + newCapacity;
}

bool operator==(const StrVec &v1, const StrVec &v2)
{
    if (v1.size() != v2.size())
    {
        return false;
    }
    bool result = true;

    for (int i = 0; i < v1.size(); ++i)
    {
        if (*(v1.begin() + i) != *(v2.begin() + i))
        {
            result = false;
            break;
        }
    }

    return result;
}
bool operator!=(const StrVec &v1, const StrVec &v2)
{
    return !(v1 == v2);
}

bool operator>(const StrVec &v1, const StrVec &v2)
{

    bool result = true;

    auto p1 = v1.begin();
    auto p2 = v2.begin();

    while (p1 != v1.end() && p2 != v2.end())
    {
        if (*p2 > *p1)
        {
            result = false;
            break;
        }
        else if (*p1 > *p2)
        {
            result = true;
            break;
        }

        ++p2;
        ++p1;
    }

    if (p1 == v1.end() && p2 == v2.end())
        return false;

    return result;
}
bool operator<(const StrVec &v1, const StrVec &v2)
{
    return !(v1 > v2);
}

std::string *StrVec::operator[](StrVec::size_type index)
{
    if (index >= size() || index < 0)
        throw out_of_range("invalid index");
        
    return begin() + index;
}

int main()
{
    StrVec sv{"1", "2", "3"};

    sv.push_back("a");
    // sv.push_back("b");
    // sv.push_back("c");

    auto b = sv.begin();

    while (b != sv.end())
    {
        cout << *b << endl;
        b++;
    }
}