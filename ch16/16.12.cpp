#include <iostream>

#include "blob.h"

using namespace std;

int main() {
    Blob<string> b{"0", "1", "2"};

    cout << b[1] << endl;
}