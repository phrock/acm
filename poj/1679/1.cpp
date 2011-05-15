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

bool isConnected(const vector<vector<pair<int, int> > > &g)
{
  int n=(int)(g).size();
  vector<int> v(n);
  v[0]=1;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int x=q.front();
    q.pop();
    for (int i=0; i<(int)(g[x]).size(); ++i)
      if (!v[g[x][i].first]) q.push(g[x][i].first), v[g[x][i].first]=1;
  }
  if (accumulate((v).begin(), (v).end(), 0)<n) return false;
  else return true;
}

pair<int, vector<pair<int, int> > > prim(const vector<vector<pair<int, int> > > &g)
{
  const int M=INT_MAX/2;
  int n=(int)(g).size();
  vector<int> dist(n, M);
  dist[0]=0;
  vector<int> back(n);
  back[0]=-1;
  set<pair<int, int> > st;
  st.insert(make_pair(0, 0));
  vector<int> visited(n);
  while (!st.empty()) {
    pair<int, int> top=*st.begin();
    st.erase(st.begin());
    int v=top.second;
    if (visited[v]) continue;
    visited[v]=1;
    for (int i=0; i<(int)(g[v]).size(); ++i) {
      int v2=g[v][i].first, cost=g[v][i].second;
      if (visited[v2]) continue;
      if (cost<dist[v2]) {
	if (dist[v2]!=M) st.erase(make_pair(dist[v2], v2));
	st.insert(make_pair(cost, v2));
	dist[v2]=cost;
	back[v2]=v;
      }
    }
  }
  vector<pair<int, int> > edge;
  int mst=0;
  for (int i=0; i<n; ++i)
    if (back[i]!=-1) edge.push_back(make_pair(i, back[i])), mst+=dist[i];
  return make_pair(mst, edge);
}
int func(const vector<vector<pair<int, int> > > &g)
{
  pair<int, vector<pair<int, int> > > mst=prim(g);
  for (int i=0; i<(int)(mst.second).size(); ++i) {
    int x=mst.second[i].first, y=mst.second[i].second;
    vector<vector<pair<int, int> > > g2=g;
    g2[x].clear(); g2[y].clear();
    for (int j=0; j<(int)(g[x]).size(); ++j)
      if (g[x][j].first!=y) g2[x].push_back(g[x][j]);
    for (int j=0; j<(int)(g[y]).size(); ++j)
      if (g[y][j].first!=x) g2[y].push_back(g[x][j]);
    if (isConnected(g2)) {
      pair<int, vector<pair<int, int> > > mst2=prim(g2);
      if (mst.first==mst2.first) return -1;
    }
  }
  return mst.first;
}

int main()
{
  int k;
  cin>>k;
  for (int i=0; i<k; ++i) {
    int n, e;
    cin>>n>>e;
    vector<vector<pair<int, int> > > g(n);
    for (int j=0; j<e; ++j) {
      int a, b, w;
      cin>>a>>b>>w;
      a--, b--;
      g[a].push_back(make_pair(b, w));
      g[b].push_back(make_pair(a, w));
    }
    int res=func(g);
    if (res==-1) cout<<"Not Unique!"<<endl;
    else cout<<res<<endl;
  }
}
