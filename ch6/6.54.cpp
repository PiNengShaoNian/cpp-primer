#include <vector>
#include <iostream>
using namespace std;
int sum(int a, int b)
{
    return a + b;
}

int main()
{

    vector<int (*)(int, int)> func;

    func.push_back(sum);

    cout << func[0](1, 2) << endl;
    return 0;
}