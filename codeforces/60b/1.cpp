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


int a[10][10][10];
int b[10][10][10];
int k, n, m;

void dfs(int x, int y, int z)
{
  if (b[x][y][z]) return;
  b[x][y][z]=1;
  if (x>0 && a[x-1][y][z]) dfs(x-1, y, z);
  if (x<k-1 && a[x+1][y][z]) dfs(x+1, y, z);
  if (y>0 && a[x][y-1][z]) dfs(x, y-1, z);
  if (y<n-1 && a[x][y+1][z]) dfs(x, y+1, z);
  if (z>0 && a[x][y][z-1]) dfs(x, y, z-1);
  if (z<m-1 && a[x][y][z+1]) dfs(x, y, z+1);
}

int main()
{
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(b));
  cin>>k>>n>>m;
  for (int i=0; i<k; ++i)
    for (int j=0; j<n; ++j) {
      string s;
      cin>>s;
      for (int x=0; x<m; ++x)
	if (s[x]=='.') a[i][j][x]=1;
    }
  int x, y;
  cin>>x>>y;
  dfs(0, x-1, y-1);
  int res=0;
  for (int i=0; i<k; ++i)
    for (int j=0; j<n; ++j)
      for (int p=0; p<m; ++p)
	if (b[i][j][p]) res++;
  cout<<res<<endl;
}
