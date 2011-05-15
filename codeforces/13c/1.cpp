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
  int n;
  cin>>n;
  vector<long long> v(n);
  for (int i=0; i<n; ++i) cin>>v[i];
  vector<long long> a=v;
  sort((a).begin(), (a).end());
  vector<vector<long long> > dp(2, vector<long long>(n));
  for (int i=0; i<n; ++i) dp[0][i]=max(0LL, v[0]-a[i]);
  for (int i=1; i<n; ++i) {
    int k=i%2;
    for (int j=0; j<n; ++j)
      if (!j) dp[k][j]=v[i]-a[j]+dp[1-k][j];
      else dp[k][j]=min(dp[k][j-1], dp[1-k][j]+abs(v[i]-a[j]));
  }
  #ifdef DEBUG
  print2(dp);  
  #endif
  cout<<dp[1-n%2][n-1]<<endl;	
}
