/*
  ID:   rock2to1
  LANG: C++
  PROG: comehome
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

ifstream fin("comehome.in");
ofstream fout("comehome.out");
////////////////////////////////////////////////////////////////////////////////

const int M=INT_MAX/2;

int main()
{
  int n=52;
  vector<vector<pair<int, int> > > g(n, vector<pair<int, int> >());
  int path;
  fin>>path;
  for (int i=0; i<path; ++i) {
    char a, b;
    int weight;
    int x, y;
    fin>>a>>b>>weight;
    if (isupper(a)) x=a-'A';
    else x=a-'a'+26;
    if (isupper(b)) y=b-'A';
    else y=b-'a'+26;
    g[x].push_back(make_pair(y, weight));
    g[y].push_back(make_pair(x, weight));
  }
  vector<int> dist(n, M);
  dist['Z'-'A']=0;
  set<pair<int, int> > st;
  st.insert(make_pair(0, 'Z'-'A'));
  
  while (!st.empty()) {
    pair<int, int> top=*st.begin();
    st.erase(st.begin());
    int weight=top.first;
    int node=top.second;
    if (node<25) { fout<<(char)(node+'A')<<" "<<weight<<endl; break; }
    for (int i=0; i<(int)(g[node]).size(); ++i) {
      int node2=g[node][i].first, weight2=g[node][i].second;
      if (weight+weight2<dist[node2]) {
	if (dist[node2]!=M) st.erase(st.find(make_pair(dist[node2], node2)));
	st.insert(make_pair(weight+weight2, node2));
	dist[node2]=weight+weight2;
      }
    }
  }
}
