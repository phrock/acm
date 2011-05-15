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

const int MAX=6105;
int dp[MAX][MAX];
char s[MAX];

int main()
{
    int T;
    cin>>T;
    for (int ti=0; ti<T; ++ti) {
        scanf("%s", s);
        int n=strlen(s);
        for (int i=0; i<n; ++i) { dp[i][i]=0; if (i) dp[i][i-1]=0; }
        for (int len=2; len<=n; ++len)
            for (int i=0; i<n-len+1; ++i) {
                int j=i+len-1;
                if (s[i]==s[j]) dp[i][j]=dp[i+1][j-1];
                else dp[i][j]=min(dp[i+1][j], dp[i][j-1])+1;
            }
        cout<<dp[0][n-1]<<endl;
    }
}
