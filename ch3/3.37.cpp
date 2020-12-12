#include <iostream>
#include <string>

using std::cout;
using std::string;

int main()
{

    char ca[] = "hello";

    char *p = ca;

    while (*p)
    {
        cout << *p << std::endl;
        p++;
    }

    return 0;
}