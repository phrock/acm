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

int a[14];
int used;
int v[14];
int n;
int cnt;

void dfs(int cur)
{
  if (cur>n) { cnt++; if (cnt<=3) { for (int i=1; i<=n; ++i) { if (i>1) fout<<" "; fout<<a[i]; } fout<<endl; }  return; }
  for (int i=1; i<=n; ++i) {
    if (n>6 && cur==1 && i>n/2) break;
    if (used&(1<<i) || v[cur]&(1<<i)) continue;
    // print(a, n+1);
    used|=1<<i;
    int sv[14];
    memcpy(sv, v, sizeof(v));
    for (int j=cur+1; j<=n; ++j) {
      if (i-(j-cur)>=1) v[j]|=(1<<(i-(j-cur)));
      if (i+(j-cur)<=n) v[j]|=(1<<(i+(j-cur)));
    }
    a[cur]=i;
    dfs(cur+1);
    a[cur]=0;
    memcpy(v, sv, sizeof(sv));
    used^=1<<i;
  }
}

int main()
{
  fin>>n;
  dfs(1);
  if (n>6) {
    cnt<<=1;
    if (n%2) {
      a[1]=1;
      int i=n/2+1;
      used|=1<<i;
      int cur=1;
      for (int j=cur+1; j<=n; ++j) {
	if (i-(j-cur)>=1) v[j]|=(1<<(i-(j-cur)));
	if (i+(j-cur)<=n) v[j]|=(1<<(i+(j-cur)));
      }
      dfs(2);
    }
  }
  fout<<cnt<<endl;
}
