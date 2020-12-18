#include <map>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    map<string, int> wordsFre = {
        {"a", 1},
        {"b", 2},
        {"c", 3}};

    auto bp = wordsFre.begin();

    for (; bp != wordsFre.end(); bp++)
    {
        cout << bp->first << " = " << bp->second << endl;
    }
    return 0;
}