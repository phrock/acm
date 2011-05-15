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

int main()
{
    int T;
    cin>>T;
    for (int ti=0; ti<T; ++ti) {
        int n;
        cin>>n;
        int x;
        vector<int> v;
        while (cin>>x) {
            if (!x) break;
            x/=100;
            v.push_back(x);
        }
        if (ti) cout<<endl;

        memset(dp, 0, sizeof(dp));
        for (int i=0; i<(int)(v).size(); ++i) {
            bool ok=false;
            for (int p=0; p<=n; ++p)
                for (int q=0; q<=n; ++q) {
                    if (p>=v[i]) {
                        ok=true;
                        dp[p][q]=i+1;
                    }
                    if (q>=v[i]) {
                        ok=true;
                        dp[p][q]=i+1;
                    }
                }
            if (!ok) break;
        }

        int res=0;
        for (int i=0; i<=n; ++i)
            for (int j=0; j<=n; ++j)
                res=max(res, dp[i][j]);
        cout<<res<<endl;
        #ifdef DEBUG
        print2(dp, n+1, n+1);        
        #endif
    }
}
