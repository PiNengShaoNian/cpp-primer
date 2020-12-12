#include <vector>

using namespace std;

int main()
{

    int nums[10];
    vector<int> v1(begin(nums), end(nums));
    auto a = nums;
    return 0;
}