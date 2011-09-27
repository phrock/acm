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

int ceil(int a, int b)
{
    return (a + b - 1) / b;
}

int main()
{
    int n, m;
    cin >> n >> m;
    --m;
    int cycle = 2 * m;
    for (int i = 0; i < n; ++i) {
        int s, f, t;
        cin >> s >> f >> t;
        --s, --f;
        if (s == f) {
            cout << t << endl;
        } else if (s < f) {
            int aux = 2 * ceil(t - s, cycle) * m + s;
            cout << aux + (f - s) << endl;
        } else {
            int aux = (2 * ceil(t - (m - s) - m, cycle) + 1) * m + (m - s);
            cout << aux + (s - f) << endl;
        }
    }
}
