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

int n, a, b, x[10];
double det, res;

void dfs(int cur, int p, int q)
{
    if (cur == n) {
        int left = max(a, p), right = min(b, q);
        if (left < right)
            res += 1. * (right - left) / (q - p);
        return;
    }
    for (int i = -x[cur]; i < x[cur]; ++i)
        dfs(cur + 1, p + i, q + i + 1);
}

int main()
{
    cout << setiosflags(ios::fixed) << setprecision(9);
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        cin >> n >> a >> b;
        for (int i = 0; i < n; ++i)
            cin >> x[i];
        det = 1;
        res = 0;
        dfs(0, 0, 0);
        for (int i = 0; i < n; ++i)
             det *= 1. / 2 / x[i];
        cout << res * det << endl;
    }
}
