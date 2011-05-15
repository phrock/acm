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

int findRoot(int x, vector<int> &root)
{
  if (root[x]!=x) root[x]=findRoot(root[x], root);
  return root[x];
}

void makeUnion(int x, int y, vector<int> &root)
{
  root[findRoot(x, root)]=findRoot(y, root);
}

pair<int, vector<pair<int, pair<int, int> > > > kruscal(const vector<vector<pair<int, int> > > &g)
{
  int n=(int)(g).size();
  vector<int> root(n);
  for (int i=0; i<n; ++i) root[i]=i;
  vector<pair<int, pair<int, int> > > edge;
  for (int i=0; i<(int)(g).size(); ++i)
    for (int j=0; j<(int)(g[i]).size(); ++j)
      if (i<g[i][j].first) edge.push_back(make_pair(g[i][j].second, make_pair(i, g[i][j].first)));
  sort((edge).begin(), (edge).end());
  vector<pair<int, pair<int, int> > > res_edge;
  int res_mst=0;
  for (int i=0; i<(int)(edge).size(); ++i) {
    int x=edge[i].second.first, y=edge[i].second.second;
    if (findRoot(x, root)!=findRoot(y, root)) {
      res_edge.push_back(edge[i]);
      makeUnion(x, y, root);
      res_mst+=edge[i].first;
    }
  }

  return make_pair(res_mst, res_edge);
}

int func(vector<vector<pair<int, int> > > &g)
{
  pair<int, vector<pair<int, pair<int, int> > > > mst=kruscal(g);
  for (int i=0; i<(int)(mst.second).size(); ++i) {
    int x=mst.second[i].second.first, y=mst.second[i].second.second, w=mst.second[i].first;
    for (__typeof((g[x]).begin()) j=(g[x]).begin(); j!=(g[x]).end(); ++j)
      if (j->first==y) { g[x].erase(j); break; }
    for (__typeof((g[y]).begin()) j=(g[y]).begin(); j!=(g[y]).end(); ++j)
      if (j->first==x) { g[y].erase(j); break; }
    if (isConnected(g)) {
      pair<int, vector<pair<int, pair<int, int> > > > mst2=kruscal(g);
      if (mst.first==mst2.first) return -1;
    }
    g[x].push_back(make_pair(y, w));
    g[y].push_back(make_pair(x, w));
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
