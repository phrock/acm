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

int v[505], a[2][505];

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        memset(a, 0, sizeof(a));
        a[0][0] = 1;
        int dis = 1, cur = 0;
        while (k) {
            if (k & 1) {
                for (int i = 0; i < n; ++i)
                    a[1 - cur][i] = a[cur][i] ^ a[cur][(i + dis) % n] ^ a[cur][(i + n - dis) % n];
                cur = 1 - cur;
            }
            k >>= 1;
            dis = (dis << 1) % n;
        }
        for (int i = 0; i < n; ++i) {
            if (i) cout << " ";
            int res = 0;
            for (int j = 0; j < n; ++j) {
                if (a[cur][j]) res ^= v[(i + j) % n];
            }
            cout << res;
        }
        cout << endl;
    }
}
