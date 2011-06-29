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

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n, m;
        scanf("%d%s%d%s", &n, a, &m, b);
        int cnta = 0, cntb = 0;
        bool za = false, zb = false;
        int za1 = INT_MAX, za2 = INT_MAX, zb1 = INT_MAX, zb2 = INT_MAX;
        for (int i = 0; i < n; ++i)
            if (a[i] == '1')
                ++cnta;
            else {
                za = true;
                za1 = min(za1, i);
                za2 = min(za2, n - i - 1);
            }
        for (int i = 0; i < m; ++i)
            if (b[i] == '1')
                ++cntb;
            else {
                zb = true;
                zb1 = min(zb1, i);
                zb2 = min(zb2, m - i - 1);
            }
        if (!cnta || !cntb) {
            cout << 0 << " " << 0 << endl;
        } else {
            int m = INT_MAX;
            if (!za && !zb) m = cnta + cntb - 1;
            else {
                if (za) m = min(m, cntb);
                if (zb) m = min(m, cnta);
            }
            if (za && zb) m = min(m, (min(za1, zb1) + min(za2, zb2)));
            cout << cnta + cntb - 1 << " " << m << endl;
        }
    }
}
