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


vector<vector<int>> read(string filename);
void write_cyc(std::ostream & outfile, vector<int> output);
vector<int> dfs(vector<vector<int>> graph, int start, int end);
const vector<int> primes{3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
vector<int> product;

class Node
{
  public:
    int point;
    int prime;
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
            } /*
            else if (*path == it->at(1))
            {
                nextdoor.push_back(it->at(0));
            }*/
        }
    }
};
void explore(std::ostream & outfile, vector<Node> graph, int pos, int &count, vector<int> visited);

bool check_dup(int pro)
{
    for (int i = 0; i < product.size(); ++i)
    {
        if (product.at(i) == pro)
        {
            return true;
        }
    }
    product.emplace_back(pro);
    return false;
}

int main()
{
    vector<vector<int>> data = read("input.txt");
    vector<Node> nodes;
    for (int i = 0; i < data.at(0).at(0); ++i)
    {
        nodes.emplace_back(data, i);
    }
    for (int i = 0; i < nodes.size(); ++i)
    {
        nodes.at(i).prime = primes.at(i);
    }
    int count = 1;
    vector<int> visited;
    std::ofstream outfile("cycles.txt");
    for (int i = 0; i < nodes.size(); ++i)
    {
        explore(outfile, nodes, i, count, visited);
    }
    return 0;
}
int pro(const vector<int> visited, const vector<Node> g)
{
    int pro = 1;
    for (int i = 0; i < visited.size(); ++i)
    {
        pro *= g.at(visited.at(i)).prime;
    }
    return pro;
}
void explore(std::ostream & outfile, vector<Node> g, int pos, int &count, vector<int> visited)
{
    if (g.at(pos).visit)
    {
        int p = pro(visited, g);
        if (!check_dup(p))
        {
            write_cyc(outfile, visited);
        }
        return;
    }
    g.at(pos).visit = true;
    visited.emplace_back(pos);
    g.at(pos).pre = count;
    count++;
    if (!g.at(pos).nextdoor.size())
    {
        g.at(pos).post = count;
        count++;
        return;
    }
    for (auto it = g.at(pos).nextdoor.begin(); it != g.at(pos).nextdoor.end(); ++it)
    {
        explore(outfile, g, *it, count, visited);
    }
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
    infile.close();
    return input;
}

void write_cyc(std::ostream & outfile, const vector <int> visited)
{
    if(!outfile.good()){
        cout<<"whoopsie\n";
        return;
    }
    outfile << "cycles\n";
    for (int i = 0; i < visited.size() - 1; ++i)
    {
        outfile << visited.at(i) << "         " << visited.at(i + 1) << endl;
    }
    outfile << visited.at(visited.size() - 1) << "         " << visited.at(0) << endl;
}