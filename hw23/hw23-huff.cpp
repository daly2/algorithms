// Danica Meier
// Michael Daly

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int asc;
    int freq;
    Node *left;
    Node *right;

  public:
    Node(int x, int f)
    {
        asc = x;
        freq = f;
    }
    Node(int x, int f, Node *l, Node *r)
    {
        asc = x;
        freq = f;
        left = l;
        right = r;
    }
};
struct Comp
{
    bool operator()(const Node *l, const Node *r)
    {
        return l->freq > r->freq;
    }
};

vector<int> frequency(string s)
{
    vector<int> v(129);
    v.at(128) = s.length();
    while (!s.empty())
    {
        int asc = (int)s.front();
        v.at(asc)++;
        s.erase(0, 1);
    }
    return v;
}
void Codes(Node *top, vector<vector<bool>> &codes, vector<bool> bin, bool lr)
{
    if (!top)
    {
        return;
    }
    bin.push_back(lr);
    if (top->asc != -1)
    {
        codes.at(top->asc) = bin;
    }
    else
    {
        Codes(top->right, codes, bin, 0);
        Codes(top->left, codes, bin, 1);
    }
}
void Codes(Node *top, vector<vector<bool>> &codes, vector<bool> bin)
{
    if (!top)
    {
        return;
    }
    if (top->asc != -1)
    {
        codes.at(top->asc) = bin;
    }
    else
    {
        Codes(top->right, codes, bin, 0);
        Codes(top->left, codes, bin, 1);
    }
}

vector<vector<bool>> huff(vector<int> freq)
{
    priority_queue<Node *, vector<Node *>, Comp> H;
    for (int i = 0; i < freq.size(); ++i)
    { // i is the ascii code
        if (freq.at(i) > 0)
        {
            Node *temp = new Node(i, freq.at(i));
            H.push(temp);
        }
    }
    Node *left, *right, *top;
    while (H.size() > 1)
    {
        left = H.top();
        H.pop();
        right = H.top();
        H.pop();

        Node *temp = new Node(-1, (left->freq + right->freq));
        temp->left = left;
        temp->right = right;
        H.push(temp);
    }
    vector<vector<bool>> codes(129);
    vector<bool> bin;
    Codes(H.top(), codes, bin);
    return codes;
    /*
    vector<Node> H; // priority queue of nodes
    for (int i = 0, l = freq.size(); i < l; i++)
    { // i = ascii code, freq.at(i) is freq
        if (freq.at(i) > 0) {
            Node n (i, freq.at(i));
            H.emplace_back(n);
        }
    }
*/

    /* 
    left = 
    right = 
    Node n (i, left, right);
     */
}

char decodeChar(vector<vector<bool>> codes, vector<bool> bin)
{
    for (int i = 0; i < codes.size(); ++i)
    {
        if (codes.at(i) == bin)
        {
            return (char)i;
        }
    }
    return (char)-1;
}

// return and pop min from queue
Node minFreq(vector<Node> &H)
{
    Node *min = &H.at(0);

    for (int i = 0, n = H.size(); i < n; i++)
    {
        int p = H.at(i).freq;
        if (p < min->freq && p > 0)
            min = &H.at(i);
    }
    Node ret = *min;
    min->freq = 0;
    return ret;
}

vector<bool> encode(const string s, vector<int> freq)
{
    vector<bool> bin;
    vector<vector<bool>> codes = huff(freq);
    for (int i = 0; i < s.length(); ++i)
    {
        char c = s.at(i);
        int stop = codes.at((int)c).size();
        for (int j = 0; j < stop; ++j)
        {
            bin.push_back(codes.at((int)c).at(j));
        }
    }
    return bin;
    // huff() - create set of codes
    // return vec<vec<bool>> codes
    // convert to codes
    // read in string char c
    // replace/output with codes[ascii(c)]
    // output
}

string decode(const vector<bool> bin, vector<int> freq)
{
    string decoded;
    vector<vector<bool>> codes = huff(freq);
    vector<bool> chbin;
    for (int i = 0; i < bin.size(); ++i)
    {
        chbin.push_back(bin.at(i));
        char c = decodeChar(codes, chbin);
        if (c > -1)
        {
            decoded += c;
            chbin.erase(chbin.begin(), chbin.end());
        }
    }
    decoded.append("");
    return decoded;
}

void printVec(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << ' ';
    cout << endl;
}

string get_file(const char *filename)
{
    ifstream in(filename, std::ios::in | std::ios::binary);
    if (in)
    {
        string contents;
        getline(in, contents, '\0');
        return contents;
    }
    return "whoopsie";
}

int main()
{
    // read in file
    string input = get_file("input.txt");

    vector<int> freq = frequency(input);
    vector<bool> output = encode(input, freq);
    //freq.at(128) = output.size();

    //output the encoded version, uses the chars for 1 and 0, should use binary
    ofstream out("output.txt");
    for (int i = 0; i < freq.size(); ++i)
    {
        out << freq.at(i) << endl;
    }
    for (auto it = output.begin(); it != output.end(); ++it)
    {
        out << (bool)*it;
    }
    out.close();
    cerr << "input: " << input.size() << endl;
    cerr << "output: " << output.size() << endl;
    cerr << "output/8: " << output.size() / 8 << endl;

    //read in the encoded version
    vector<bool> binary;
    ifstream in2("output.txt");
    vector<int> freq2(129);
    for (int i = 0; i < 129; ++i)
    { //read in freq, 0-127 is the ascii range, add 1 for the total number of bits
        in2 >> freq2.at(i);
    }
    char bin;
    while (in2)
    {
        in2 >> bin;
        if (bin == '0')
        {
            binary.push_back(false);
        }
        else
        {
            binary.push_back(true);
        }
    }

    string decoded = decode(binary, freq);
    //write out the decoded version
    ofstream out2("output2.txt");
    out2 << decoded;
    return 0;
}