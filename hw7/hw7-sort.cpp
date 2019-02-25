#include <iostream>
#include <stdlib.h>
#include <vector>
#include "elapsed_time.h"
using namespace std;

vector<int> initializeVec(int N)
{
    // initialize an array with random values
    vector<int> vec;
    for (auto it = 0; it < N; ++it)
        vec.emplace_back(rand() % 10000);
    return vec;
}

void printArray(vector<int> vec)
{
    for (auto it = vec.begin(); it != vec.end(); ++it)
        cout << " " << *it;
    cout << endl;
}

int findMax(vector<int> vec)
{
    int max = 0;
    for (auto it = vec.begin(); it != vec.end(); it++)
    {
        if (*it > max)
        {
            max = *it;
        }
    }
    return max;
}

vector<int> mySort(vector<int> vec, int N)
{
    int max = findMax(vec);
    vector<int> vec2;
    for (int i = 0; i <= max; i++)
    {
        vec2.emplace_back(0);
    }
    for (int i = 0; i < N; i++)
    {
        int x = vec.at(i);
        vec2.at(x)++;
    }
    vector<int> vec3;
    for (int i = 0; i < N; i++)
    {
        vec3.emplace_back(0);
    }

    int j = 0;
    for (int i = 0; i <= max; i++)
    {
        for (int k = 0; k < vec2.at(i); k++)
        {
            vec3.at(j) = i;
            j++;
        }
    }
    return vec3;
}

int main()
{
    const int N = 1000000;
    const bool verbose = false;
    const int num_tests=100;
    long double sum=0;
    for (int z = 0; z < num_tests; z++)
    {
        vector<int> vec = initializeVec(N);
        if (verbose)
        {
            cout << "Input: ";
            printArray(vec);
        }
        start_timer();
        vector<int> sorted = mySort(vec, N);
        double cycles = elapsed_time();
        if (verbose)
        {
            cout << "Sorted:";
            printArray(sorted);
        }
        sum+=cycles;
    }
    cout<<sum/num_tests<<"  N="<< N <<endl;
    return 0;
}