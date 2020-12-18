#include <iostream>

using namespace std;

struct Numbered
{
public:
    unsigned mysn;

    static unsigned id;
    Numbered() : mysn(id++) {}

    Numbered(Numbered &n) : mysn(id++){};

    Numbered &operator=(Numbered &n)
    {
        mysn = id++;

        return *this;
    };
};

void f1(Numbered n)
{
    cout << n.mysn << endl;
}

void f2(Numbered &n)
{
    cout << n.mysn << endl;
}

unsigned Numbered::id = 0;

int main()
{

    Numbered n1;
    Numbered n2 = n1;
    Numbered n3(n2);

    f2(n1);
    f2(n2);
    f2(n3);

    f1(n1);
    f1(n2);
    f1(n3);
}