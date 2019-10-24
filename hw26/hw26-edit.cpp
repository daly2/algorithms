// Danica Meier
// Mike Daly
// Guannan Liu
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string a, b;
vector<vector<int> > table;
int n, m;

string greedy();

int diff(int i, int j) { return !(a.at(i - 1) == b.at(j - 1)); }

int edit_dist_1() {
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      int x = min(table.at(i - 1).at(j) + 1, table.at(i).at(j - 1) + 1);
      x = min(x, table.at(i - 1).at(j - 1) + diff(i, j));
      table.at(i).at(j) = x;
    }
  }
  return table.at(n - 1).at(m - 1);
}

int edit_dist_2()  // where substitute is half cost of insert/delete
{
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      int x = min(table.at(i - 1).at(j) + 2, table.at(i).at(j - 1) + 2);
      x = min(x, table.at(i - 1).at(j - 1) + diff(i, j));
      table.at(i).at(j) = x;
    }
  }
  return table.at(n - 1).at(m - 1);
}  // doesn't change -- substitution price always lower than insert/delete

// substitution has infinite cost
string edit_dist_3() {
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      int x = min(table.at(i - 1).at(j) + 1, table.at(i).at(j - 1) + 1);
      x = min(x, table.at(i - 1).at(j - 1) + (diff(i, j) * n * m));
      table.at(i).at(j) = x;
    }
  }
  return greedy();
}

string greedy() {
  int curr = 1;
  int i = n - 1, j = m - 1;
  int left, up, corner;
  string sub;
  while (i > 0 && j > 0) {
    if (a.at(i - 1) == b.at(j - 1)) {
      sub += a.at(i - 1);
    }
    curr = table.at(i).at(j);

    left = table.at(i - 1).at(j);
    up = table.at(i).at(j - 1);
    corner = table.at(i - 1).at(j - 1);

    if (left < up) {
      if (left < corner)
        i--;
      else {
        j--;
        i--;
      }
    } else if (up < corner)
      j--;
    else {
      j--;
      i--;
    }
  }
  reverse(sub.begin(), sub.end());
  return sub;
}

void printTable() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << table.at(i).at(j) << " ";
    }
    cout << endl;
  }
}

vector<vector<int> > initTable() {  // a is i, b is j
  vector<vector<int> > tab(n);
  for (int i = 0; i < n; ++i)  // allocate the space for the vec
  {
    tab.at(i).resize(m);
    // cout << "\t "
  }
  for (int i = 0; i < n; ++i)  // fill in the first column
  {
    tab.at(i).at(0) = i;
  }
  for (int j = 0; j < m; ++j)  // fill in the first row
  {
    tab.at(0).at(j) = j;
  }
  return tab;
}

int main() {
  cin >> a >> b;

  n = a.length() + 1;
  m = b.length() + 1;

  table = initTable();

  cout << "string a: " << a << endl;
  cout << "string b: " << b << endl;
  cout << "longest common subsequence: " << edit_dist_3() << endl;
  cout << endl;
  printTable();
  cout << endl;

  return 0;
}