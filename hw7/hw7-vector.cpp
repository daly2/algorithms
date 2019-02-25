#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v;
    int num_z = rand()%1000;
    for(int i = 0; i<num_z; i++){
        v.emplace_back(0);
    }
    for(auto it = v.begin(); it!=v.end(); it++){
        cout<<*it;
    }
    cout<<endl;
    return 0;
}