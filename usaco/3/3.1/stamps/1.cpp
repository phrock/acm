/*
  ID:   rock2to1
  LANG: C++
  PROG: stamps
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

ifstream fin("stamps.in");
ofstream fout("stamps.out");
////////////////////////////////////////////////////////////////////////////////

set<int> st;
vector<int> v;

void dfs(int cur, int n, int sum)
{
  if (cur==(int)(v).size()) return;
  for (int i=0; i<=n; ++i) {
    st.insert(sum+v[cur]*i);
    dfs(cur+1, n-i, sum+v[cur]*i);
  }
}

int main()
{
  int k, n;
  fin>>k>>n;
  v.resize(n);
  for (int i=0; i<n; ++i) fin>>v[i];
  sort((v).begin(), (v).end()), (v).erase(unique((v).begin(), (v).end()), (v).end());
  dfs(0, k, 0);
  int res=0;
  for (int i=1; i<INT_MAX; ++i) if (((st).find(i)!=(st).end())) res=i; else break;
  fout<<res<<endl;
}
