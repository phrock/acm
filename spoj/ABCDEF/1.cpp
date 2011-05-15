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
    map<int, int> ab, ef;
    for (__typeof((st).begin()) i=(st).begin(); i!=(st).end(); ++i) {
        int a=*i;
        for (__typeof((st).begin()) j=(st).begin(); j!=(st).end(); ++j) {
            int b=*j;
            ab[a*b]++;
            ef[a+b]++;
        }
    }
    #ifdef DEBUG
    print(st);
    printp(ab);
    #endif
    int res=0;
    for (__typeof((ab).begin()) i=(ab).begin(); i!=(ab).end(); ++i) {
        int x=i->first, cnt=i->second;
        for (__typeof((st).begin()) j=(st).begin(); j!=(st).end(); ++j) {
            int c=*j;
             for (__typeof((st).begin()) k=(st).begin(); k!=(st).end(); ++k) {
                int d=*k;
                if (!d || (x+c)%d) continue;
                int aux=(x+c)/d;
                if (((ef).find(aux)!=(ef).end()))
                    res+=cnt*ef[aux];
             }
        }
    }

    cout<<res<<endl;
}
