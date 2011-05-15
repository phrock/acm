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
    int t;
    cin>>t;
    for (int ti=0; ti<t; ++ti) {
        int a, b;
        cin>>a>>b;
        if (!a && b) { cout<<1<<endl; continue; }
        if (a && !b) { cout<<0<<endl; continue; }
        if (!a && !b) { cout<<1<<endl; continue; }
        b*=4;
        double res=0;
        if (a<=b) {
            res=0.5+0.5*(1.0*a/b*0.5);
        } else {
            res=0.5+0.5*(1.0*b/a*0.5+1.0*(a-b)/a);
        }
        cout<<setiosflags(ios::fixed)<<setprecision(9);
        cout<<res<<endl;
    }
}
