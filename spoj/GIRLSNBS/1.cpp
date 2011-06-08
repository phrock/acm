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
#include "/home/rock/program/acm/topcoder/libs/debug.cpp"
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
    int a, b;
    while (cin >> a >> b && a != -1) {
        if (a > b) swap(a, b);
        if (!a) { cout << b << endl; continue; }
        int res = INT_MAX;
        for (int i = 1; i <= a; ++i) {
            int x = (a + (i - 1)) / i;
            int y = (b + i) / (i + 1);
            res = min(res, max(x, y));
        }
        cout << res << endl;
    }
}
