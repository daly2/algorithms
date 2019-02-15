#include <iostream>
#include "elapsed_time.h"
using namespace std;

int main(){
    int n=100;
start_timer();
for ( int i = 0; i <= n; ++i ) {
  for ( int j = 0; j <= i/2; ++j ) {
    i = i + 1;
  }
};
double cycles = elapsed_time();
cout<< "total cycles"<<cycles<<endl;

}