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
char a[MAX], b[MAX];
int dp_max[2][MAX], dp_min[2][MAX];

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n, m;
        scanf("%d%s%d%s", &n, a, &m, b);
        memset(dp_max, 0, sizeof(dp_max));
        memset(dp_min, 0, sizeof(dp_min));
        for (int i = 2; i <= m; ++i)
            dp_min[0][i] = INT_MAX / 2;
        dp_min[0][0] = dp_min[1][0] = INT_MAX / 2;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                dp_max[i % 2][j] = max(dp_max[i % 2][j - 1], dp_max[1 - i % 2][j]) + (a[i - 1] == '1' && b[j - 1] == '1' ? 1 : 0);
                dp_min[i % 2][j] = min(dp_min[i % 2][j - 1], dp_min[1 - i % 2][j]) + (a[i - 1] == '1' && b[j - 1] == '1' ? 1 : 0);
                // cout << i << " " << j <<": "<<dp_max[i %2][j] << " " <<dp_min[i % 2][j]<<endl;
            }
        cout << dp_max[n % 2][m] << " " << dp_min[n % 2][m] << endl;
    }
}
