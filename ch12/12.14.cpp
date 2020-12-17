#include <memory>
#include <iostream>

using namespace std;

void deletePointer(int *p)
{
    delete p;
}

int main()
{
    int *p = new int(12);
    int *p3 = new int(12);

    shared_ptr<int> p2(p, deletePointer);
    shared_ptr<int> p4(p3, [](int *p) { delete p; });

    cout << *p2 * 2 << endl;
}