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

const int MOD = 314159;
const int MAX = 1000000;
int dp[MAX + 5][2];

int main()
{
    dp[0][0] = 1;
    dp[0][1] = 0;
    for (int i = 1; i <= MAX; ++i) {
        dp[i][0] = (dp[i - 1][1] + dp[i - 1][0] * 9) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1] * 9) % MOD;
    }
    int T, n;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        cin >> n;
        cout << dp[n][0] << endl;
    }
}
