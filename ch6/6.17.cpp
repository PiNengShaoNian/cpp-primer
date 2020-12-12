#include <iostream>
#include <string>

using namespace std;

bool hasUpperCase(const string &s)
{
    bool result = false;

    for (auto &c : s)
    {
        if (c >= 'A' && c <= 'Z')
        {
            result = true;
            break;
        }
    }

    return result;
}

void toUpperCase(string &s)
{
    for (auto &c : s)
    {
        c = toupper(c);
    }
}

int main()
{

    string a = "Abc";
    string b = "abc";
    char *argv[] = {};

    cout << hasUpperCase(a) << " " << hasUpperCase(b) << endl;

    return 0;
}
