#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::vector;

int main()
{
    cout << "plase enter numbers"
         << std::endl;
    vector<int> nums;
    int number = 0;
    while (cin >> number)
    {
        nums.push_back(number);
    }

    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        cout << nums[i] + nums[j] << std::endl;
        i++;
        j--;
    }

    return 0;
}
