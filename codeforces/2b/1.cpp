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

int n;
int a[1005][1005], a2[1005][1005], a5[1005][1005], dp[1005][1005], path[1005][1005];

pair<int, string> func(int v[][1005])
{
  memset(dp, 100, sizeof(dp));
  memset(path, 0, sizeof(path));
  dp[0][0]=v[0][0];
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j) {
      if (i) {
	if (v[i][j]+dp[i-1][j]<dp[i][j]) dp[i][j]=v[i][j]+dp[i-1][j], path[i][j]=1;
      }
      if (j) {
	if (v[i][j]+dp[i][j-1]<dp[i][j]) dp[i][j]=v[i][j]+dp[i][j-1], path[i][j]=2;
      }
    }
  string s;
  int x=n-1, y=n-1;
  while (x || y) if (path[x][y]==1) s.push_back('D'), x--; else s.push_back('R'), y--;
  reverse((s).begin(), (s).end());
  return make_pair(dp[n-1][n-1], s);
}

int main()
{
  cin>>n;
  bool zero=false;
  int zerox, zeroy;
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j) {
      // cin>>a[i][j];
      scanf("%d", &a[i][j]);
      if (!a[i][j]) { zero=true; a[i][j]=10; zerox=i; zeroy=j; }
      int aux=a[i][j];
      while (aux%2==0) aux/=2, a2[i][j]++;
      while (aux%5==0) aux/=5, a5[i][j]++;
    }
  pair<int, string> r2=func(a2), r5=func(a5);
  int res;
  string res_path;
  if (r2.first<r5.first) res=r2.first, res_path=r2.second;
  else res=r5.first, res_path=r5.second;
  if (zero && res) {
    res=1;
    res_path="";
    for (int i=0; i<zerox; ++i) res_path.push_back('D');
    for (int i=1; i<n; ++i) res_path.push_back('R');
    for (int i=zerox+1; i<n; ++i) res_path.push_back('D');
  }
  cout<<res<<endl<<res_path<<endl;
}
