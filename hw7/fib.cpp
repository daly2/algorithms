#include <iostream>
using namespace std;

int fib(int a)
{
    if(a<=1)return a;
    else{
        return fib(a-1)+fib(a-2);
    }
}
int main()
{
    int a = 0;
    cin >> a;
    if (a > 0)
        cout << fib(a);
    return 0;
}