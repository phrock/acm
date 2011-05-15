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

int n, m, k, p;
const int M=1100;
int g[M][M], hole[M], v[M], match[M];

bool dfs(int idx)
{
  for (int i=0; i<p; ++i) {
    int x=i/n, y=i%n;
    if ((x+y)%2) {
      if (g[idx][i] && !v[i] && !hole[i]) {
	v[i]=1;
	if (match[i]==-1 || dfs(match[i])) {
	  match[i]=idx;
	  return true;
	}
      }
    }
  }
  return false;
}

bool check()
{
  memset(match, -1, sizeof(match));
  for (int i=0; i<p; ++i) {
    if (hole[i]) continue;
    int x=i/n, y=i%n;
    if ((x+y)%2==0) {
      memset(v, 0, sizeof(v));
      if (!dfs(i)) return false;
    }
  }
  return true;
}

int main()
{
  cin>>n>>m>>k;
  p=n*m;
  for (int i=0; i<k; ++i) {
    int x, y;
    cin>>x>>y;
    x--, y--;
    hole[y*n+x]=1;
  }
  for (int i=0; i<p; ++i) {
    int x1=i/n, y1=i%n;
    int x2=x1, y2=y1+1;
    if (y2<n) {
      int j=x2*n+y2;
      int color=(x1+y1)%2?0:1;
      if (color) g[i][j]=1;
      else g[j][i]=1;
    }
    x2=x1+1, y2=y1;
    if (x2<m) {
      int j=x2*n+y2;
      int color=(x1+y1)%2?0:1;
      if (color) g[i][j]=1;
      else g[j][i]=1;
    }
  }
  cout<<(check()?"YES":"NO")<<endl;
}
