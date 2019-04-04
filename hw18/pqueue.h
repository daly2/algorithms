#ifndef _Node_
#define _Node_

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Node
{
  public:
    int point;
    vector<int> nextdoor;
    int pre;
    int post;
    Node(vector<vector<int>> graph, int pn)
    {
        point = pn;
        pre = post = 0;
        auto it = graph.begin();
        ++it;
        for (; it != graph.end(); ++it)
        {
            auto path = find(it->begin(), it->end(), point);
            if (*path == it->at(0))
            {
                nextdoor.push_back(it->at(1));
            }
            else if (*path == it->at(1))
            {
                nextdoor.push_back(it->at(0));
            }
        }
    }
};
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


#endif //_Node_ def