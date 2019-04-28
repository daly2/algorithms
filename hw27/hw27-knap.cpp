// a Michael Daly production
// knapsack without repitition
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int cap; //width
vector<vector<int>> table;
vector<int> weight; //.size=height of table
vector<int> value;

void printTable()
{
    for (int i = 0; i < table.size(); i++)
    {
        for (int j = 0; j < table.at(i).size(); j++)
        {
            cout << table.at(i).at(j) << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> initTable()
{ //a is i, b is j
    vector<vector<int>> tab(weight.size() + 1);
    for (int i = 0; i < weight.size(); ++i) // allocate the space for the vec
    {
        tab.at(i).resize(cap + 2);
        // cout << "\t "
    }
    for (int i = 0; i < weight.size(); ++i) // fill in the first column
    {
        tab.at(i).at(0) = i;
    }
    for (int j = 0; j < cap + 1; ++j) // fill in the first row
    {
        tab.at(0).at(j + 1) = j;
    }
    return tab;
}

void knap()
{
    for (int i = 1; i < table.size(); ++i)
    { //i goes through the items
        for (int j = 2; j < table.at(i).size(); ++j)
        { //j goes through capacity
            if (j < weight.at(i))
            {
                table.at(i).at(j) = table.at(i - 1).at(j - 1);
            }
            else
            {
                table.at(i).at(j)=max(value.at(i)+table.at(i-1).at(j-weight.at(i)), table.at(i-1).at(j));
            }
        }
    }
}

int main()
{
    cap = 10;
    weight = {2, 1, 4, 5, 6};
    value = {4, 3, 7, 9, 11};
    table = initTable();
    knap();
    printTable();
    return 0;
}
/*
I recived different answers because for the book problems I allowed repitions, but here I did not
*/