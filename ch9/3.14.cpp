#include <list>
#include <vector>
#include <string>
#include <assert.h>
#include <iostream>

using namespace std;

list<string> vectorToList(vector<char *> &v, list<string> &l)
{
    l.assign(v.begin(), v.end());

    return l;
}

int main()
{
    vector<char *> v = {"1sf",
                        "sdf"};
    list<string> l;

    vectorToList(v, l);

    cout << l.size() << endl;

    return 0;
}