#include <iostream>

int main()
{
    unsigned u = 10, u2 = 42;

    std::cout << u2 - u << " expected value: 32" << std::endl;         // 32
    std::cout << u - u2 << " expected value: 4294967264" << std::endl; //4294967264

    int i1 = 10, i2 = 42;

    std::cout << i1 - i2 << " expected value: -32" << std::endl; // 32
    std::cout << i2 - i1 << " expected value: 32" << std::endl;  // 32

    std::cout << i1 - u << " expected value: 0" << std::endl; // 32
    std::cout << u - i1 << " expected value: 0" << std::endl; // 32
}