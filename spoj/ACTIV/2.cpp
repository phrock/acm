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

const int MAX = 100005;
const long long MOD = 1e12;
pair<int, int> a[MAX];
long long dp[MAX];

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second < b.second;
}

int main()
{
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == -1) break;

        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
            scanf("%d%d", &a[i].first, &a[i].second);
        sort(a + 1, a + n + 1, cmp);
        for (int i = 1; i <= n; ++i) {
            pair<int, int> aux;
            aux.second = a[i].first;
            int k = upper_bound(a, a + i, aux, cmp) - a - 1;
            dp[i] = (dp[i - 1] + dp[k]) % MOD;
        }
        // printf("%08d\n", dp[n] - 1);
        string res = *({stringstream ss; ss << (dp[n] - 1); static string _; ss >> _; &_;});
        if ((int)(res).size() > 8) {
            res = res.substr((int)(res).size() - 8);
        } else {
            while ((int)(res).size() < 8) res = "0" + res;
        }
        cout << res << endl;
    }
}
