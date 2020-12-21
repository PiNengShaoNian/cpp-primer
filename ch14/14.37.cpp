#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IntCompare
{
public:
    IntCompare(int v) : val(v){};
    bool operator()(int v)
    {
        return val == v;
    }

private:
    int val;
};

int main()
{
    vector<int> vec = {1,
                       2,
                       3,
                       4,
                       5,
                       2,
                       1,
                       3,
                       2};

    int old = 2;
    int newValue = 666;
    auto compare = IntCompare(2);

    replace_if(vec.begin(), vec.end(), compare, newValue);

    for (int &v : vec)
    {
        cout << v << " " << endl;
    }

    return 0;
}