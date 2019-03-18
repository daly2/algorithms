//Danica Meier
//Johe Johnson
//Michael Daly
#include <iostream>
#include "bucket.h"
#include <algorithm>
#include <vector>
using namespace std;

bool found = false;

bool check_dup(node that, vector<node> &g)
{
    for (int i=0; i < g.size(); i++) {
        if (g.at(i) == that) {
            return true; // duplicate exists
        }
    }
    return false; // no duplicates
}

void explore(vector<node> &g, const node pos);

bool check(vector<node> &g, const node pos)
{
    if (pos.four.current == 2 || pos.seven.current == 2)
    {
        found = true;
        cout << pos.four.current << " " << pos.seven.current <<" "<< pos.ten.current << endl;
        return true;
    }
    if (!check_dup(pos, g))
    {
        g.push_back(pos);
        explore(g, pos);
    }
    return false;
}
void explore(vector<node> &g, const node pos)
{
    node npos = pos;
    npos.four.fill(npos.seven);
    if(check(g, npos) || found)
        return;
    npos = pos;
    npos.four.fill(npos.ten);
    if(check(g, npos) || found)
        return;
    npos = pos;
    npos.seven.fill(npos.ten);
    if(check(g, npos) || found)
        return;
    npos = pos;
    npos.seven.fill(npos.four);
    if(check(g, npos) || found)
        return;
    npos = pos;
    npos.ten.fill(npos.four);
    if(check(g, npos) || found)
        return;
    npos = pos;
    npos.ten.fill(npos.seven);
    if(check(g, npos) || found)
        return;
}
int main()
{
    vector<node> g;
    node start;
    g.emplace_back(start);
    explore(g, g.at(0));
    if(!found){
        cout<< "no solution\n";
    }
    return 0;
}