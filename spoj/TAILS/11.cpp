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

const int MAX=20;

int a[MAX];

int func()
{
    int res = 0;
    int f1 = 0, f2 = 0;
    for (int i=0; i<MAX; ++i)
        if (a[i] ^ f1) res++, f1 = f2 ^ 1, f2 = 1;
        else f1 = f2, f2 = 0;
    return f1 ? INT_MAX/2 : res;
}

int main()
{
    for (int i=0; i<MAX; ++i) cin>>a[i];
    int res = func();
    if (a[0]) a[0] ^= 1, a[1] ^= 1, res = min(res, func() + 1);
    cout<<res<<endl;
}
