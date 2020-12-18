#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(string &s = string("")) : ptr(new string(s)){};

    HasPtr(HasPtr &hp)
    {
        ptr = new string(*hp.ptr);
        i = hp.i;
    }

    HasPtr &operator=(HasPtr &hp)
    {
        auto newPtr = new string(*hp.ptr);

        delete ptr;
        ptr = newPtr;
        i = hp.i;
        return *this;
    }

    ~HasPtr()
    {
        delete ptr;
    }

private:
    string *ptr;
    int i;
};
