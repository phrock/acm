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

const int MAXN = 100000;
const int MAXK = 64;
// f[i][j] means: i --- i + 2 ^ j - 1
int dp_min[MAXN][MAXK];
int dp_max[MAXN][MAXK];

int seq[MAXN];

void st_min(int seq[], int n)
{
    int k = (int)log2(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= k; ++j)
            dp_min[i][j] = INT_MAX;

    for (int i = 0; i < n; ++i)
        dp_min[i][0] = seq[i];

    for (int j = 1; j <= k; ++j)
        for (int i = 0; i + (1 << j) - 1 < n; ++i)
            dp_min[i][j] = min(dp_min[i][j - 1], dp_min[i + (1 << (j - 1))][j - 1]);
}

void st_max(int seq[], int n)
{
    int k = (int)log2(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= k; ++j)
            dp_max[i][j] = INT_MIN;

    for (int i = 0; i < n; ++i)
        dp_max[i][0] = seq[i];

    for (int j = 1; j <= k; ++j)
        for (int i = 0; i + (1 << j) - 1 < n; ++i)
            dp_max[i][j] = max(dp_max[i][j - 1], dp_max[i + (1 << (j - 1))][j - 1]);
}

int rmq_min(int a, int b)
{
    int k = (int)log2(b - a + 1);
    return min(dp_min[a][k], dp_min[b - (1 << k) + 1][k]);
}

int rmq_max(int a, int b)
{
    int k = (int)log2(b - a + 1);
    return max(dp_max[a][k], dp_max[b - (1 << k) + 1][k]);
}

int main()
{
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; ++i)
        scanf("%d", &seq[i]);
    st_min(seq, n);
    st_max(seq, n);
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        --a, --b;
        printf("%d\n", rmq_max(a, b) - rmq_min(a, b));
    }
}
