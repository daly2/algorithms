#include <iostream>
#include <vector>
using namespace std;

class bin_heap
{
  public:
    vector<int> arr;

    bin_heap();

    void insert(int element);
    int del_min();
    void dec_key(int key, int val);
    void bubble(int i);
    int parent(int i) { return i / 2; }
    int left(int i) { return 2 * i; }
    int right(int i) { return 2 * i + 1; }
};

bin_heap::bin_heap(){
    arr.emplace_back(-66666666);
}
void bin_heap::insert(int element)
{
    arr.emplace_back(element);
    int i = arr.size()-1;
    while (i > 0 && element < arr.at(parent(i)))
    {
        int temp = arr.at(i);
        arr.at(i) = arr.at(parent(i));
        arr.at(parent(i)) = temp;
        i = parent(i);
    }
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
