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
    int n;
    cin >> n;
    vector<int> v(100000 + 1), res(n + 1);
    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        int cnt = 0;
        for (int j = 1; j * j <= x; ++j) {
            if (x % j == 0) {
                if (v[j] < i - y)
                    ++cnt;
                v[j] = i;
                if (j * j < x && v[x / j] < i - y)
                    ++cnt;
                v[x / j] = i;
            }
        }
        res[i] = cnt;
    }
    for (int i = 1; i <= n; ++i)
        cout << res[i] << endl;
}
