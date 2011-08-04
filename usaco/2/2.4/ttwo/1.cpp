/*
  ID:   rock2to1
  LANG: C++
  PROG: ttwo
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

ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
////////////////////////////////////////////////////////////////////////////////

int p[]={-1, 0, 1, 0};
int q[]={0, 1, 0, -1};

pair<int, int> next(const vector<string> &g, const pair<int, int> &cur)
{
  int x=cur.first/10, y=cur.first%10, dir=cur.second;
  int nx=x+p[dir];
  int ny=y+q[dir];
  pair<int, int> res;
  if (nx>=0 && ny>=0 && nx<10 && ny<10 && g[nx][ny]!='*') { res.first=nx*10+ny; res.second=dir; }
  else { res.first=cur.first; res.second=(dir+1)%4; }
  return res;
}

int main()
{
  vector<string> g(10);
  for (int i=0; i<(int)(g).size(); ++i) fin>>g[i];
  pair<int, int> farmer, cow;
  for (int i=0; i<(int)(g).size(); ++i)
    for (int j=0; j<(int)(g[i]).size(); ++j)
      if (g[i][j]=='F') { farmer.first=i*10+j; farmer.second=0; }
      else if (g[i][j]=='C') { cow.first=i*10+j; cow.second=0; }
  set<pair<pair<int, int>, pair<int, int> > > st;
  st.insert(make_pair(farmer, cow));
  int cnt=0;
  while (true) {
    cnt++;
    farmer=next(g, farmer);
    cow=next(g, cow);
    if (farmer.first==cow.first) break;
    if (((st).find(make_pair(farmer, cow))!=(st).end())) { cnt=0; break; }
    st.insert(make_pair(farmer, cow));
  }
  fout<<cnt<<endl;
}
