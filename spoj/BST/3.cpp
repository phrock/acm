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
#include "/home/rock/program/acm/topcoder/libs/debug.cpp"
#endif

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

const int MAX = 300005;
long long a[MAX];
int b[MAX];

int main()
{
    int n, x;
    long long res = 0;
    scanf("%d", &n);
    scanf("%d", &x);
    a[x] = 1;
    printf("%lld\n", res);
    for (int i = 1; i < n; ++i) {
        scanf("%d", &x);
        int p = x, q = x, f1 = 1, f2 = 1;
        while (true) {
            --p, ++q;
            if (p == 0) f1 = 0;
            if (q == n + 1) f2 = 0;
            if (f1 && a[p]) {
                f1 = 0;
                if ((b[p] & 2) == 0) {
                    res += a[p];
                    a[x] = a[p] + 1;
                    b[p] |= 2;
                    break;
                }
            }
            if (f2 && a[q]) {
                f2 = 0;
                if ((b[q] & 1) == 0) {
                    res += a[q];
                    a[x] = a[q] + 1;
                    b[q] |= 1;
                    break;
                }
            }
        }
        printf("%lld\n", res);
    }
}
