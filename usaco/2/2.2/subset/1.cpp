/*
  ID:   rock2to1
  LANG: C++
  PROG: subset
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

ifstream fin("subset.in");
ofstream fout("subset.out");
////////////////////////////////////////////////////////////////////////////////
int n, x;
vector<int> a;
int cnt;
set<vector<int> > st;

void dfs(int sum, int cur)
{
  if (sum==x) {
    if (!((st).find(a)!=(st).end())) {
      st.insert(a);
      
    }
    return;
  }
  for (int i=cur+1; i<=n; ++i) {
    if (sum+i<=x) { a[i]=1; dfs(sum+i, i); a[i]=0; }
  }
}
      

int main()
{
  fin>>n;
  if (n*(n+1)%4) { fout<<0<<endl; return 0; }
  x=n*(n+1)/4;
  a.resize(n+1);
  for (int i=1; i<=n; ++i) { a[i]=1; dfs(i, i); a[i]=0; }
  fout<<(int)(st).size()/2<<endl;
}
