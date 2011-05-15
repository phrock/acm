/*
  ID:   rock2to1
  LANG: C++
  PROG: replaceme
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

ifstream fin("replaceme.in");
ofstream fout("replaceme.out");
////////////////////////////////////////////////////////////////////////////////

vector<int> c(3);
vector<int> v(3);
set<vector<int> > st;

void dfs()
{
  if (((st).find(v)!=(st).end())) return;
  else st.insert(v);
  for (int i=0; i<3; ++i)
    for (int j=0; j<3; ++j) {
      if (i==j) continue;
      int p=min(v[i], c[j]-v[j]);
      if (!p) continue;
      v[i]-=p; v[j]+=p;
      dfs();
      v[i]+=p; v[j]-=p;
    }
}

int main()
{
  fin>>c[0]>>c[1]>>c[2];
  v[0]=v[1]=0; v[2]=c[2];
  dfs();
  set<int> res;
  for (__typeof((st).begin()) i=(st).begin(); i!=(st).end(); ++i)
    if (!(*i)[0]) res.insert((*i)[2]);
  for (__typeof((res).begin()) i=(res).begin(); i!=(res).end(); ++i) {
    if (i!=res.begin()) fout<<" ";
    fout<<*i;
  }
  fout<<endl;
  
}
