#include <string>

using namespace std;

class HasPtr
{
public:
    HasPtr(string &s = string("")) : ptr(new string(s)), i(0), use(new unsigned(1)){};

    HasPtr(HasPtr &hp)
    {
        ptr = hp.ptr;
        use = hp.use;
        *hp.use++;
        i = hp.i;
    }

    HasPtr &operator=(HasPtr &hp)
    {
        if (--use == 0)
        {
            delete use;
            delete ptr;
        }
        *hp.use++;
        ptr = hp.ptr;
        i = hp.i;
        use = hp.use;
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
    string *ptr;
    int i;
    unsigned *use;
};
