#include <vector>
#include <iostream>

using namespace std;

vector<int> *push1(vector<int> *v)
{
    v->push_back(1);

    return v;
}

vector<int> *pop(vector<int> *v)
{
    v->pop_back();

    return v;
}

int main()
{
    auto v = new vector<int>({1});

    push1(v);
    pop(v);

    cout << v->size() << endl;

    delete v;
}