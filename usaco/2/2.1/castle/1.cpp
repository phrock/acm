/*
  ID:   rock2to1
  LANG: C++
  PROG: castle
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

ifstream fin("castle.in");
ofstream fout("castle.out");
////////////////////////////////////////////////////////////////////////////////

int m, n;
set<pair<int, int> > g;

int convert(int a, int b)
{
  return a*m+b;
}

pair<int, int> convert2(int a)
{
  return make_pair(a/m, a%m);
}

int p[]={-1, 1, 0, 0};
int q[]={0, 0, -1, 1};
int cnt;
map<int, int> mm;

void dfs(int x)
{
  int a=convert2(x).first;
  int b=convert2(x).second;
  for (int i=0; i<4; ++i) {
    int na=a+p[i];
    int nb=b+q[i];
    if (na>=0 && (na<n) && nb>=0 && (nb<m)) {
      int next=convert(na, nb);
      if (!mm[next] && ((g).find(make_pair(x, next))!=(g).end())) mm[next]=mm[x], dfs(next);
    }
  }
}

int main()
{
  fin>>m>>n;
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j) {
      int x;
      fin>>x;
      if (!(x & (1<<0))) {
	g.insert(make_pair(convert(i, j), convert(i, j-1)));
	g.insert(make_pair(convert(i, j-1), convert(i, j)));
      }
      if (!(x & (1<<1))) {
	g.insert(make_pair(convert(i, j), convert(i-1, j)));
	g.insert(make_pair(convert(i-1, j), convert(i, j)));
      }
      if (!(x & (1<<2))) {
	g.insert(make_pair(convert(i, j), convert(i, j+1)));
	g.insert(make_pair(convert(i, j+1), convert(i, j)));
      }
      if (!(x & (1<<3))) {
	g.insert(make_pair(convert(i, j), convert(i+1, j)));
	g.insert(make_pair(convert(i+1, j), convert(i, j)));
      }
    }
  cnt=0;
  for (int i=0; i<n; ++i)
    for (int j=0; j<m; ++j) {
      int x=convert(i, j);
      if (!mm[x]) {
	mm[x]=++cnt;
	dfs(x);
      }
    }
  vector<int> v(cnt+1);
  for (__typeof((mm).begin()) i=(mm).begin(); i!=(mm).end(); ++i) v[i->second]++;
  fout<<cnt<<endl;
  fout<<*max_element((v).begin(), (v).end())<<endl;

  int rx=INT_MAX, ry=INT_MAX, rm=-1;
  string rs;
  for (int j=0; j<m; ++j)
    for (int i=n-1; i>=0; --i) {
      if (i>0) {
	int x=convert(i, j);
	int y=convert(i-1, j);
	if (!((g).find(make_pair(x, y))!=(g).end()) && mm[x]!=mm[y]) {
	  int c1=v[mm[x]], c2=v[mm[y]];
	  if (c1+c2>rm) { rm=c1+c2; rx=i; ry=j; rs="N"; }
	}
      }
      if (j<m-1) {
	int x=convert(i, j);
	int y=convert(i, j+1);
	if (!((g).find(make_pair(x, y))!=(g).end()) && mm[x]!=mm[y]) {
	  int c1=v[mm[x]], c2=v[mm[y]];
	  if (c1+c2>rm) { rm=c1+c2; rx=i; ry=j; rs="E"; }
	}
      }
    }
  fout<<rm<<endl;
  fout<<rx+1<<" "<<ry+1<<" "<<rs<<endl;
  #ifdef DEBUG
  for (int i=0; i<n; ++i) {
    for (int j=0; j<m; ++j)
      printf("%3d", v[mm[convert(i, j)]]);
    cout<<endl;
  }
  #endif
}
