#ifndef __bin_heap__
#define __bin_heap__
#include <iostream>
#include <vector>
using namespace std;

vector<int> initializeVec(int N)
{
    // initialize an array with random values
    vector<int> vec;
    for (auto it = 0; it < N; ++it)
        vec.emplace_back(rand() % 100);
    return vec;
}

void printArray(vector<int> vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
        cout << " " << *it;
    cout << endl;
}
class bin_heap
{
  public:
    vector<int> arr;

    bin_heap();
    bin_heap(int size);

    void insert(int element);
    int del_min();
    void dec_key(int key, int val);
    void bubble(int i);
    int parent(int i) { return i / 2; }
    int left(int i) { return 2 * i; }
    int right(int i) { return 2 * i + 1; }
    vector <int> sort();
};

bin_heap::bin_heap(int size)
{
    arr = initializeVec(size + 1);

    arr.at(0) = INT32_MIN;
    printArray(arr);
    // for(int i=0; i<size; i++){
    //     insert(i);
    // }
    int i = arr.size()-1;
    if (i % 2 == 0)
    {
        if (arr.at(i) < arr.at(parent(i)))
        {
            int temp = arr.at(i);
            arr.at(i) = arr.at(parent(i));
            arr.at(parent(i)) = temp;
            i--;
        }
    }
    for (; i >= 1; i -= 2)
    {
        if (arr.at(i) < arr.at(i - 1))
        {
            if (arr.at(i) < arr.at(parent(i)))
            {
                int temp = arr.at(i);
                arr.at(i) = arr.at(parent(i));
                arr.at(parent(i)) = temp;
                bubble(i);
            }
        }
        else if (arr.at(i - 1) < arr.at(parent(i - 1)))
        {
            int temp = arr.at(i - 1);
            arr.at(i - 1) = arr.at(parent(i - 1));
            arr.at(parent(i - 1)) = temp;
            bubble(i-1);
        }
        printArray(arr);
        cout<<i<<' ' << endl;
    }
    printArray(arr);
}
bin_heap::bin_heap()
{
    arr.emplace_back(-66666666);
}
void bin_heap::insert(int element)
{
    arr.emplace_back(element);
    int i = arr.size() - 1;
    while (i > 0 && element < arr.at(parent(i)))
    {
        int temp = arr.at(i);
        arr.at(i) = arr.at(parent(i));
        arr.at(parent(i)) = temp;
        i = parent(i);
    }
}
vector<int>bin_heap::sort(){
    vector <int> old = arr;
    vector <int> ret;
    while(arr.size()>1){
        ret.emplace_back(this->del_min());
    }
    arr=old;
    return ret;
}

int bin_heap::del_min()
{
    int min = arr.at(1);
    arr.at(1) = arr.back();
    arr.pop_back();
    bubble(1);
    return min;
}

void bin_heap::dec_key(int key, int val)
{
}
void bin_heap::bubble(int i)
{
    if (right(i) < arr.size() && arr.at(left(i)) < arr.at(i) && arr.at(right(i)) > arr.at(left(i)) || left(i) < arr.size() && right(i) > arr.size() && arr.at(left(i)) < arr.at(i))
    {
        int temp = arr.at(i);
        arr.at(i) = arr.at(left(i));
        arr.at(left(i)) = temp;
        bubble(left(i));
    }
    else if (right(i) < arr.size() && arr.at(right(i)) < arr.at(i))
    {
        int temp = arr.at(i);
        arr.at(i) = arr.at(right(i));
        arr.at(right(i)) = temp;
        bubble(right(i));
    }
}

#endif //__bin_heap__