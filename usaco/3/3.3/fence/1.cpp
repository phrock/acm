/*
  ID:   rock2to1
  LANG: C++
  PROG: fence
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

ifstream fin("fence.in");
ofstream fout("fence.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////

int g[501][501];
vector<int> res;

void dfs(int x)
{
  for (int i=1; i<=500; ++i) 
    if (g[i][x]) g[i][x]--, g[x][i]--, dfs(i);
  res.push_back(x);
}

int main()
{
  cin.rdbuf(fin.rdbuf());
  cout.rdbuf(fout.rdbuf());
  #ifdef DEBUG
  cin.rdbuf(cin_buf);
  cout.rdbuf(cout_buf);
  #endif
  //////////////////////////////////////////////////////////////////////////////

  memset(g, 0, sizeof(g));
  int n;
  cin>>n;
  int start=1000;
  for (int i=0; i<n; ++i) {
    int a, b;
    cin>>a>>b;
    g[a][b]++; g[b][a]++;
    start=min(start, a);
    start=min(start, b);
  }
  for (int i=1; i<=500; ++i) {
    int aux=0;
    for (int j=1; j<=500; ++j) aux+=g[i][j];
    if (aux%2) { start=i; break; }
  }
  dfs(start);
  reverse((res).begin(), (res).end());
  for (int i=0; i<(int)(res).size(); ++i) cout<<res[i]<<endl;
}
