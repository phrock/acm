/*
  ID:   rock2to1
  LANG: C++
  PROG: hamming
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

ifstream fin("hamming.in");
ofstream fout("hamming.out");
////////////////////////////////////////////////////////////////////////////////

int n, b, d;
int res[100];
int cur;
bool found=false;

bool check(int a, int b)
{
  return __builtin_popcount(a^b)>=d;
}

void dfs(int x)
{
  if (found) return;
  if (cur==n) {
    found=true;
    for (int i=0; i<n; ++i) {
      if (i) {
	if(i%10==0) fout<<endl;
	else fout<<" ";
      }
      fout<<res[i];
    }
    fout<<endl;
    return;
  }
  bool ok=true;
  for (int i=0; i<cur; ++i) if (!check(x, res[i])) { ok=false; break; }
  if (ok) {
    res[cur++]=x;
    for (int i=x+1; i<(1<<b); ++i) if (!found) dfs(i);
    cur--;
  }
}

int main()
{
  fin>>n>>b>>d;
  b++;
  cur=0;
  for (int i=0; i<(1<<b); ++i) if (!found) dfs(i);
}
