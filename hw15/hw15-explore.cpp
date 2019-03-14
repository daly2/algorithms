#include <iostream>
#include <stack>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
using namespace std;
class Node
{
  public:
    int point;
    vector<int> nextdoor;
    int pre;
    int post;
    Node(vector<vector<int>> graph, int pn)
    {
        point = pn;
        pre = post = 0;
        auto it = graph.begin();
        ++it;
        for (; it != graph.end(); ++it)
        {
            auto path = find(it->begin(), it->end(), point);
            if (*path == it->at(0))
            {
                nextdoor.push_back(it->at(1));
            }
            else if (*path == it->at(1))
            {
                nextdoor.push_back(it->at(0));
            }
        }
    }
};
vector<vector<int>> read(string filename)
{
    char problem;
    string edges;
    int nvert, nedges;
    std::ifstream infile(filename);
    infile >> problem >> edges >> nvert >> nedges;
    vector<vector<int>> input(nedges + 1, vector<int>(2));
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

    return input;
}
void explore(vector<Node> &graph, Node *start, int &count)
{
    stack<Node *> s;
    s.push(start);
    while (!s.empty())
    {
        start = s.top();
        bool post = true;
        if (!start->pre)
        {
            start->pre = (count);
            (count)++;
            for (auto it = start->nextdoor.end() - 1; it != start->nextdoor.begin() - 1; --it)
            {
                if (!graph.at(*it).pre)
                {
                    s.push(&graph.at(*it));
                    post = false;
                }
            }
            if (post)
            {
                s.pop();
                start->post = (count);
                (count)++;
            }
        }
        else
        {
            if (!start->post)
            {
                start->post = (count);
                (count)++;
            }
            s.pop();
        }
    }
}
int main()
{
    vector<vector<int>> data = read("input.txt");
    vector<Node> nodes;
    for (int i = 0; i < data.at(0).at(0); ++i)
    {
        nodes.emplace_back(data, i);
    }
    int count = 1;
    for (auto it = nodes.begin(); it != nodes.end(); it++)
    {
        explore(nodes, &(*it), count);
        cout << it->point << " " << it->pre << " " << it->post << endl;
    }
    return 0;
}
