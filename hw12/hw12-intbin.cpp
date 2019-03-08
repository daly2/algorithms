#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ctime>
using namespace std;

vector<int> initializeVec(int N)
{
    // initialize an array with random values
    vector<int> vec;
    for (auto it = 0; it < N; ++it)
        vec.emplace_back(rand() % 10);
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

int bin_search(vector<int> *sorted, int num, int N)
{
    int left = 0;
    int right = N;
    int middle = 0;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (sorted->at(middle) < num)
        {
            left = middle + 1;
        }
        else if (sorted->at(middle) > num)
        {
            right = middle-1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}

const bool verbose = true;
int main()
{
    srand(time(NULL));
    const int N = 100;
    int num = rand() % 10;
    vector<int> vec = initializeVec(N);
    if (verbose)
    {
        cout << "Input: ";
        printArray(vec);
    }

    vector<int> sorted = mySort(vec, N);
    int index = bin_search(&sorted, num, N);
    cout << index << " " << num << endl;

    if (verbose)
    {
        cout << "Sorted:";
        printArray(sorted);
    }
    return 0;
}