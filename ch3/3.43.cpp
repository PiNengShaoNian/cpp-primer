#include <iostream>

using namespace std;

int main()
{

    int ia[3][4] = {
        {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}};

    for (const auto &row : ia)
    {
        for (auto ele : row)
        {
            cout << ele << endl;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ia[i][j] << endl;
        }
    }

    for (int(*p)[4] = begin(ia); p != end(ia); p++)
    {
        for (int *q = begin(*p); q != end(*p); q++)
        {
            cout << *q << endl;
        }
    }
    return 0;
}