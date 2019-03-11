#ifndef _Stack_
#define _Stack_
class Stack
{
  public:
    int *arr;
    int MaxSize;
    int index;
    Stack(int MaxSize)
    {
        this->arr = new int[MaxSize];
        this->MaxSize = MaxSize;
        this->index = 0;
    }
    ~Stack()
    {
        delete[] this->arr;
    }
    void push(int pull)
    {
        if (index <= MaxSize)
        {
            arr[index] = pull;
            index++;
        }
    }
    int pop()
    {
        if (index > 0)
        {
            index--;
            int pop = arr[index];
            return pop;
        }
        else
        {
            return -1;
        }
    }
};
#endif