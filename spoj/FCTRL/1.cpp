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

int func(long long n)
{
    long long x=5;
    int res=0;
    while (x<=n) {
        res+=n/x;
        x*=5;
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    for (int ti=0; ti<t; ++ti) {
        int n;
        cin>>n;
        cout<<func(n)<<endl;
    }
}
