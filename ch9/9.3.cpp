#include <iostream>
#include <assert.h>
#include <vector>

using namespace std;

bool find(vector<int>::const_iterator begin, vector<int>::const_iterator end, int target)
{
    bool result = false;
    while (begin != end)
    {
        if (*begin == target)
        {
            result = true;
            break;
        }
        ++begin;
    }

    return result;
}

int main()
{
    const vector<int> nums = {1, 2, 3, 4, 5};
    assert(find(
               nums.cbegin(), nums.cend(), 3) == true);
    assert(find(nums.cbegin(), nums.cend(), 6) == false);
    return 0;
}