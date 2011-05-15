/*
  ID:   rock2to1
  LANG: C++
  PROG: money
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

ifstream fin("money.in");
ofstream fout("money.out");
////////////////////////////////////////////////////////////////////////////////

long long dp[10001];
int money[26];

int main()
{
  int v, n;
  fin>>v>>n;
  for (int i=1; i<=v; ++i) fin>>money[i];
  dp[0]=1;
  for (int i=1; i<=v; ++i)
    for (int j=1; j<=n; ++j)
      if (j>=money[i]) dp[j]+=dp[j-money[i]];
  fout<<dp[n]<<endl;
}
