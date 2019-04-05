#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> ipair;

class bin_heap
{
  public:
    vector<ipair> arr;

    bin_heap();

    void insert(ipair element);
    ipair del_min();
    void dec_key(ipair keyval);
    void bubble(int i);
    int parent(int i) { return i / 2; }
    int left(int i) { return 2 * i; }
    int right(int i) { return 2 * i + 1; }
};

bin_heap::bin_heap()
{
    ipair temp;
    temp.first = temp.second = -666666666;
    arr.emplace_back(temp);
}
void bin_heap::insert(ipair element)
{
    arr.emplace_back(element);
    int i = arr.size() - 1;
    while (i > 0 && element < arr.at(parent(i)))
    {
        ipair temp = arr.at(i);
        arr.at(i) = arr.at(parent(i));
        arr.at(parent(i)) = temp;
        i = parent(i);
    }
}

ipair bin_heap::del_min()
{
    ipair min = arr.at(1);
    arr.at(1) = arr.back();
    arr.pop_back();
    bubble(1);
    return min;
}

void bin_heap::dec_key(ipair)
{
}
void bin_heap::bubble(int i)
{
    if (right(i) < arr.size() && arr.at(left(i)).second < arr.at(i).second && arr.at(right(i)).second > arr.at(left(i)).second || left(i) < arr.size() && right(i) > arr.size() && arr.at(left(i)).second < arr.at(i).second)
    {
        ipair temp = arr.at(i);
        arr.at(i) = arr.at(left(i));
        arr.at(left(i)) = temp;
        bubble(left(i));
    }
    else if (right(i) < arr.size() && arr.at(right(i)).second < arr.at(i).second)
    {
        ipair temp = arr.at(i);
        arr.at(i) = arr.at(right(i));
        arr.at(right(i)) = temp;
        bubble(right(i));
    }
}
