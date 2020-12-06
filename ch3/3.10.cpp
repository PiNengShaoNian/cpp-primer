#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string result;

    cin >> result;

    for (auto &c : result)
    {
        if (ispunct(c))
        {
            c = ' ';
        }
    }
    cout
        << result << std::endl;
    return 0;
}