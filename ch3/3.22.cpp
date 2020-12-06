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
    vector<string> nums;
    string str;
    while (cin >> str)
    {
        nums.push_back(str);
    }

    for (auto i = nums.begin(); i != nums.end(); i++)
    {
        if (!i->empty())
        {
            char &first = i->at(0);
            first = toupper(first);
        }
    }

    for (string word : nums)
    {
        cout << word << std::endl;
    }

    return 0;
}
