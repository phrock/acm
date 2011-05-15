/*
  ID:   rock2to1
  LANG: C++
  PROG: checker
*/

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

ifstream fin("checker.in");
ofstream fout("checker.out");
////////////////////////////////////////////////////////////////////////////////

int a[20][20];
int used;
int n;
int cnt;

void dfs(int cur)
{
  if (cur>n) { cnt++; if (cnt<=3) { for (int i=1; i<=n; ++i) { if (i>1) fout<<" "; fout<<a[i][0]; } fout<<endl; }  return; }
  for (int i=1; i<=n; ++i) {
    if (n>6 && cur==1 && i>n/2) break;
    if (used&(1<<i)) continue;
    bool ok=true;
    for (int j=cur-1; j>=1; --j) {
      int k=cur-j;
      if (i-k>=1 && a[j][i-k]) { ok=false; break; }
      if (i+k<=n && a[j][i+k]) { ok=false; break; }
    }
    if (ok) {
      used|=(1<<i);
      a[cur][i]=1;
      a[cur][0]=i;
      dfs(cur+1);
      a[cur][0]=0;
      a[cur][i]=0;
      used^=(1<<i);
    }
  }
}

int main()
{
  fin>>n;
  dfs(1);
  if (n>6) {
    cnt<<=1;
    if (n%2) { a[1][n/2+1]=1; used|=(1<<(n/2+1)); dfs(2); }
  }
  fout<<cnt<<endl;
}
