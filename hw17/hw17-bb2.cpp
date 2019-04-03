#include <iostream>
#include <algorithm>
#include <vector>
#include "bucket5.h"
#include <queue>
#include <unordered_map>
using namespace std;

bool found = false;
bool check_dup(Node that, unordered_map<Node, Node> &g)
{
    std::unordered_map<Node, Node>::const_iterator got = g.find(that);
    if (got == g.end())
    {
        return false; // no duplicates
    }
    return true;
}

bool check(const Node pos)
{
    if (pos.buck.at(2).current == 4 && pos.buck.at(3).current == 4 && pos.buck.at(4).current == 47)
    {
        found = true;
        cout << pos.buck.at(0).current
             << " " << pos.buck.at(1).current
             << " " << pos.buck.at(2).current
             << " " << pos.buck.at(3).current
             << " " << pos.buck.at(4).current
             << " depth of: " << pos.dist << endl;
        return true;
    }
    return false;
}

bool disc(Node &see, std::unordered_map<Node, Node> &did_see)
{

    std::unordered_map<Node, Node>::const_iterator got = did_see.find(see);
    if (got == did_see.end())
    {
        return true; // no duplicates
    }
    return false;
}

void bfs(unordered_map<Node, Node> &graph, Node start)
{
    start.dist = 0;
    int gs = graph.size();
    queue<Node> Q;
    Q.emplace(start);
    int qs = Q.size();
    while (!Q.empty())
    {
        start = (Q.front());
        Q.pop();
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                Node tem = start;
                Node *temp = &tem;
                temp->buck.at(i).fill(temp->buck.at(j));
                if (!(disc(*temp, graph)))
                {
                    temp->dist = start.dist + 1;
                    graph.emplace(*temp);
                    Q.emplace(*temp);
                    if (check(*temp))
                    {
                        return;
                    }
                    qs = Q.size();
                    gs = graph.size();
                }
            }
        }
    }
}
int main()
{
    Node start;
    std::unordered_map<Node, Node> g;
    g[start]=start;
    bfs(g, start);
    if (!found)
    {
        cout << "no solution\n";
        cout << g.size() << " attempts\n";
    }
    else
    {
        cerr << "found\n";
    }
    return 0;
}