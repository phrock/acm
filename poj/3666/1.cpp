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

////////////////////////////////////////////////////////////////////////////////

int dp[2005];
int height[2005];
int a[2005];

int main()
{
  int n;
  cin>>n;
  for (int i=1; i<=n; ++i) cin>>a[i], height[i]=a[i];
  sort(height+1, height+1+n);
  dp[0]=INT_MAX;
  for (int i=1; i<=n; ++i) 
    for (int j=1; j<=n; ++j) 
      dp[j]=min(dp[j-1], dp[j]+abs(a[i]-height[j]));
  int cnt1=*min_element(dp+1, dp+1+n);
  sort(height+1, height+1+n, greater<int>());
  memset(dp, 0, sizeof(dp));
  dp[0]=INT_MAX;
  for (int i=1; i<=n; ++i)
    for (int j=1; j<=n; ++j)
      dp[j]=min(dp[j-1], dp[j]+abs(a[i]-height[j]));
  int cnt2=*min_element(dp+1, dp+1+n);
  cout<<min(cnt1, cnt2)<<endl;
}
