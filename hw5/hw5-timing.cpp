#include <iostream>
using namespace std;
#include "elapsed_time.h"
void recursion(int n)
{
    double x = 2 * 3;
    x = x * 3;

    if (n > 0)
    {
        recursion(n / 3);
        recursion(n / 3);
        recursion(n / 3);
        recursion(n / 3);
    }
}
void recursion2(int n)
{
    double x = 2 * 3;
    x = x * 3;

    if (n > 0)
    {
        recursion(n / 3);
        recursion(n / 3);
        recursion(n / 3);
    }
}

int main()
{
    int n = 100;
    start_timer();
    recursion(n);
    double cycles = elapsed_time();
    cout << "num cycles: " << cycles << "\n";
    cycles=0;
    start_timer();
    recursion2(n);
    cycles=elapsed_time();
    cout << "num2 cycles: " << cycles << "\n";
    return 0;
}