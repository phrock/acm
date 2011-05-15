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

#ifdef DEBUG
#include "/home/rock/program/topcoder/libs/debug.cpp"
#endif
////////////////////////////////////////////////////////////////////////////////

const int M=100;
int root[M+5];
int rank[M+5];

void initSet()
{
  for (int i=1; i<=M; ++i) root[i]=i, rank[i]=1;
}

int findRoot(int x)
{
  if (root[x]!=x) root[x]=findRoot(root[x]);
  return root[x];
}

void mergeDisjointSet(int a, int b)
{
  int ra=findRoot(a), rb=findRoot(b);
  if (rank[ra]>rank[rb]) root[rb]=ra, rank[ra]++;
  else root[ra]=rb, rank[rb]++;
}

int n;
int g[105][105];

int main()
{
  while (cin>>n) {
    for (int i=1; i<=n; ++i)
      for (int j=1; j<=n; ++j) cin>>g[i][j];
    initSet();
    vector<vector<int> > dis;
    for (int i=1; i<=n; ++i)
      for (int j=i+1; j<=n; ++j) {
	vector<int> tmp(3);
	tmp[0]=g[i][j]; tmp[1]=i; tmp[2]=j;
	dis.push_back(tmp);
      }
    sort((dis).begin(), (dis).end());
    int res=0;
    for (int i=0; i<(int)(dis).size(); ++i) 
      if (findRoot(dis[i][1])==findRoot(dis[i][2])) continue;
      else res+=dis[i][0], mergeDisjointSet(dis[i][1], dis[i][2]);
    cout<<res<<endl;
  }
}
