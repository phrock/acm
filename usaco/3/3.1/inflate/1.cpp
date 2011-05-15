/*
  ID:   rock2to1
  LANG: C++
  PROG: inflate
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

ifstream fin("inflate.in");
ofstream fout("inflate.out");
////////////////////////////////////////////////////////////////////////////////

int main()
{
  int m, n;
  fin>>m>>n;
  vector< pair<int, int> > v(n);
  for (int i=0; i<n; ++i) fin>>v[i].first>>v[i].second;
  vector<int> dp(m+1);
  for (int i=0; i<n; ++i)
    for (int j=v[i].second; j<=m; ++j)
      dp[j]=max(dp[j], dp[j-v[i].second]+v[i].first);
  fout<<dp[m]<<endl;
}
