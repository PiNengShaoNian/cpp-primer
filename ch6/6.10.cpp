#include <iostream>

using namespace std;

void exch(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 1;
    int b = 2;

    exch(&a, &b);

    cout << "a: " << a << " b: " << b;
    return 0;
}