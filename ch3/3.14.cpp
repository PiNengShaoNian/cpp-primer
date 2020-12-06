#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
    int number = 0;
    vector<int> numbers = {};

    while (cin >> number)
    {
        /* code */
        numbers.push_back(number);
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << std::endl;
    }

    return 0;
}