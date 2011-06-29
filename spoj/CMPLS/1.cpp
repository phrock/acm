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

int a[105][105];

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n, c;
        scanf("%d%d", &n, &c);
        for (int i = 0; i < n; ++i)
            scanf("%d", &a[0][i]);
        for (int i = 1; i < n; ++i)
            for (int j = 0; i + j < n; ++j)
                a[i][j] = a[i - 1][j + 1] - a[i - 1][j];
        for (int i = 1; i <= c; ++i)
            a[n - 1][i] = a[n - 1][0];
        for (int i = n - 2; i >= 0; --i)
            for (int j = 0; j < c; ++j)
                a[i][n - i + j] = a[i][n - i + j - 1] + a[i + 1][n - i + j - 1];
        for (int i = 0; i < c; ++i) {
            if (i) printf(" ");
            printf("%d", a[0][n + i]);
        }
        printf("\n");
    }
}
