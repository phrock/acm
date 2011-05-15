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

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

int a[100005];
int b[100005];
int c[100005];
int p[100005];
int dp[100005];

bool cmp(int x, int y)
{
    if (a[x] != a[y]) return a[x] < a[y];
    if (b[x] != b[y]) return b[x] < b[y];
    if (c[x] != c[y]) return c[x] < c[y];
    return true;
}

int main()
{
    int T, n;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ++ti) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d%d%d", &a[i], &b[i], &c[i]), p[i] = i;
        sort(p, p+n, cmp);
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j)
                if (b[p[i]] >= b[p[j]] && c[p[i]] >= c[p[j]])
                    dp[i] = max(dp[i], dp[j]);
            ++dp[i];
        }
        cout << *max_element(dp, dp + n) << endl;
    }
}
