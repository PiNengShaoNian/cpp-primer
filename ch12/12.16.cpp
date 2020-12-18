#include <memory>

using namespace std;

int main()
{

    unique_ptr<int> p(new int(10));

    unique_ptr<int> p2;

    // p2 = p;

    return 0;
}