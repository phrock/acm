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


int main()
{
    int n;
    cin>>n;
    set<int> st;
    for (int i=0; i<n; ++i) { int x; cin>>x; st.insert(x); }
    map<int, int> ab, ef, abc, def;
    for (__typeof((st).begin()) i=(st).begin(); i!=(st).end(); ++i) {
        int a=*i;
        for (__typeof((st).begin()) j=(st).begin(); j!=(st).end(); ++j) {
            int b=*j;
            ab[a*b]++;
            ef[a+b]++;
        }
    }
    for (__typeof((ab).begin()) i=(ab).begin(); i!=(ab).end(); ++i)
        for (__typeof((st).begin()) j=(st).begin(); j!=(st).end(); ++j) 
            abc[i->first+*j]+=i->second;
    for (__typeof((st).begin()) i=(st).begin(); i!=(st).end(); ++i) {
        if (!*i) continue;
        for (__typeof((ef).begin()) j=(ef).begin(); j!=(ef).end(); ++j)
            def[*i*(j->first)]+=j->second;
    }

    int res=0;
    for (__typeof((abc).begin()) i=(abc).begin(); i!=(abc).end(); ++i)
        if (((def).find(i->first)!=(def).end()))
            res+=i->second*def[i->first];
    // for (__typeof((def).begin()) i=(def).begin(); i!=(def).end(); ++i)
    //     if (((abc).find(i->first)!=(abc).end()))
    //         res+=i->second*abc[i->first];

    cout<<res<<endl;
}
