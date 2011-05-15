/*
  ID:   rock2to1
  LANG: C++
  PROG: concom
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

ifstream fin("concom.in");
ofstream fout("concom.out");
////////////////////////////////////////////////////////////////////////////////
int g[101][101];
int res[101];
int v[101];

void dfs(int x)
{
  v[x]=1;
  for (int i=1; i<=100; ++i) res[i]+=g[x][i];
  for (int i=1; i<=100; ++i) if (res[i]>50 && !v[i]) dfs(i);
}

int main()
{
  int n;
  fin>>n;
  for (int i=0; i<n; ++i) {
    int a, b, x;
    fin>>a>>b>>x;
    g[a][b]=x;
  }
  for (int i=1; i<=100; ++i) {
    memset(v, 0, sizeof(v));
    memset(res, 0, sizeof(res));
    dfs(i);
    for (int j=1; j<=100; ++j)
      if (i!=j && res[j]>50) fout<<i<<" "<<j<<endl;
  }
  // print2(res, 6, 6);
}
