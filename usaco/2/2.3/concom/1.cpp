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
int res[101][101];
int v[101];

void control(int x)
{
  set<int> st;
  st.insert(x);
  while (true) {
    bool update=false;
    memset(v, 0, sizeof(v));
    for (__typeof((st).begin()) i=(st).begin(); i!=(st).end(); ++i)
      for (int j=1; j<=100; ++j) v[j]+=g[*i][j];
    for (int i=1; i<=100; ++i)
      if (v[i]>50 && !((st).find(i)!=(st).end())) { update=true; st.insert(i); }
    if (!update) break;
  }
  for (__typeof((st).begin()) i=(st).begin(); i!=(st).end(); ++i) res[x][*i]=1;
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
  for (int i=1; i<=100; ++i) control(i);
  for (int i=1; i<=100; ++i)
    for (int j=1; j<=100; ++j)
      if (i!=j && res[i][j]) fout<<i<<" "<<j<<endl;
  // print2(res, 6, 6);
}
