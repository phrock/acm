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

#ifdef DEBUG
#include "/home/rock/program/topcoder/libs/debug.cpp"
#endif
////////////////////////////////////////////////////////////////////////////////


int main()
{
  long long dp[15][15];
  memset(dp, 0, sizeof(dp));
  //for (int i=0; i<=10; ++i) dp[0][i]=1;
  dp[0][0]=1;
  for (int i=0; i<=10; ++i)
    for (int j=1; j<=10; ++j)
      if (i>=j) dp[i][j]=dp[i][j-1]+dp[i-j][j];
      else dp[i][j]=dp[i][i];
  #ifdef DEBUG
  print(dp[7], 8);
  #endif
  int m, n, t;
  cin>>t;
  while (t--) {
    cin>>m>>n;
    cout<<dp[m][n]<<endl;
  }
}
