#include <unordered_map>
#include <iostream>
#include <functional>

using namespace std;

int operations(int a, int b, const char op)
{
    unordered_map<char, function<int(int, int)>> binOperations = {
        {'+', [](int a, int b) { return a + b; }},
        {'-', [](int a, int b) { return a - b; }},
        {'*', [](int a, int b) { return a * b; }},
        {'/', [](int a, int b) { return a / b; }},
        {'%', [](int a, int b) { return a % b; }}};

    return binOperations[op](a, b);
}

int main()
{

    cout << operations(1, 2, '+') << operations(1, 2, '-') << operations(1, 2, '*') << operations(1, 2, '/') << endl;
    return 0;
}