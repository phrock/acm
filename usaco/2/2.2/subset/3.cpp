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

long long dp[1000];

int main()
{
  int n;
  fin>>n;
  if (n*(n+1)%4) { fout<<0<<endl; return 0; }
  int x=n*(n+1)/4;
  dp[0]=1;
  for (int i=1; i<=n; ++i)
    for (int j=x; j>=i; --j)
      dp[j]+=dp[j-i];
  fout<<dp[x]/2<<endl;
}
