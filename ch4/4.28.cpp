#include <iostream>
#include <string>

using namespace std;

int main()
{

    cout << sizeof(int) << " int" << endl;
    cout << sizeof(double) << " double" << endl;
    cout << sizeof(string) << " string" << endl;
    cout << sizeof(long long) << " long long" << endl;
    cout << sizeof(long double) << " long double" << endl;
    cout << sizeof(int[5]) << " long double" << endl;
    cout << sizeof(string[5]) << " long double" << endl;
    cout << sizeof(int *) << " int *" << endl;
    cout << sizeof(double *) << " double *" << endl;
    cout << (0.1 + 0.2) << " double *" << endl;

    return 0;
}