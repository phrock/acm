/*
  ID:   rock2to1
  LANG: C++
  PROG: humble
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

ifstream fin("humble.in");
ofstream fout("humble.out");
////////////////////////////////////////////////////////////////////////////////

int main()
{
  int n, cnt;
  fin>>n>>cnt;
  vector<int> v(n);
  for (int i=0; i<n; ++i) fin>>v[i];
  sort((v).begin(), (v).end());
  long long m=v.back();
  set<long long> st;
  for (int i=0; i<n; ++i) st.insert(v[i]);
  long long x;
  while (cnt) {
    x=*st.begin();
    st.erase(st.begin());
    cnt--;
    for (int i=0; i<n; ++i) {
      long long y=x*v[i];
      if ((int)(st).size()>cnt && y>=m) continue;
      if (!((st).find(y)!=(st).end())) st.insert(y), m=max(m, y);
    }
  }
  fout<<x<<endl;
}
