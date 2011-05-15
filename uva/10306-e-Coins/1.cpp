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

ifstream fin("in");
////////////////////////////////////////////////////////////////////////////////

int dp[1000][1000];
int a[100][2];

int main()
{
#ifdef DEBUG
  cin.rdbuf(fin.rdbuf());  
#endif

  int n;
  cin>>n;
  for (int t=0; t<n; ++t) {
    memset(dp, -1, sizeof(dp));
    dp[0][0]=0;
    int m, s;
    cin>>m>>s;
    for (int i=0; i<m; ++i) cin>>a[i][0]>>a[i][1];
    for (int j=0; j<=s; ++j)
      for (int k=0; k<=s; ++k) {
	int p=INT_MAX;
	for (int i=0; i<m; ++i)
	  if (j>=a[i][0] && k>=a[i][1] && dp[j-a[i][0]][k-a[i][1]]!=-1)
	    p=min(p, 1+dp[j-a[i][0]][k-a[i][1]]);
	if (p!=INT_MAX) dp[j][k]=p;
      }
    int res=INT_MAX;
    for (int i=0; i<=s; ++i)
      for (int j=0; j<=s; ++j)
	if (dp[i][j]!=-1 && i*i+j*j==s*s)
	  res=min(res, dp[i][j]);
    if (res==INT_MAX) cout<<"not possible"<<endl;
    else cout<<res<<endl;
  }
}
