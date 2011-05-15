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
    #ifdef DEBUG
    print2(g);    
    #endif
    bool ok=false;
    for (int i=0; i<n; ++i) {
      if (ok) break;
      pair<int, int> start;
      start.first=i;
      start.second=0;
      queue<pair<int, int> > q;
      q.push(start);
      map<int, int> mm;
      mm[i]=0;
      while (!q.empty()) {
	pair<int, int> x=q.front();
	q.pop();
	if (x.first==i && x.second<0) { ok=true; break; }
	for (int j=0; j<n; ++j) {
	  if (g[x.first][j]==INT_MAX) continue;
	  pair<int, int> next;
	  next.first=j;
	  next.second=x.second+g[x.first][j];
	  if (!((mm).find(j)!=(mm).end()) || mm[j]>next.second) { q.push(next); mm[j]=next.second; }
	}
      }
    }
    cout<<(ok?"YES":"NO")<<endl;
  }
}
