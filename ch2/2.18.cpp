#include <iostream>

int main()
{
    int i = 666;
    int *p = &i;
    int i2 = 6666;

    *p = 665;

    p = &i2;

    std::cout << i << " " << *p << p << std::endl;
}