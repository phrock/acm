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

int dp[1005][55];
int tm[55][55], toll[55][55];

int main()
{
    int n, t;
    while (cin>>n>>t) {
        if (!n) break;
        memset(dp, 0, sizeof(dp));

        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                cin>>tm[i][j];
        for (int i=0; i<n; ++i)
            for (int j=0; j<n; ++j)
                cin>>toll[i][j];

        for (int i=0; i<=t; ++i)
            for (int j=0; j<n; ++j)
                dp[i][j]=INT_MAX/2;
        dp[0][0]=0;

        for (int i=0; i<=t; ++i)
            for (int j=0; j<n; ++j) {
                for (int k=0; k<n; ++k) {
                    if (k==j) continue;
                    for (int t1=0; t1<=i; ++t1) {
                        int t2=i-t1;
                        if (t2>=tm[k][j]) dp[i][j]=min(dp[i][j], dp[t1][k]+toll[k][j]);
                    }
                }
            }
        #ifdef DEBUG
        print2(dp, t+1, n);        
        #endif
        int res=INT_MAX, res_t;
        for (int i=0; i<=t; ++i)
            if (dp[i][n-1]<res) res=dp[i][n-1], res_t=i;
        cout<<res<<" "<<res_t<<endl;
    }
        
}
