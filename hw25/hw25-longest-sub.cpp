#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
typedef pair<int, int> ipair;
struct Comp
{
    bool operator()(const ipair l, const ipair r)
    {
        return l.first < r.first;
    }
};

vector<int> read_in(string filename)
{
    ifstream in(filename);
    vector<int> numbers;
    int i;
    while (in.good())
    {
        in >> i;
        numbers.push_back(i);
    }
    in.close();
    return numbers;
}

vector<int> longest_sub(const vector<int> nums)
{
    vector<ipair> prev; //first is weight, second is prev
    ipair last;
    last.first = 1;
    last.second = 0;

    ipair max;
    max.first = 0; //first is weight,second is index
    max.second = 0;

    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = 0; j < i; j++)
        {
            if (prev.at(j).first >= last.first-1 && nums.at(j) < nums.at(i))
            {
                last.first = prev.at(j).first + 1;
                last.second = j;
            }
        }
        if(0==i){
            last.first=1;
            last.second=0;
        }
        if (last.first > max.first)
        {
            max.first = last.first;
            max.second=i;
        }
        prev.push_back(last);
        last.first = 1;
        last.second = 0;
        //find max of prev
        //add last to prev
    }
    vector <int> trace(max.first);
    int index=max.second;
    for(int k=max.first-1; k>=0; --k){
        trace.at(k)=nums.at(index);
        index=prev.at(index).second;
    }
    return trace;
    /*
    for(int i=0; index>=0;++i){
        trace.push_back(nums.at(index))
    }*/
    //add -1 as the prev for index 0
    //find max val in weight, traceback the pointers
    //create a vector of the traceback
    //return traceback
}
void print_vec(vector<int> p)
{
    for (int i = 0; i < p.size(); ++i)
    {
        cout << p.at(i) << ' ';
    }
    cout << endl;
}

int main()
{
    vector<int> num = read_in("input.txt");
    print_vec(longest_sub(num));
    return 0;
}