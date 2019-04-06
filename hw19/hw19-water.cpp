#include <iostream>
#include "bucket.h"
#include <algorithm>
#include <vector>
using namespace std;

bool found = false;

bool check_dup(node that, vector<node> &g)
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

void explore(vector<node> g, const node pos, int sofar, int max_cost);

bool check(vector<node> &g, const node pos, int cost, int max_cost)
{
    if(cost>max_cost){return false;}
    if (pos.four.current == 2 || pos.seven.current == 2)
    {
        found = true;
        cout << pos.four.current << " " << pos.seven.current << " " << pos.ten.current << endl;
        for(auto it =g.begin(); it!=g.end(); ++it){
            cout << "state: " << it->four.current << " " << it->seven.current << ' ' << it->ten.current << endl;
        }
        cout << cost<<endl;
        return true;
    }
    if (!check_dup(pos, g))
    {
        g.push_back(pos);
        explore(g, pos, cost, max_cost);
    }
    return false;
}
void explore(vector<node> g, const node pos, int sofar, int max_cost)
{
    node npos = pos;
    int cost =0;
    cost = npos.four.fill(npos.seven);
    if (check(g, npos, sofar+cost, max_cost) || found)
        return;
    npos = pos;
    cost=npos.four.fill(npos.ten);
    if (check(g, npos, sofar+cost, max_cost) || found)
        return;
    npos = pos;
    cost = npos.seven.fill(npos.ten);
    if (check(g, npos, sofar+cost, max_cost) || found)
        return;
    npos = pos;
    cost= npos.seven.fill(npos.four);
    if (check(g, npos, sofar+cost, max_cost) || found)
        return;
    npos = pos;
    cost=npos.ten.fill(npos.four);
    if (check(g, npos, sofar+cost, max_cost) || found)
        return;
    npos = pos;
    cost = npos.ten.fill(npos.seven);
    if (check(g, npos, sofar+cost, max_cost) || found)
        return;
}
int main()
{
    vector<node> g;
    node start;
    g.emplace_back(start);
    for (int max_cost = 0; !found && max_cost < 1000; ++max_cost)
    {
        explore(g, g.at(0), 0, max_cost);
    }
    if (!found)
    {
        cout << "no solution\n";
    }
    return 0;
}