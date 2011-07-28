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


int main()
{
    long long x;
    cin >> x;
    long long res = LLONG_MAX;
    for (int i = 1; i < (1 << 16); ++i) {
        long long aux = 0, k = 1;
        int n = __builtin_popcount(i), m = __builtin_clz(0) - __builtin_clz(i) - n;
        if (n < m) continue;
        int tmp = i;
        while (tmp) {
            if (tmp % 2) {
                aux += k * 7;
            } else {
                aux += k * 4;
            }
            k *= 10;
            tmp >>= 1;
        }
        for (int j = 0; j < n - m; ++j) {
            aux += k * 4;
            k *= 10;
        }
        if (aux >= x)
            res = min(res, aux);
    }
    cout << res << endl;
}
