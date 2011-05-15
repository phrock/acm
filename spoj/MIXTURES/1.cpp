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

int a[110];
int dp[110][110][110];          // start, len, color -> smoke

int main()
{
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> a[i];
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; ++i) dp[i][1][a[i]] = 0;
        for (int len = 2; len <= n; ++len)
            for (int i = 0; i < n - len + 1; ++i)
                for (int left = 1; left < len; ++left) {
                    int j = i + left, right = len - left;
                    for (int color1 = 0; color1 < 100; ++color1) {
                        if (dp[i][left][color1] == -1) continue;
                        for (int color2 = 0; color2 < 100; ++color2) {
                            if (dp[j][right][color2] == -1) continue;
                            int color = (color1 + color2) % 100;
                            if (dp[i][len][color] == -1) dp[i][len][color] = dp[i][left][color1] + dp[j][right][color2] + color1 * color2;
                            else dp[i][len][color] = min(dp[i][len][color], dp[i][left][color1] + dp[j][right][color2] + color1 * color2);
                        }
                    }
                }
        int res = INT_MAX;
        for (int i = 0; i < 100; ++i) if (dp[0][n][i] != -1) res = min(res, dp[0][n][i]);
        cout << res << endl;
    }
}
