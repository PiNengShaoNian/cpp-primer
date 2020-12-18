#include <iostream>

int main()
{
    auto sum = [](int a, int b) {
        return a + b;
    };

    std::cout << sum(1, 5) << std::endl;

    return 0;
}