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

int a[26];

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n, m, k;
        string s, res;
        cin >> n >> m >> k >> s;
        for (int i = 0; i < m; ++i) {
            fill(a, a + k, 0);
            for (int j = 0; j + m <= (int)(s).size(); ++j)
                ++a[s[i + j] - 'a'];
            int idx = 0, aux = a[0];
            for (int j = 1; j < k; ++j)
                if (a[j] < aux) {
                    aux = a[j];
                    idx = j;
                }
            res += char('a' + idx);
        }
        cout << res << endl;
    }
}
