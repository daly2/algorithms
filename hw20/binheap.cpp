#include <iostream>
#include "binheap.h"
using namespace std;

int main()
{
    bin_heap h;
    for (int j = 0; j < 4; ++j)
    {
        for (int i = 0; i < 6; ++i)
        {
            h.insert(i);
        }
    }
    for (int i = 0; h.arr.size() > 2; ++i)
    {
        cerr << h.del_min();
    }
}