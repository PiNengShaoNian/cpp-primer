#include <iostream>

using namespace std;

template <typename T>
void print(ostream& os, T t) {
    cout << t << endl;
}

template <typename T, typename... Args>
void print(ostream& os, T t, Args... rest) {
    os << t << endl;

    print(os, rest...);
}

int main() {
    long long a = 1;
    double b = 3.14;
    unsigned c = 999;
    long long* d = &a;
    char e = 'e';

    print(cout, a, b, c, d, e);
    return 0;
}