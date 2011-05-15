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

int findAugmentingPath(vector<vector<int> > &g, int source, int dest)
{
  int n=(int)(g).size();
  vector<int> from(n, -1);
  queue<int> q;
  q.push(source);
  while (!q.empty()) {
    int cur=q.front();
    q.pop();
    if (cur==dest) break;
    for (int next=0; next<n; ++next)
      if (next!=source && from[next]==-1 && g[cur][next]) from[next]=cur, q.push(next);
  }
  int cur=dest;
  int res=INT_MAX;
  while (from[cur]!=-1) res=min(res, g[from[cur]][cur]), cur=from[cur];
  cur=dest;
  while (from[cur]!=-1) g[from[cur]][cur]-=res, g[cur][from[cur]]+=res, cur=from[cur];
  return res==INT_MAX?0:res;
}

int maxFlow(const vector<vector<int> > &g, int source, int dest)
{
  vector<vector<int> > residual=g; // residual graph for original graph
  int res=0, cap=0;
  while ((cap=findAugmentingPath(residual, source, dest))>0) res+=cap;
  return res;
}

int main()
{
  int m, n;
  while (cin>>m>>n) {
    vector<vector<int> > g(n, vector<int>(n));
    for (int i=0; i<m; ++i) {
      int x, y, c;
      cin>>x>>y>>c;
      g[x-1][y-1]+=c;
    }
    cout<<maxFlow(g, 0, n-1)<<endl;
  }
}
