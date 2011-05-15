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
    int T;
    cin>>T;
    string a, plus, b, equal, c;
    int x, y, z;
    string machula="machula";

    for (int ti=0; ti<T; ++ti) {
        cin>>a>>plus>>b>>equal>>c;
        if (a.find(machula)!=string::npos) a.clear();
        else x=*({stringstream ss; ss<<(a); static int _; ss>>_; &_;});
        if (b.find(machula)!=string::npos) b.clear();
        else y=*({stringstream ss; ss<<(b); static int _; ss>>_; &_;});
        if (c.find(machula)!=string::npos) c.clear();
        else z=*({stringstream ss; ss<<(c); static int _; ss>>_; &_;});

        if (a.empty()) a=*({stringstream ss; ss<<(z-y); static string _; ss>>_; &_;});
        if (b.empty()) b=*({stringstream ss; ss<<(z-x); static string _; ss>>_; &_;});
        if (c.empty()) c=*({stringstream ss; ss<<(x+y); static string _; ss>>_; &_;});

        cout<<a<<" + "<<b<<" = "<<c<<endl;
    }
}
