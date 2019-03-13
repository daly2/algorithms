#include <iostream>
#include "elapsed_time.h"
using namespace std;

class Stack
{
  public:
    int size;
    int index;
    int *arr;
    Stack(int sz = 100)
    {
        size = sz;
        arr = new int[size];
        index = 0;
    }
    void push_back(int thing)
    {
        if (index == size)
        {
            this->resize();
        }
        arr[index] = thing;
        index++;
    }
    int pop_back()
    {
        if (index > 0)
        {
            index--;
            return arr[index];
        }
        else
        {
            return -1;
        }
    }
    void resize()
    {
        size *= 2;
        int *temp = new int[size];
        for (int i = 0; i < size/2; i++)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        return;
    }
    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    int max = 20;
    int j = 0;
    cin >> max;
    Stack s(2);
    start_timer();

    for (int i = 0; i < max; i++)
    {
        s.push_back(i);
    }
    double cycles = elapsed_time();
    std::cout << max << " <- num elements cycles-> " << cycles << endl;
    for (; s.index;)
    {
        j = s.pop_back();
    }
}