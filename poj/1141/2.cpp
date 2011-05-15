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

int dp[105][105];
string res[105][105];

int main()
{
  memset(dp, 100, sizeof(dp));
  string s;
  getline(cin, s);
  int n=(int)(s).size();
  s=" "+s;

  for (int i=1; i<105; ++i) dp[i][i-1]=0, dp[i][i]=1;
  for (int i=1; i<=n; ++i) res[i][i]=(s[i]=='('||s[i]==')')?"()":"[]";

  for (int len=1; len<=n; ++len)
    for (int i=1; i<=n-len+1; ++i) {
      int j=i+len-1;
      if (s[i]=='(' &&s[j]==')') {
	  if (dp[i+1][j-1]<dp[i][j]) dp[i][j]=dp[i+1][j-1], res[i][j]="("+res[i+1][j-1]+")";
      }
      if (s[i]=='[' && s[j]==']') {
	  if (dp[i+1][j-1]<dp[i][j]) dp[i][j]=dp[i+1][j-1], res[i][j]="["+res[i+1][j-1]+"]";
      }	  
      for (int k=i; k<=j-1; ++k) {
	if (dp[i][k]+dp[k+1][j]<dp[i][j]) dp[i][j]=dp[i][k]+dp[k+1][j], res[i][j]=res[i][k]+res[k+1][j];
      }
    }
  cout<<res[1][n]<<endl;
}
