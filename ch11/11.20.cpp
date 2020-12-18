#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<string> words = {"a", "b", "c", "d", "a", "b", "c", "a", "b", "a"};

    map<string, int> fre;

    for (int i = 0; i < words.size(); ++i)
    {
        auto ret = fre.insert(make_pair(words[i], 1));

        if (!ret.second)
        {
            ++ret.first->second;
        }
    }

    
    for (auto start = fre.begin(); start != fre.end(); start++)
    {
        cout << start->first << " = " << start->second << endl;
    }

    return 0;
}