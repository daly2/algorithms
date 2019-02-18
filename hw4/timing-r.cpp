#include <iostream>
using namespace std;
#include "elapsed_time.h"
void recursion(int n)
{
    double x = 2 * 3;
    x = x * 3;
    if (n > 0)
    {
        recursion(n / 2);
        recursion(n / 2);
    }
}
int main()
{
    int n = 100;
    start_timer();
    recursion(n);
    double cycles = elapsed_time();
    cout << "num cycles: " << cycles << "\n";
}