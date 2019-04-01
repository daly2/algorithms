#include <iostream>
#include <algorithm>
#include <vector>
#include "bucket5.h"
#include <queue>
using namespace std;

bool found = false;
bool check_dup(Node that, vector<Node> &g)
{
    for (int i = 0; i < g.size(); i++)
    {
        if (g.at(i) == that)
        {
            return true; // duplicate exists
        }
    }
    return false; // no duplicates
}

bool check(const Node pos)
{
    if (pos.buck.at(2).current == 4
        && pos.buck.at(3).current == 4
        && pos.buck.at(4).current ==4)
    {
        found = true;
        cout << pos.buck.at(0).current
        << " " << pos.buck.at(1).current 
        <<" "<< pos.buck.at(2).current
        << " " << pos.buck.at(3).current 
        << " " << pos.buck.at(4).current
        <<" depth of: " << pos.dist <<endl;
        return true;
    }
    return false;
}


bool disc( Node & see,  vector <Node> & did_see){
    for(auto it =did_see.begin(); it!=did_see.end(); ++it){
        if(*it==see){
            return true;
        }
    }
    return false;
}
void bfs(vector<Node> &graph, Node start)
{
    start.dist = 0;
    int gs=graph.size();
    queue<Node> Q;
    Q.emplace(start);
    int qs=Q.size();
    while (!Q.empty())
    {
        start = (Q.front());
        Q.pop();
        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                Node tem=start;
                Node* temp=&tem;
                temp->buck.at(i).fill(temp->buck.at(j));
                if(!(disc(*temp, graph))){
                    temp->dist=start.dist+1;
                    graph.emplace_back(*temp);
                    Q.emplace(*temp);
                    if(check(*temp)){
                        return;
                    }
                    qs=Q.size();
                    gs=graph.size();
                }
            }
        }
    }
}
int main()
{
    vector<Node> g;
    Node start;
    g.emplace_back(start);
    bfs(g, g.at(0));
    if (!found)
    {
        cout << "no solution\n";
        cout << g.size() << " attempts\n";
    }else{
        cerr<< "found\n";
    }
    return 0;
}