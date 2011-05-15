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

////////////////////////////////////////////////////////////////////////////////
bool check(const vector<vector< pair<int, int> > > &g)
{
  // for (int i=0; i<(int)(g).size(); ++i) printp(g[i]);
  int n=(int)(g).size();
  vector<int> dis(n, INT_MAX);
  dis[n-1]=0;
  for (int i=0; i<n; ++i) 
    for (int j=0; j<(int)(g).size(); ++j) {
      if (dis[j]==INT_MAX) continue;
      for (int k=0; k<(int)(g[j]).size(); ++k) {
	int p=g[j][k].first;
	int w=g[j][k].second;
	if (dis[p]==INT_MAX || dis[p]>dis[j]+w) dis[p]=dis[j]+w;
	// cout<<j<<" "<<p<<" "<<w<<" "<<dis[p]<<endl;
	// print(dis);
      }
    }
  for (int i=0; i<(int)(g).size(); ++i) {
    if (dis[i]==INT_MAX) continue;
    for (int j=0; j<(int)(g[i]).size(); ++j) {
      int p=g[i][j].first;
      int w=g[i][j].second;
      if (dis[p]==INT_MAX || dis[p]>dis[i]+w) return true;
    }
  }
  return false;
}

int main()
{
  int F;
  cin>>F;
  for (int tt=0; tt<F; ++tt) {
    int n, m, w;
    cin>>n>>m>>w;
    vector< vector<int> > g(n, vector<int>(n, INT_MAX));
    for (int i=0; i<m; ++i) {
      int x, y, t;
      cin>>x>>y>>t;
      x--; y--;
      g[x][y]=g[y][x]=min(t, g[x][y]);
    }
    for (int i=0; i<w; ++i) {
      int x, y, t;
      cin>>x>>y>>t;
      x--; y--;
      t=-t;
      g[x][y]=min(g[x][y], t);
    }
    vector<vector<pair<int, int> > > a(n);
    for (int i=0; i<n; ++i) 
      for (int j=0; j<n; ++j) {
	if (g[i][j]==INT_MAX) continue;
	pair<int, int> x;
	x.first=j; x.second=g[i][j];
	a[i].push_back(x);
      }
    // for (int i=0; i<(int)(a).size(); ++i) a[i].push_back(make_pair(n, 0));
    vector< pair<int, int> > aux;
    for (int i=0; i<n; ++i) aux.push_back(make_pair(i, 0));
    a.push_back(aux);
    bool ok=check(a);
    cout<<(ok?"YES":"NO")<<endl;
  }
}
