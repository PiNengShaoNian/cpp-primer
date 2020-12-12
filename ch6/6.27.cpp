#include <iostream>

using namespace std;

int *arr()
{
    int a[2] = {1, 2};
    return a;
}

int sum(initializer_list<int> nums)
{
    int result = 0;

    auto l = nums.begin();
    auto r = nums.end();

    while (l != r)
    {
        result += *l;
        l++;
    }

    return result;
}

int main()
{
    int a[2] = {1, 2};

    cout
        << sum({1, 2, 3}) << endl;

    cout
        << "a: " << *a << endl;
    return 0;
}