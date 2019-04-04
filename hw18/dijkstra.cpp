#include <iostream>
#include <vector>
#define inf 32767
// #include <iterator>
// #include <algorithm>
//#include "pqueue.h"

using namespace std;

typedef pair<int, int> ipair;

// class Node
// {
//   public:
//     int point;
//     vector<ipair> nextdoor;//first is neibour num, second is edge len
//     Node * prev;
//     int dist;
//     Node(vector<vector<ipair>> graph, int pn)
//     {
//         point = pn;
//         prev = NULL;
//         auto it = graph.begin();
//         //++it; for skipping the first line
//         for (; it != graph.end(); ++it)
//         {
//             auto path = find(it->begin(), it->end(), point);
//             if (*path == it->at(0))
//             {
//                 nextdoor.push_back(it->at(1));
//             }
//             else if (*path == it->at(1))
//             {
//                 nextdoor.push_back(it->at(0));
//             }
//         }
//     }
// };

class pqueue
{
  public:
    //int v;
    vector<ipair> ls; //store index in graph and distance guess
    ipair delMin()
    {
        ipair min = ls.at(0);
        auto minptr = ls.begin();
        for (auto it = ls.begin(); it != ls.end(); ++it)
        {
            if (it->second < min.second)
            {
                min = *it;
                minptr = it;
            }
        }
        ls.erase(minptr);
        return min;
    }
    void decKey(const ipair update)
    {
        for (auto it = ls.begin(); it != ls.end(); ++it)
        {
            if (it->first == update.first)
            {
                if (it->second > update.first)
                {
                    *it = update;
                    return;
                }
            }
        }
        cerr << " node not found \n";
    }
    void insert(ipair add)
    {
        ls.push_back(add);

    }
    int getval(int key)
    {
        for (auto it = ls.begin(); it != ls.end(); ++it)
        {
            if (it->first == key)
            {
                return it->second;
            }
        }
    }
    bool empty() { return ls.empty(); }
};
/*
vector<ipair> dij(vector<Node> &g, int start)
{
    pqueue H;
    for (int i = 0; i < g.size(); ++i)
    {
        ipair temp;
        temp.first = i;
        temp.second = inf;
        H.insert(temp);
        g.at(i).prev = NULL;
    }
    ipair st;
    st.first = start;
    st.second = 0;
    H.decKey(st);
    while (!H.ls.empty())
    {
        ipair u = H.delMin();
        Node *curr = &g.at(u.first);
        for (int i = 0; i < curr->nextdoor.size(); ++i)
        {
            Node* future = &g.at(curr->nextdoor.at(i).first);
            ipair temp;
            temp.first = future->point;
            temp.second = curr->dist + curr->nextdoor.at(i).second;
            if (H.getval(temp.first)>temp.second){
                future->dist=temp.second;
                future->prev=curr;
                H.decKey(temp);
            }
        }
    }
}
*/
// void dij2(graph & g, )

struct Graph
{
    int vert;
    vector<int> dist;
    vector<int> prev;
    vector<vector<int>> edges;
    Graph(vector<vector<int>> e)
    {
        vert = e.size();
        for (int i = 0; i < vert; ++i)
        {
            dist.emplace_back(inf);
        }
        edges = e;
        prev.resize(vert, 0);
    }
};

void dij2(Graph &g, int start)
{
    pqueue Q;
    for (int i = 0; i < g.vert; ++i)
    {
        ipair temp;
        temp.first = i;
        temp.second = inf;
        Q.insert(temp);
    }
    ipair st;
    st.first = start;
    st.second = 0;
    Q.decKey(st);
    g.dist.at(start)=0;
    while (!Q.empty())
    {
        ipair u = Q.delMin();
        for (int i = 0; i < g.vert; ++i)
        {
            if (g.edges.at(u.first).at(i))
            {
                int v = i;
                int l = g.edges.at(u.first).at(i);
                if (g.dist.at(v) > g.dist.at(u.first) + l)
                {
                    g.dist.at(v) = g.dist.at(u.first) + l;
                    g.prev.at(v) = u.first;
                    ipair temp;
                    temp.first = v;
                    temp.second = g.dist.at(u.first) + l;
                    Q.decKey(temp);
                }
            }
        }
    }
}

int main()
{
    int numV = 5;
    vector<vector<int>> e(5);
    for (int i = 0; i < numV; i++)
    {
        for (int j = 0; j < numV; ++j)
        {

            e.at(i).emplace_back(i+1*j);
        }
    }
    Graph g(e);
    dij2(g, 0);
    for(int i=0;i<numV; ++i){
        cout<< "node "<< i << " is at distance: " << g.dist.at(i) << " and has parent: " << g.prev.at(i) <<endl;
    }
    return 0;
}