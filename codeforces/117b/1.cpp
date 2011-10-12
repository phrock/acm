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

int p[10000005];

int main()
{
    long long a, b, m;
    cin >> a >> b >> m;
    if (b >= m) {
        cout << 2 << endl;
        return 0;
    }
    long long res = 0;
    while (true) {
        ++res;
        long long x = res * 1e9, y = x + b;
        x %= m, y %= m;
        if (res > a || p[x]) {
            cout << 2 << endl;
            return 0;
        } else {
            p[x] = 1;
        }
        #ifdef DEBUG
        cout << res << " " << x << " " << y << endl;        
        #endif
        if (x > 0 && y >= x) {
            cout << 1 << " " << setw(9) << setfill('0') << res << endl;
            break;
        }
    }
}
