/*
  ID:   rock2to1
  LANG: C++
  PROG: fence4
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

ifstream fin("fence4.in");
ofstream fout("fence4.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////

int crossMultiplication(pair<int, int> a, pair<int, int> b)
{
  return a.first*b.second-a.second*b.first;
}

bool isDiffSide(pair<pair<int, int>, pair<int, int> > line, pair<int, int> a, pair<int, int> b)
{
  pair<int, int> p=make_pair(line.second.first-line.first.first, line.second.second-line.first.second);
  pair<int, int> t1=make_pair(a.first-line.first.first, a.second-line.first.second);
  pair<int, int> t2=make_pair(b.first-line.first.first, b.second-line.first.second);
  return crossMultiplication(p, t1)*crossMultiplication(p, t2)<0;
}

bool isCrossed(pair<pair<int, int>, pair<int, int> > a, pair<pair<int, int>, pair<int, int> > b)
{
  if (isDiffSide(a, b.first, b.second) && isDiffSide(b, a.first, a.second)) return true;
  else return false;
}

int main()
{
  cin.rdbuf(fin.rdbuf());
  cout.rdbuf(fout.rdbuf());
  #ifdef DEBUG
  cin.rdbuf(cin_buf);
  cout.rdbuf(cout_buf);
  #endif
  //////////////////////////////////////////////////////////////////////////////

  int n, px, py;
  cin>>n>>px>>py;
  vector<pair<int, int> > v(n);
  for (int i=0; i<n; ++i) cin>>v[i].first>>v[i].second;
  vector<pair<pair<int, int>, pair<int, int> > > fence;
  for (int i=0; i<n; ++i) {
    int p=i, q=(i+1)%n;
    if (p>q) swap(p, q);
    fence.push_back(make_pair(v[p], v[q]));
  }
  bool ok=true;
  for (int i=0; i<(int)(fence).size(); ++i)
    for (int j=i+1; j<(int)(fence).size(); ++j)
      if (isCrossed(fence[i], fence[j])) { ok=false; break; }
  if (!ok) { cout<<"NOFENCE"<<endl; return 0; }

  for (int i=0; i<(int)(fence).size(); ++i)  {
    bool ok=true;
    for (int j=0; j<(int)(fence).size(); ++j) {
      if (i==j) continue;
      if (isCrossed2(fence[j], fence[i].first, fence[i].second
}
