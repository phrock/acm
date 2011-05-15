/*
  ID:   rock2to1
  LANG: C++
  PROG: frac1
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

ifstream fin("frac1.in");
ofstream fout("frac1.out");
////////////////////////////////////////////////////////////////////////////////

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
  return a.first*b.second<a.second*b.first;
}

int main()
{
  int n;
  fin>>n;
  set<pair<int, int> > st;
  st.insert(make_pair(0, 1)); st.insert(make_pair(1, 1));
  for (int i=2; i<=n; ++i)
    for (int j=1; j<i; ++j) {
      int g=__gcd(i, j);
      st.insert(make_pair(j/g, i/g));
    }
  vector<pair<int, int> > v((st).begin(), (st).end());
  sort((v).begin(), (v).end(), cmp);
  for (int i=0; i<(int)(v).size(); ++i)
    fout<<v[i].first<<"/"<<v[i].second<<endl;
}
