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

int color[110][110];            // start, len
int dp[110][110];               // start, len -> smoke

int main()
{
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) cin >> color[i][1], dp[i][1] = 0;
        for (int len = 2; len <= n; ++len) {
            color[0][len] = (color[0][len-1] + color[len-1][1]) % 100;
            for (int i = len-1; i > 1; --i) color[len-i][i] = (color[0][len] + 100 - color[0][len-i]) % 100;
        }
        for (int i = 0; i < n; ++i)
            for (int len = 2; len <= n; ++len)
                dp[i][len] = INT_MAX / 3;
        for (int len = 2; len <= n; ++len)
            for (int i = 0; i < n - len + 1; ++i)
                for (int left = 1; left <= len; ++left) {
                    int j = i + left, right = len - left;
                    dp[i][len] = min(dp[i][len], dp[i][left] + dp[j][right] + color[i][left] * color[j][right]);
                }
        cout << dp[0][n] << endl;
    }
}
