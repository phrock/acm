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
#include "/home/Aphrodite/program/acm/topcoder/libs/debug.cpp"
#endif

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

long long a[63];

// f(0) = 1
// f(n) = (1 << n) + (f(0) + f(1) + f(2) + ... + f(n - 1))
long long func(long long x)
{
    long long res = 0, aux = 0;
    while (x) {
        if (x % 2) res += a[aux];
        x >>= 1;
        ++aux;
    }
    return res;
}

int main()
{
    a[0] = 1;
    for (int i = 1; i < 63; ++i) {
        a[i] = 1LL << i;
        for (int j = 0; j < i; ++j)
            a[i] += a[j];
    }
    long long x, y;
    cin >> x >> y;
    cout << func(y) - func(x - 1) << endl;
}
