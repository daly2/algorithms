#include <iostream>
using namespace std;

class pqueue
{
  public:
    int *arr;
    int size;
    int maxsize;
    void insert(int el)
    {
        if (size < maxsize)
        {
            arr[size] = el;
            size += 1;
        }
        else
        {
            int nemax = maxsize * 2;
            int *narr = new int[nemax];
            for (int i = 0; i < maxsize; ++i)
            {
                narr[i] = arr[i];
            }
            delete[] arr;
            arr = narr;
            insert(el);
        }
    }                                               //insert new element
    void decKey(int ke, int val) { arr[ke] = val; } //decrease key values of a certian element
    int del_min()
    {
        int min, index = 0;
        for (int i = 0; i < size; ++i)
        {
            if (arr[i] < min && arr[i] > 0)
            {
                min = arr[i];
                index = i;
            }
        }
        for (int i = index; i < size; ++i)
        {
            arr[i - 1] = arr[i];
        }
        arr[size-1]=-1;
        size -= 1;
        return index;
    } //returns smallest key, and deletes it
    pqueue(int sz)
    {
        size = sz;
        maxsize = size + 1 * 2;
        arr = new int[maxsize];
        for (int i = 0; i < size; ++i)
        {
            arr[i] = -1;
        }

    } //make a pqueue of given elements, with given key values
};

int main()
{
    pqueue bar(10);
    return 0;
}