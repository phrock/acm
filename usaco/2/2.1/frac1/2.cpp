/*
  ID:   rock2to1
  LANG: C++
  PROG: frac1
*/

#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

ifstream fin("frac1.in");
ofstream fout("frac1.out");
////////////////////////////////////////////////////////////////////////////////

int n;
vector<pair<int, int> > res;

void dfs(const pair<int, int> &a, const pair<int, int> &b)
{
  int x=a.first+b.first;
  int y=a.second+b.second;
  pair<int, int> next=make_pair(x, y);
  if (y<=n) {
    dfs(a, next);
    res.push_back(next);
    dfs(next, b);
  }
}

int main()
{
  fin>>n;
  res.push_back(make_pair(0, 1));
  dfs(make_pair(0, 1), make_pair(1, 1));
  res.push_back(make_pair(1, 1));
  for (int i=0; i<(int)(res).size(); ++i)
    fout<<res[i].first<<"/"<<res[i].second<<endl;
}
