#include <iostream>
using namespace std;
#include <vector>
#include <string>
void printArray(vector<string> *vec)
{
    for (auto it = vec->begin(); it != vec->end(); ++it)
        cout << " " << *it;
    cout << endl;
}
int bin_search(vector<string> *sorted, string * word)
{
    int left = 0;
    int right = sorted->size();
    int middle = 0;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (int(sorted->at(middle).at(0)) < word->at(0))
        {
            left = middle + 1;
        }
        else if (int(sorted->at(middle).at(0)) > word->at(0))
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
    const int N = 100;
    vector<string> sorted={"apple","bat","cat","dog", "ear", "fear", "gear", "hear"
                            "isle", "jeer", "kept", "lee", "me", "nope", "open", "peer"
                            "quiet", "rear", "steer", "tear", "up", "vector", "went",
                            "xa", "yes", "zee"};
    string word ="zpple";
    if (verbose)
    {
        cout << "Input: ";
        printArray(&sorted);
    }
    int index = bin_search(&sorted, &word);
    cout << index << " " << word << endl;
    return 0;
}