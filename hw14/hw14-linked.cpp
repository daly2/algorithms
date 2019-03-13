#include <iostream>
#include "elapsed_time.h"
using namespace std;

class Node
{
  public:
    int num;
    Node *nextdoor;
};
class Stack
{
  public:
    Node *first;
    int size;
    Stack(){
        size =0;
        first=NULL;
    }
    void push_back(int n)
    {
        this->size++;
        Node *temp = new Node;
        temp->num = n;
        if (this->first)
        {
            temp->nextdoor = this->first;
        }else{
            temp->nextdoor=NULL;
        }
        this->first = temp;
        if (this->size == 1)
        {
            first->nextdoor = NULL;
        }
        return;
    }
    int pop_back()
    {
        if (this->first == NULL)
        {
            this->size--;
            return -1;
        }
        this->size--;
        int n = first->num; //create the return value
        if (size)
        {
            Node *temp = first->nextdoor;
            //delete this->first;
            first = temp;
        }
        return n;
    }
    ~Stack()
    {
        for (; size > 1;)
        {
            int n = this->pop_back();
        }
    }
};

int main()
{
    int max = 20;
    int j = 0;
    cin >> max;
    start_timer();
    Stack s;
    s.first=NULL;
    for (int i = 0; i < max; ++i)
    {
        s.push_back(i);
    }
    double cycles = elapsed_time();
    cout << max << " <- num elements cycles-> " << cycles << endl;
    while (s.size)
    {
        j=s.pop_back();
    }
    return 0;
}