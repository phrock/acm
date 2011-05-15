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

const int M=1005;
int g[M][M], v[M], match[M];
int n, m;

bool check(int x)
{
  for (int i=1; i<=m; ++i)
    if (g[x][i] && !v[i]) {
      v[i]=1;
      if (!match[i] || check(match[i])) {
	match[i]=x;
	return true;
      }
    }
  return false;
}

int hungary()
{
  int res=0;
  for (int i=1; i<=n; ++i) {
    memset(v, 0, sizeof(v));
    if (check(i)) res++;
  }
  return res;
}

int main()
{
  while (cin>>n>>m) {
    memset(g, 0, sizeof(g));
    memset(match, 0, sizeof(match));
    for (int i=1; i<=n; ++i) {
      int p;
      cin>>p;
      for (int j=0; j<p; ++j) {
	int x;
	cin>>x;
	g[i][x]=1;
      }
    }
    int res=hungary();
    cout<<res<<endl;
  }
}
