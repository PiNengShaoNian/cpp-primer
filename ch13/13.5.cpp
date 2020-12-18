#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(string &s = string("")) : ptr(new string(s)), i(0){};

    HasPtr(HasPtr &hp)
    {
        ptr = new string(*hp.ptr);
        i = hp.i;
    }

    HasPtr &operator=(HasPtr &hp)
    {
        ptr = new string(*hp.ptr);
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