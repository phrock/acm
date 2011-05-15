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

long long dp[5005];

int main()
{
    string s;
    while (cin>>s) {
        if (s=="0") break;
        memset(dp, 0, sizeof(dp));
        int n=(int)(s).size();
        dp[n]=1;
        for (int i=n-1; i>=0; --i) {
            if (s[i]>'0') dp[i]+=dp[i+1];
            if (i<n-1 && s[i]>'0' && s[i]<='2' && s[i]<='6')
                dp[i]+=dp[i+2];
        }
        cout<<dp[0]<<endl;
    }
}
