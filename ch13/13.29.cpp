#include <string>
#include <iostream>

using namespace std;

class HasPtr
{
public:
    friend void swap(HasPtr &p1, HasPtr &p2);
    string *ptr;
    int i;
    unsigned *use;
    HasPtr(const string &s = string("")) : ptr(new string(s)), i(0), use(new unsigned(1)){};

    HasPtr(HasPtr &hp)
    {
        ptr = hp.ptr;
        use = hp.use;
        *hp.use++;
        i = hp.i;
    }

    HasPtr &operator=(HasPtr hp)
    {
        if (--use == 0)
        {
            delete use;
            delete ptr;
        }

        *hp.use++;
        swap(*this, hp);
        return *this;
    }

    ~HasPtr()
    {
        if (--*use == 0)
        {
            delete use;
            delete ptr;
        }
    }

private:
};

inline void swap(HasPtr &hp1, HasPtr &hp2)
{
    using std::swap;

    swap(hp1.ptr, hp2.ptr);
    swap(hp1.i, hp2.i);
    swap(hp1.use, hp2.use);
}

int main()
{
    string a = "sddf";
    HasPtr hp1(a);

    HasPtr hp2 = hp1;

    cout << *hp2.ptr << endl;
}