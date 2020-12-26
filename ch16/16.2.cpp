#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Sales_data {
    string bookNo;
    double price;

    Sales_data(string no, double p) : bookNo(no), price(p){};
};

template <typename T>
int compare(const T& a, const T& b) {
    if (a == b)
        return 0;
    else if (a > b)
        return 1;
    else
        return -1;
}

template <typename InputIterator, typename T>
InputIterator find(InputIterator begin, InputIterator end, T val) {
    while (begin != end) {
        if (*begin == val) return begin;

        ++begin;
    }

    return end;
}

template <unsigned N, typename T>
void print(const T (&arr)[N]) {
    const T* p = begin(arr);
    for (int i = 0; i < N; ++i) {
        cout << *(p + i);
    }

    cout << endl;
}

template <unsigned N, typename T>
const T* begin1(const T (&arr)[N]) {
    const T* p = &arr[0];

    return p;
}

template <unsigned N, typename T>
const T* end1(const T (&arr)[N]) {
    const T* p = &arr[0];

    return p + N;
}

template <size_t size, typename T>
constexpr size_t size1(const T (&arr)[size]) {
    return size;
}

int main() {
    std::cout << compare("1", "2") << std::endl;
    std::cout << compare(1, 2) << std::endl;

    int a[3] = {1, 2, 3};
    print(a);

    int b[3] = {3, 4, 5};

    for (auto p = begin1(b); p != end1(b); p++) {
        cout << *p << endl;
    }

    cout << size1(a) << endl;
}
