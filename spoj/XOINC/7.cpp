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

const int MAX = 2005;
int a[MAX], dp[MAX][MAX], cache[MAX][MAX], idx[MAX], upper[MAX];

void init_upper()
{
    int idx = 1, aux = 2;
    while (idx < MAX) {
        for (int i = 0; i < aux; ++i) {
            upper[idx++] = aux;
            if (idx == MAX) break;
        }
        aux <<= 1;
    }
}

int main()
{
    init_upper();
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[n - i]);
    for (int i = 1; i <= n; ++i)
        a[i] += a[i - 1];

    for (int i = 1; i <= n; ++i)
        idx[i] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= min(i, upper[i]); ++j) {
            int aux = min(2 * j, i - j), start = 1;
            if (aux >= idx[i - j]) start = idx[i - j];
            else { dp[i][j] = a[i] - cache[i - j][aux]; continue; }
            for (int k = start; k <= aux; ++k)
                cache[i - j][k] = max(cache[i - j][k - 1], dp[i - j][k]);
            idx[i - j] = aux;
            dp[i][j] = a[i] - cache[i - j][aux];
        }
    #ifdef DEBUG
    print2(dp, n + 1, n + 1);    
    #endif
    cout << max(dp[n][1], dp[n][2]) << endl;
}
