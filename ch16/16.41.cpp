#include <iostream>

using namespace std;

template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(a + b) {
    return a + b;
}

int main() {
    long long ll = 3;
    cout << sum(1, 3.14) << endl;
    cout << sum(ll, 3.14) << endl;
}
