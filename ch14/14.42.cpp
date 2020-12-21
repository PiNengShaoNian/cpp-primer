#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string>

using namespace std;

int main()
{

    std::vector<int> vec = {1, 2, 3, 4, 1024, 1025, 1077};
    vector<string> vec2 = {"pooh", "pooh", "666"};

    int res = count_if(vec.begin(), vec.end(), bind(greater<int>(), placeholders::_1, 1024));

    auto res1 = find_if(vec2.begin(), vec2.end(), bind(not_equal_to<string>(), placeholders::_1, "pooh"));

    cout << res << endl;
    cout << *res1 << endl;
    return 0;
}