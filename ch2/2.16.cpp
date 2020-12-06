#include <iostream>
int main()
{
    int i = 0, &r1 = i;
    double d = 3.14, &r2 = d;

    i = 666;
    r1 = 6666;

    std::cout << r1 << " " << i << std::endl;
}