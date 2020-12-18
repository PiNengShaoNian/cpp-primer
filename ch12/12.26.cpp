#include <string>
#include <memory>
#include <iostream>

using namespace std;

char *append(const string &a, const string &b)
{
    string c = a + b;

    allocator<char> alloc;
    char *p = alloc.allocate(c.size());

    for (int i = 0; i < c.size(); ++i)
    {
        p[i] = c[i];
    }

    return p;
}

int main()
{
    auto p = append("sdfsdf", "66666");

    cout << p[6] << endl;
}