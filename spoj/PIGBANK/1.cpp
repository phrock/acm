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

const int MAX = INT_MAX/2;
int w[505], p[505], dp[10005];

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int E, F;
        cin >> E >> F;
        int m = F - E;
        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> p[i] >> w[i];
        dp[0] = 0;
        for (int i = 1; i <= m; ++i)
            dp[i] = MAX;
        for (int i = 0; i < n; ++i)
            for (int j = w[i]; j <= m; ++j)
                dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
        if (dp[m] == MAX) cout << "This is impossible." << endl;
        else cout << "The minimum amount of money in the piggy-bank is " << dp[m] << "." << endl;
    }
}
