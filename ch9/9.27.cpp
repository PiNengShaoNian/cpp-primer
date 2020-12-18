#include <forward_list>
#include <iostream>
#include <string>

using namespace std;

void deleteOdd(forward_list<int> &list)
{
    auto prev = list.before_begin();
    auto end = list.end();
    auto cur = list.begin();
    while (cur != end)
    {
        if (*cur % 2)
        {
            cur = list.erase_after(prev);
        }
        else
        {
            ++prev;
            ++cur;
        }
    }
}

void printList(forward_list<int> &list)
{
    string result;

    for (auto &e : list)
    {
        result.push_back(static_cast<char>(e));
        result.push_back('-');
        result.push_back('>');
    }

    cout << result << endl;
}

int main()
{

    forward_list<int> nums = {1,
                              2,
                              3,
                              4,
                              5};

    deleteOdd(nums);
    printList(nums);
    return 0;
}
