/*
  ID:   rock2to1
  LANG: C++
  PROG: holstein
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

ifstream fin("holstein.in");
ofstream fout("holstein.out");
////////////////////////////////////////////////////////////////////////////////

int main()
{
  int n, m;
  fin>>n;
  vector<int> v(n);
  for (int i=0; i<n; ++i) fin>>v[i];
  fin>>m;
  vector<vector<int> > g(m, vector<int>(n));
  for (int i=0; i<m; ++i)
    for (int j=0; j<n; ++j)
      fin>>g[i][j];
  vector<int> res(m, INT_MAX);
  int cnt=INT_MAX;
  for (int i=0; i<(1<<m); ++i) {
    if (__builtin_popcount(i)>cnt) continue;
    vector<int> aux(n);
    for (int j=0; j<m; ++j)
      if (i & (1<<j))
	for (int k=0; k<n; ++k) aux[k]+=g[j][k];
    bool ok=true;
    for (int j=0; j<n; ++j) if (aux[j]<v[j]) { ok=false; break; }
    if (ok) {
      vector<int> tmp;
      for (int j=0; j<m; ++j) if (i & (1<<j)) tmp.push_back(j+1);
      if (__builtin_popcount(i)<cnt) { cnt=__builtin_popcount(i); res=tmp; }
      else res=min(res, tmp);
    }
  }
  fout<<cnt;
  for (int i=0; i<(int)(res).size(); ++i) fout<<" "<<res[i];
  fout<<endl;
}
