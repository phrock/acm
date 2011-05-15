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

map<pair<int, int>, int > mm;
int a[100005];
int v[100005];
vector<int> g[100005];

int check(int x, int y)
{
  if (((mm).find(make_pair(x, y))!=(mm).end())) return mm[make_pair(x, y)];
  set< pair<int, int> > aux;
  queue<pair<int, int> > q;
  pair<int, int> init=make_pair(x, 1);
  q.push(init);
  memset(v, 0, sizeof(v));
  v[x]=1;
  while (!q.empty()) {
    pair<int, int> t=q.front();
    int next=t.second==1?2:1;
    q.pop();
    if (t.first==y) return t.second;
    for (__typeof((aux).begin()) i=(aux).begin(); i!=(aux).end(); ++i)
      if (i->second==t.second) mm[make_pair(i->first, t.first)]=mm[make_pair(t.first, i->first)]=1;
      else mm[make_pair(i->first, t.first)]=mm[make_pair(t.first, i->first)]=2;
    aux.insert(t);
    for (int i=0; i<(int)(g[t.first]).size(); ++i)
      if (!v[g[t.first][i]]) q.push(make_pair(g[t.first][i], next));
  }
  return 0;
}

int main()
{
  int T, n, m;
  cin>>T;
  for (int i=0; i<T; ++i) {
    cin>>n>>m;
    mm.clear();
    for (int j=0; j<n; ++j) g[j].clear();
    for (int j=0; j<m; ++j) {
      string s;
      int x, y;
      cin>>s>>x>>y;
      x--; y--;
      if (s=="A") {
	int res=check(x, y);
	switch(res) {
	case 0: cout<<"Not sure yet."<<endl; break;
	case 1: cout<<"In the same gang."<<endl; break;
	case 2: cout<<"In different gangs."<<endl; break;
	}
      } else {
	g[x].push_back(y);
	g[y].push_back(x);
      }
    }
  }
}
