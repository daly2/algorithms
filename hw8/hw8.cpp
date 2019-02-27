#include <iostream>
#include "math.h"
using namespace std;

void recursion(int n)
{

    for (int i = 0; i < 100; i++)
    {
        int x = sin(0.8 + 0.234);
    }

    if (n > 0)
    {
        recursion(n / 2);
        recursion(n / 2);
    }
}
int main()
{
    int n =100;
    recursion(n);
    return 0;
}