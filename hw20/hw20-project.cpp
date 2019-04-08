//Danica Meier
//Michael Daly
/*although both merge sort and heap sort are nlogn,
merge sort ends up being much faster in practice*/

#include <iostream>
#include "binheap.h"
#include <vector>

int main(){
    bin_heap hp(20);
    vector <int> sorted =hp.sort();
    printArray(sorted);
    
    return 0;
}