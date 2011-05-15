#include <cstring>
#include <iostream>
using namespace std;
int a[105][105], dp[105][105];
int main()
{
    int T, ti, i, j, n;
    cin>>T;
    for (ti=0; ti < T; ++ti) {cin >> n; memset(a, 0, sizeof(a)); memset(dp, 0, sizeof(dp)); for (i=0; i < n; ++i) for (j=0; j <= i; ++j) cin >> a[i][j]; dp[0][0]=a[0][0]; for (i=1; i<n; ++i) for (j=0; j<=i; ++j) {if (j) dp[i][j]=max(dp[i][j], dp[i-1][j-1]+a[i][j]); if (j!=i) dp[i][j]=max(dp[i][j], dp[i-1][j]+a[i][j]);} int res=0; for (int i=0; i < n; ++i) res=max(res, dp[n-1][i]); cout<<res<<endl;}
}
