#include <list>
#include <vector>
#include <iostream>
#include <assert.h>

using namespace std;

bool compare(list<int> &list, vector<int> &v)
{
    auto lbegin = list.begin();
    auto lend = list.end();
    auto vbegin = v.begin();
    auto vend = v.end();

    if (static_cast<unsigned>(list.size()) != static_cast<unsigned>(v.size()))
        return false;

    while (lbegin != lend && vbegin < vend)
    {
        if (*lbegin != *vbegin)
            return false;
        
        ++lbegin;
        ++vbegin;
    }

    return true;
}

int main()
{

    vector<int> v{1, 2, 3};
    list<int> li{1, 2, 3};
    list<int> li1{1, 2, 3, 4};

    assert(compare(li, v) == true);
    assert(compare(li1, v) == false);

    return 0;
}
