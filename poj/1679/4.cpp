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

const int M=INT_MAX/2;
int n;
int g[5000][5000];

bool isConnected()
{
  vector<int> v(n);
  v[0]=1;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int x=q.front();
    q.pop();
    for (int i=0; i<n; ++i)
      if (g[x][i]!=M && !v[i]) q.push(i), v[i]=1;
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

pair<int, vector<pair<int, int> > > kruscal()
{
  vector<int> root(n);
  for (int i=0; i<n; ++i) root[i]=i;
  vector<pair<int, pair<int, int> > > edge;
  for (int i=0; i<n; ++i)
    for (int j=i+1; j<n; ++j)
      if (g[i][j]!=M) edge.push_back(make_pair(g[i][j], make_pair(i, j)));
  sort((edge).begin(), (edge).end());
  vector<pair<int, int> > res_edge;
  int res_mst=0;
  for (int i=0; i<(int)(edge).size(); ++i) {
    int x=edge[i].second.first, y=edge[i].second.second;
    if (findRoot(x, root)!=findRoot(y, root)) {
      res_edge.push_back(make_pair(x, y));
      makeUnion(x, y, root);
      res_mst+=edge[i].first;
    }
  }
  return make_pair(res_mst, res_edge);
}

int func()
{
  pair<int, vector<pair<int, int> > > mst=kruscal();
  for (int i=0; i<(int)(mst.second).size(); ++i) {
    int x=mst.second[i].first, y=mst.second[i].second, w=g[x][y];
    g[x][y]=g[y][x]=M;
    if (isConnected()) {
      pair<int, vector<pair<int, int> > > mst2=kruscal();
      if (mst.first==mst2.first) return -1;
    }
    g[x][y]=g[y][x]=w;
  }
  return mst.first;
}

int main()
{
  int k;
  cin>>k;
  for (int i=0; i<k; ++i) {
    int e;
    cin>>n>>e;
    for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) g[i][j]=M;
    for (int j=0; j<e; ++j) {
      int a, b, w;
      cin>>a>>b>>w;
      a--, b--;
      g[a][b]=g[b][a]=w;
    }
    int res=func();
    if (res==-1) cout<<"Not Unique!"<<endl;
    else cout<<res<<endl;
  }
}
