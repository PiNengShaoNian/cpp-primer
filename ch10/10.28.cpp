#include <deque>
#include <iostream>
#include <array>
#include <string>

using namespace std;

string dequeToString(const deque<int> &queue)
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
    deque<int> queue1;
    deque<int> queue2;
    deque<int> queue3;

    const array<int, 5> arr = {1,
                               2,
                               3,
                               4,
                               5};

    copy(arr.begin(), arr.end(), back_inserter(queue1));
    copy(arr.begin(), arr.end(), front_inserter(queue2));
    copy(arr.begin(), arr.end(), inserter(queue3, queue3.begin()));

    cout << dequeToString(queue1) << " " << dequeToString(queue2) << " " << dequeToString(queue3) << endl;
}