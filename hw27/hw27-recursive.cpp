#include <iostream>
using namespace std;

long fake_fib(long n){
    if(n<=0){
        return 0;
    }
    else
    {
        int sum=fake_fib(n-2);
        sum+=fake_fib(n-4);
        sum+=fake_fib(n-6);
        return n+sum;
    }
}

int main(){
    int n=100;
    cout << fake_fib(n) <<endl;
    return 0;
}