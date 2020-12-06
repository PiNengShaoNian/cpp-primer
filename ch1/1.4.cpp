#include <iostream>

int main()
{
    std::cout << "请输入两个数" << std::endl;

    int v1, v2;
    std::cin >> v1 >> v2;
    int result = v2 * v1; //3423432

    
    std::cout << v1 << "*" << v2 << "=" << result << std::endl;

    return 0;
}