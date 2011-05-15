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
    int n, a, b, dir;
    cin>>n>>a>>b;
    string s1, s2, s;
    cin>>s1>>s2>>s;
    dir=s2=="head"?-1:1;

    int idx=0;
    for (idx=0; idx<(int)(s).size(); idx++) {
        #ifdef DEBUG
        cout<<dir<<" "<<a<<" "<<b<<endl;        
        #endif
        int p=b;
        if (p+dir==0 || p+dir==n+1) dir=-dir;
        int q=p+dir;
        b=q;
        if (s[idx]=='0') {
            if (a!=p && a!=q) continue;
            else if (a-1>=1 && a-1!=p && a-1!=q) { a=a-1; continue; }
            else if (a+1<=n && a+1!=p && a+1!=q) { a=a+1; continue; }
            break;
        } else {
            if (dir==-1) a=b+1;
            else a=b-1;
        }
    }
    if (idx<(int)(s).size())
        cout<<"Controller "<<idx+1<<endl;
    else cout<<"Stowaway"<<endl;
}
