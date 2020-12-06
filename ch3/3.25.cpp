#include <iostream>
#include <vector>
#include <string>
using std::cin;
using std::cout;
using std::string;
using std::vector;

int main()
{
    cout << "plase enter numbers"
         << std::endl;
    vector<int> nums(11, 0);
    int number = 0;
    while (cin >> number)
    {
        if (number > 100 || number < 0)
            continue;
        auto it = nums.begin() + number / 10;
        (*it)++;
    }

    auto i = nums.begin();
    auto j = nums.begin() + nums.size() - 1;

    for (int count : nums)
    {
        cout << ' ' << count;
    }

    return 0;
}
