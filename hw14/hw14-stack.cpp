#include <iostream>
#include <stack>
#include "elapsed_time.h"
using namespace std;

int main()
{
    int max = 20;
    int j = 0;
    cin >> max;
    start_timer();
    stack<int> s;
    for (int i = 0; i < max; ++i)
    {
        s.emplace(i);
    }
    double cycles = elapsed_time();
    std::cout << max << " <- num elements cycles-> " << cycles << endl;
    /*
    for (; !s.empty();)
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    */
    return 0;
}