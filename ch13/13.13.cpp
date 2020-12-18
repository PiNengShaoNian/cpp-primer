#include <iostream>

using namespace std;

struct X
{

    X()
    {
        cout << "X()" << endl;
    }

    X(X &)
    {
        cout << "X(X &)" << endl;
    };

    X &operator=(X &x)
    {
        cout << "X &operator=(X &x)" << endl;
        return *this;
    };

    ~X()
    {
        cout << "~X()" << endl;
    }
};

void foo(X x1, X &x2)
{
}

int main()
{
    X x1;
    X x2 = x1;
    foo(x1, x2);
}
