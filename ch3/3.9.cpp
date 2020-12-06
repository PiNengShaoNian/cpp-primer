#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    string result;

    cin >> result;

    for (decltype(result.size()) i = 0; i < result.size(); i++)
    {
        char &c = result[i];
        c = 'X';
    }

    decltype(result.size()) n = result.size();
    while (n)
    {
        n--;
        char &c = result[n];
        c = 'O';
    }

    cout
        << result << std::endl;
    return 0;
}