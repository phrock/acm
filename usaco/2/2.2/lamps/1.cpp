/*
  ID:   rock2to1
  LANG: C++
  PROG: lamps
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

ifstream fin("lamps.in");
ofstream fout("lamps.out");
////////////////////////////////////////////////////////////////////////////////

vector<bool> lamp, on, off;
int n, c, cur;
int button[4];
set<string> res;

void fun()
{
  fill((lamp).begin(), (lamp).end(), true);
  for (int i=0; i<4; ++i) {
    button[i]%=2;
    if (!button[i]) continue;
    switch (i) {
    case 0: fill((lamp).begin(), (lamp).end(), false); break;
    case 1: for (int i=1; i<=n; i+=2) lamp[i]=!lamp[i]; break;
    case 2: for (int i=2; i<=n; i+=2) lamp[i]=!lamp[i]; break;
    case 3: for (int i=1; i<=n; i+=3) lamp[i]=!lamp[i]; break;
    }
  }
  bool ok=true;
  for (int i=1; i<=n; ++i) if (on[i] && !lamp[i]) { ok=false; break; }
  for (int i=1; i<=n; ++i) if (off[i] && lamp[i]) { ok=false; break; }
  if (ok) {
    string s;
    for (int i=1; i<=n; ++i) s+=lamp[i]?"1":"0";
    res.insert(s);
  }
}

void dfs(int k)
{
  if (cur==4) { fun(); return; }
  for (int i=0; k+i<=c; ++i) { button[cur++]=i; dfs(k+i); cur--; }
}

int main()
{ 
  fin>>n>>c;
  int aux;
  lamp.resize(n+1); on.resize(n+1); off.resize(n+1);
  while (fin>>aux) { if (aux==-1) break; on[aux]=true; }
  while (fin>>aux) { if (aux==-1) break; off[aux]=true; }
  cur=0;
  dfs(0);
  if (!res.empty()) for (__typeof((res).begin()) i=(res).begin(); i!=(res).end(); ++i) fout<<*i<<endl;
   else fout<<"IMPOSSIBLE"<<endl;
}
