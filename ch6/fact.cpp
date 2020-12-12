#include "Chapter6.h"

int fact(int n)
{
    int result = 1;

    while (n)
    {
        result *= n;
        n--;
    }

    return result;
}