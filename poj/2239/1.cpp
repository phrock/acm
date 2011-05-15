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

int n, g[305][100], v[100], match[100];

bool dfs(int x)
{
  for (int i=0; i<7*12; ++i)
    if (g[x][i] && !v[i]) {
      v[i]=1;
      if (!match[i] || dfs(match[i])) {
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
    if (dfs(i)) res++;
  }
  return res;
}

int main()
{
  while (cin>>n) {
    memset(g, 0, sizeof(g));
    memset(match, 0, sizeof(match));
    for (int i=1; i<=n; ++i) {
      int a;
      cin>>a;
      for (int j=0; j<a; ++j) {
	int p, q;
	cin>>p>>q;
	p--, q--;
	g[i][p*12+q]=1;
      }
    }
    cout<<hungary()<<endl;
  }
}
