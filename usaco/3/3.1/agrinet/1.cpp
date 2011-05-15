/*
  ID:   rock2to1
  LANG: C++
  PROG: agrinet
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

ifstream fin("agrinet.in");
ofstream fout("agrinet.out");
////////////////////////////////////////////////////////////////////////////////

int main()
{
  int n;
  fin>>n;
  vector<vector<int> > g(n, vector<int>(n));
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      fin>>g[i][j];
  const int M=INT_MAX/2;
  vector<int> dist(n, M);
  vector<int> back(n);
  for (int i=0; i<(int)(back).size(); ++i) back[i]=i;
  dist[0]=0;
  set<pair<int, int> > st;
  st.insert(make_pair(0, 0));
  vector<int> visited(n);
  while (!st.empty()) {
    pair<int, int> top=*st.begin();
    st.erase(st.begin());
    int v=top.second;
    visited[v]=1;
    for (int i=0; i<n; ++i) {
      if (visited[i]) continue;
      int cost=g[v][i];
      if (cost<dist[i]) {
	if (dist[i]!=M) st.erase(make_pair(dist[i], i));
	st.insert(make_pair(cost, i));
	dist[i]=cost;
	back[i]=v;
      }
    }
  }
  int res=0;
  for (int i=0; i<n; ++i) res+=g[i][back[i]];
  fout<<res<<endl;
}
