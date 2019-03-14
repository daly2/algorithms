#include <iostream>
using namespace std;

class queue{
    int capacity;
    int back;
    int * arr;
    public:
    queue(int max){
        capacity = max;
        back = 0;
        arr = new int [capacity];
    }
    void inject(int val){
        if(back==capacity){
            cout<< "Bad!!\n";
            return;
        }else{
            arr[back]=val;
            back++;
        }
    }
    int eject(){
        if(!back){
            cout << "Bad!\n";
            return -1;
        }else{
            int val = arr[0];
            for(int i=1; i<back; i++){
                arr[i-1]=arr[i];
            }
            back--;
            return val;
        }
    }
};
int main(){
    int size = 0;
    cin>> size;
    queue q(size);
    for(int i = 0; i< size; ++i){
        q.inject(i);
    }
    for(int i=0; i<size; ++i){
        cout<< q.eject()<<" ";
    }
    cout << endl;
    return 0;
}