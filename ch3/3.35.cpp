#include <array>;
#include <iostream>;
#include <vector>;

int main()
{
    int nums[3] = {1, 2, 3};

    auto start = std::begin(nums);
    auto end = std::end(nums);

    while (start != end)
    {
        *start = 0;
        start++;
    }

    int nums2[3] = {0, 0, 0};

    std::vector<int> a = {1, 2, 3};
    std::vector<int> b = {1, 2, 3};

    std::cout << (nums == nums2) << std::endl;
    std::cout << (a == b) << std::endl;

    std::cout << nums[0] << nums[1] << nums[2] << std::endl;
}