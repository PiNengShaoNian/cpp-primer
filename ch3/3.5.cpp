#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string result;
    string word;
    while (cin >> word)

    {
        result += " " + word;

        /* code */
    }

    cout
        << result << std::endl;
    return 0;
}