#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class StringLens
{
public:
    StringLens(string::size_type l) : len(l){};

    bool operator()(string &s)
    {
        return s.size() == len;
    }

private:
    string::size_type len;
};

int main()
{
    vector<string> res;
    string word;
    StringLens compare(3);
    while (cin >> word)
    {
        if (compare(word))
        {
            res.push_back(word);
        }
    }

    for (string &s : res)
    {
        cout << s << " ";
    }

    return 0;
}
