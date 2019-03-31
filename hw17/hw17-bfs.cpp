#include <iostream>
#include <queue>
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
    int dist;
    Node(vector<vector<int>> graph, int pn)
    {
        point = pn;
        dist = 0;
        auto it = graph.begin();
        ++it;
        for (; it != graph.end(); ++it)
        {
            auto path = find(it->begin(), it->end(), point);
            if (*path == it->at(0))
            {
                nextdoor.push_back(it->at(1));
            }/*
            else if (*path == it->at(1))
            {
                nextdoor.push_back(it->at(0));      //Extension for undirected graphs
            }*/
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
void bfs(vector<Node>& graph, Node *start){
    for(auto it=graph.begin(); it!=graph.end(); ++it){
        it->dist=-1;
    }
    start->dist=0;
    queue <Node*> Q;
    Q.emplace(start);
    while(!Q.empty()){
        start = Q.front();
        Q.pop();
        for(auto it =start->nextdoor.begin();it!=start->nextdoor.end(); ++it){
            if(graph.at(*it).dist==-1){
                Q.emplace(&graph.at(*it));
                graph.at(*it).dist=start->dist+1;
            }
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
    bfs(nodes, &nodes.at(0));
    for(auto it=nodes.begin(); it!=nodes.end(); ++it){
        cout<< it->point<< ' ' <<it->dist << endl;
    }
    return 0;
}
