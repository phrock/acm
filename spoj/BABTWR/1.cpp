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

int dp[100][100];

int main()
{
    int n;
    while (cin>>n && n) {
        set<int> st;
        map<pair<int, int>, int> mm;
        int x, y, z;
        for (int i=0; i<n; ++i) {
            cin>>x>>y>>z;
            st.insert(x), st.insert(y), st.insert(z);
            int p=x, q=y;
            if (p>q) swap(p, q);
            mm[make_pair(p, q)]=max(mm[make_pair(p, q)], z);
            p=x, q=z;
            if (p>q) swap(p, q);
            mm[make_pair(p, q)]=max(mm[make_pair(p, q)], y);
            p=y, q=z;
            if (p>q) swap(p, q);
            mm[make_pair(p, q)]=max(mm[make_pair(p, q)], x);
        }
        st.insert(INT_MAX);
        vector<int> a((st).begin(), (st).end());
        map<int, int> ms;
        for (__typeof((st).begin()) i=(st).begin(); i!=(st).end(); ++i)
            ms[*i]=find((a).begin(), (a).end(), *i)-a.begin();
        memset(dp, 0, sizeof(dp));
        #ifdef DEBUG
        printp(ms);        
        #endif
        for (int i=0; i<(int)(a).size(); ++i)
            for (int j=i; j<(int)(a).size(); ++j)
                for (__typeof((mm).begin()) k=(mm).begin(); k!=(mm).end(); ++k)
                    if (a[i]>k->first.first && a[j]>k->first.second)
                         dp[i][j]=max(dp[i][j], k->second+dp[ms[k->first.first]][ms[k->first.second]]);
        cout<<dp[(int)(a).size()-1][(int)(a).size()-1]<<endl;
    }
}
