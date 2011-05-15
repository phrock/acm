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

// P1=(ap)2(-a2+b2+c2-p2+q2+r2)
// P2=(bq)2(a2-b2+c2+p2-q2+r2)
// P3=(cr)2(a2+b2-c2+p2+q2-r2)
// P=(abr)2+(acq)2+(bcp)2+(pqr)2
// V=√(P1+P2+P3–P)/12。

int main()
{
    int n;
    cin>>n;
    for (int i=0; i<n; ++i) {
        long double a, b, c, p, q, r, t1, t2, t3, t, v;
        // cin>>a>>b>>c>>p>>q>>r;
        cin>>a>>b>>c>>r>>q>>p;
        t1=(a*a*p*p)*(-a*a+b*b+c*c-p*p+q*q+r*r);
        t2=(b*b*q*q)*(a*a-b*b+c*c+p*p-q*q+r*r);
        t3=(c*c*r*r)*(a*a+b*b-c*c+p*p+q*q-r*r);
        t=(a*a*b*b*r*r)+(a*a*c*c*q*q)+(b*b*c*c*p*p)+(p*p*q*q*r*r);
        v=sqrtl(t1+t2+t3-t)/12;
    
        cout<<setiosflags(ios::fixed)<<setprecision(4);
        cout<<v<<endl;
    }
}
