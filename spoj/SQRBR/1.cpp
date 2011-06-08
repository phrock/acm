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

int a[50];
long long dp[50][50];

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        memset(a, 0, sizeof(a));
        memset(dp, 0, sizeof(dp));
        int n, k, x;
        cin >> n >> k;
        for (int i = 0; i < k; ++i) {
            cin >> x;
            a[x] = 1;
        }
        for (int i = 2; i <= 2 * n; ++i)
            if (!a[i]) dp[i - 1][i] = 1;
        for (int len = 4; len <= 2 * n; len += 2)
            for (int i = 1; i + len - 1 <= 2 * n; ++i) {
                int j = i + len - 1;
                if (a[j]) continue;
                dp[i][j] += dp[i][i + 1] * dp[i + 2][j];
                dp[i][j] += dp[i + 1][j - 1];
                // cout <<dp[i][j]<<endl;
                for (int k = i + 2; k < j; ++k)
                    dp[i][j] += dp[i + 1][k - 1] * dp[k + 1][j];
                // cout << i << " "  << j << "  : " << dp[i][j]<<endl;
            }
        cout << dp[1][2 * n] << endl;
    }
}
