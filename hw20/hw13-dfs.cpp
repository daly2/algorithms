#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
using namespace std;

vector<vector<int>> read(string filename);
void write(string filename, vector<vector<int>> output);
vector<int> dfs(vector<vector<int>> graph, int start, int end);

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
        auto it=graph.begin();
        ++it;
        for (;it!=graph.end();++it)
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
void explore(vector<Node> *graph, Node *pos, int *count);

int main()
{
    vector<vector<int>> data = read("input.txt");
    vector<Node> nodes;
    for (int i = 0; i < data.at(0).at(0); ++i)
    {
        nodes.emplace_back(data, i);
    }
    //vector<Node> path = dfs(nodes, 3, 7);
    int *count;
    *count = 1;
    vector<Node> *nenodes = &nodes;
    explore(nenodes, &nodes.at(0), count);

    for (auto it = nodes.begin(); it != nodes.end(); it++)
    {
        explore(nenodes, &(*it), count);
        cout << it->point << " " << it->pre << " " << it->post << endl;
    }
    return 0;
}
/*
vector<Node> dfs(vector<Node> nodes, int start, int end)
{
    int count = 1;
    vector<Node> route;
    route.push_back(nodes.at(start));
    route.back().pre = count;
    count++;
    while (true)
    {
        for (auto p = route.back().nextdoor.begin(); p != route.back().nextdoor.begin(); p++)
        {
            if (!nodes.at(*p).)
            {
                p->pre = count;
                count++;
            }
        }
    }
    
    while(!route.empty()){
        Node p = route.back();
        //route.pop_back();
        if(!p.pre){
            p.pre=count;
            count++;
            for(auto &n:p.nextdoor){
                if()
            }
        }

    }
    
    return route;
}*/

void explore(vector<Node> *graph, Node *pos, int *count)
{
    if(pos->visit) return;
    pos->visit = true;
    pos->pre = *count;
    (*count)++;
    if(pos->nextdoor.size()==0){
        pos->post=*count;
        return;
    }
    for (auto it = pos->nextdoor.begin(); it != pos->nextdoor.end(); ++it)
    {
        if (!graph->at(*it).visit)
        {
            explore(graph, &graph->at(*it), count);
        }
    }
    pos->post = *count;
    (*count)++;
    return;
}

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

void write(string filename, vector<vector<int>> output)
{
    std::ofstream outfile(filename);
    outfile << "p edge ";
    for (auto const &value : output)
    {
        if (value == output.at(0))
        {
            outfile << value.at(0) << " " << value.at(1) << endl;
            continue;
        }
        outfile << value.at(0) << "         " << value.at(1);
        if (value != output.back())
        {
            outfile << endl;
        }
    }
}