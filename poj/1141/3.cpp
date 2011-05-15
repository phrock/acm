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
int trace[105][105];
string s;

void output(int a, int b)
{
  if (a>b) return;
  else if (a==b) cout<<((s[a]=='('||s[b]==')')?"()":"[]");
  else if (trace[a][b]==-1) cout<<s[a], output(a+1, b-1), cout<<s[b];
  else output(a, trace[a][b]), output(trace[a][b]+1, b);
}

int main()
{
  getline(cin, s);
  int n=(int)(s).size();

  memset(dp, 100, sizeof(dp));
  for (int i=1; i<105; ++i) dp[i][i-1]=0, dp[i][i]=1;

  for (int len=2; len<=n; ++len)
    for (int i=0; i<n-len+1; ++i) {
      int j=i+len-1;
      if ((s[i]=='(' && s[j]==')') || (s[i]=='[' && s[j]==']')) {
	  if (dp[i+1][j-1]<dp[i][j]) trace[i][j]=-1, dp[i][j]=dp[i+1][j-1];
      }
      for (int k=i; k<=j-1; ++k) {
	if (dp[i][k]+dp[k+1][j]<dp[i][j]) dp[i][j]=dp[i][k]+dp[k+1][j], trace[i][j]=k;
      }
    }
  output(0, n-1);
  cout<<endl;
}
