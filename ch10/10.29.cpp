#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

string vectorToString(const vector<int> &queue)
{
    string result;

    for (const &num : queue)
    {
        result += to_string(num) + "->";
    }

    return result;
}

int main()
{
    istream_iterator<int> b(cin), e;

    vector<int> nums;

    while (b != e)
    {
        nums.push_back(*b++);
    }

    sort(nums.begin(), nums.end());

    cout << vectorToString(nums) << endl;
}