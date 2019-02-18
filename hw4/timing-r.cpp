#include <iostream>
using namespace std;
#include "elapsed_time.h"

int main()
{

    start_timer();
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
    double cycles = elapsed_time();
    cout << "num cycles: " << cycles << "\n";
}