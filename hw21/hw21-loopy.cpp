#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

//  reads in dimacs format from input.txt
//  outputs cycles into cycles.txt in the form of edges with a start and edge node
//  individual cycles are seperated by the word "cycles"
vector<vector<int>> product;
class Node
{
  public:
    int point;
    vector<int> nextdoor;
    int pre;
    int post;
    bool visit;
    Node(vector<vector<int>> graph, int pn)
    {
        point = pn;
        pre = post = 0;
        visit = false;
        auto it = graph.begin();
        ++it;
        for (; it != graph.end(); ++it)
        {
            auto path = find(it->begin(), it->end(), point);
            if (*path == it->at(0))
            {
                nextdoor.push_back(it->at(1));
            }
        }
    }
};
vector<vector<int>> read(string filename)
{
    int nvert, nedges;
    std::ifstream infile(filename);
    infile >> nvert >> nedges;
    vector<vector<int>> input(nedges + 2, vector<int>(2));
    input.at(0).at(0) = nvert;
    input.at(0).at(1) = nedges;
    int i = 1;
    int c = 0;
    while (infile.good())
    {
        infile >> c;
        input.at(i).at(0) = c;
        infile >> c;
        input.at(i).at(1) = c;
        i++;
    }
    infile.close();
    return input;
}
vector<int> sort(const vector<int> arr)
{
    vector<int> arr2;
    int val = arr.at(0);
    int index = 0;
    for (int min = 0; min < arr.size(); min++)
    {
        if (arr.at(min) < val)
        {
            index = min;
            val = arr.at(min);
        }
    }
    for (int i = 0; i < arr.size(); ++i)
    {
        arr2.emplace_back(arr.at(index));
        index++;
        if (index == arr.size())
        {
            index = 0;
        }
    }
    return arr2;
}

bool check(const int ipos, const vector<int> nextdoor)
{
    for (int i = 0; i < nextdoor.size(); ++i)
    {
        if (ipos == nextdoor.at(i))
        {
            return true;
        }
    }
    return false;
}

void check_dup(vector<int> pro)
{
    for (int i = 0; i < product.size(); ++i)
    {
        if (product.at(i) == pro)
        {
            return;
        }
    }
    product.emplace_back(pro);
    return;
}
void explore(vector<Node> g, int pos, vector<int> visited, const int start)
{
    if (!g.at(pos).visit)
    {
        g.at(pos).visit = true;
        visited.emplace_back(pos);
    }
    else
    {
        return;
    }
    if (check(start, g.at(pos).nextdoor))
    {
        vector<int> p = sort(visited);
        check_dup(p);
    }
    for (auto it = g.at(pos).nextdoor.begin(); it != g.at(pos).nextdoor.end(); ++it)
    {
        explore(g, *it, visited, start);
    }
    return;
}

int main()
{
    vector<vector<int>> data = read("input.txt");
    vector<Node> nodes;
    for (int i = 0; i < data.at(0).at(0); ++i)
    {
        nodes.emplace_back(data, i);
    }
    vector<int> visited;
    for (int i = 0; i < nodes.size(); ++i)
    {
        explore(nodes, i, visited, i);
    }
    cout << product.size() << endl;
    return 0;
}