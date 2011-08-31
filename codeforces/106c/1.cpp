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


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m + 1), b(m + 1), c(m + 1), d(m + 1);
    cin >> c[0] >> d[0];
    for (int i = 1; i <= m; ++i)
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    vector<int> dp(n + 1);
    for (int i = 1; i <= m; ++i)
        for (int times = 0; times < a[i] / b[i]; ++times)
            for (int j = n; j >= c[i]; --j)
                dp[j] = max(dp[j], dp[j - c[i]] + d[i]);
    for (int i = c[0]; i <= n; ++i)
        dp[i] = max(dp[i], dp[i - c[0]] + d[0]);
    cout << *max_element((dp).begin(), (dp).end()) << endl;
}
