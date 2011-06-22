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

long long dp[6000006];

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n, k;
        cin >> n >> k;
        if (n > k || n * 6 < k) {
            cout << 0 << endl;
            continue;
        }
        k -= n;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        r
}
