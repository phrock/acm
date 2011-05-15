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

int dp[105];

int main()
{
    int T;
    cin>>T;
    for (int ti=0; ti<T; ++ti) {
        int n;
        cin>>n;
        n*=100;
        int x;
        vector<int> v;
        while (cin>>x) {
            if (!x) break;
            v.push_back(x);
        }
        vector<int> len=v;
        for (int i=1; i<(int)(len).size(); ++i) len[i]+=len[i-1];

        if (ti) cout<<endl;

        memset(dp, -1, sizeof(dp));
        dp[0]=0;

        int m=(int)(v).size();
        for (int i=1; i<=m; ++i)
            for (int j=0; j<=i; ++j)
                if (dp[j]!=-1 && dp[j]+v[i-1]<=n && )
    }
}
