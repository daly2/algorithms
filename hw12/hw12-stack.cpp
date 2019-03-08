#include <iostream>
using namespace std;

class Stack{
    public:
    int * arr;
    int MaxSize;
    int index;
    Stack(int MaxSize){
        this->arr= new int[MaxSize];
        this->MaxSize=MaxSize;
        this->index= 0;
    }
    ~Stack(){
        delete [] this->arr;
    }
    void push(int pull){
        arr[index]=pull;
        index++;
    }
    int pop(){
        index--;
        int pop=arr[index];
        return pop;
    }
};

int main(){
    Stack s(7);
    //cout<<s.MaxSize <<endl;
    for(int i=0; i<3; i++){
        s.push(i);
    }
    cout<< s.index<<endl;
    for(int i=0; i<3; i++){
        cout<<s.pop()<<endl;
    }
    return 0;
}