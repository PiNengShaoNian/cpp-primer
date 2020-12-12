#include <string>

using namespace std;
using StringArr = string[10];

string (*foo())[10]
{
    string res[10];
    return &res;
}

auto bar() -> string (*)[10]
{
    string res[10];
    return &res;
}

StringArr *bzz()
{
    string res[10];
    return &res;
}