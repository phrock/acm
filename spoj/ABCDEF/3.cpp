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
    map<int, int> ab, abc, abcd, ef;
    for (__typeof((st).begin()) i=(st).begin(); i!=(st).end(); ++i) {
        int a=*i;
        for (__typeof((st).begin()) j=(st).begin(); j!=(st).end(); ++j) {
            int b=*j;
            ab[a*b]++;
            ef[a+b]++;
        }
    }
    int res=0;
    for (__typeof((ab).begin()) i=(ab).begin(); i!=(ab).end(); ++i)
        for (__typeof((st).begin()) j=(st).begin(); j!=(st).end(); ++j) 
            abc[i->first+*j]+=i->second;
    for (__typeof((abc).begin()) i=(abc).begin(); i!=(abc).end(); ++i)
        for (__typeof((st).begin()) j=(st).begin(); j!=(st).end(); ++j) {
            if (!*j || i->first%*j) continue;
            abcd[i->first/(*j)]+=i->second;
        }
    for (__typeof((ef).begin()) i=(ef).begin(); i!=(ef).end(); ++i)
        if (((abcd).find(i->first)!=(abcd).end()))
            res+=i->second * abcd[i->first];
    cout<<res<<endl;
}
