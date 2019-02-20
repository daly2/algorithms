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
int main()
{
    int n = 100;
    start_timer();
    recursion(n);
    double cycles = elapsed_time();
    cout << "num cycles: " << cycles << "\n";
    n = 100;
    int x=0;
    cycles = elapsed_time();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            for (int k = 0; k < j; ++k)
            {
                x = x + 5;
            }
        }
    }

    cycles = elapsed_time() - cycles;
    cout << "num2 cycles: " << cycles << "\n";
    return 0;
}