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


int main()
{
    double pi = acos(-1);
    cout << setiosflags(ios::fixed) << setprecision(3);
    int w, h;
    while (cin >> w >> h && w) {
        double a = w, b = h;
        double x = min(a, b / (pi + 1));
        double r = x / 2;
        double v1 = pi * r * r * a;
        x = a / pi;
        r = x / 2;
        double v2 = pi * r * r * (b - x);
        x = min(a / pi, b * 2 / 3);
        r = x / 2;
        double v3 = pi * r * r * (b - x);
        // cout << v1 << " " << v2 << " " << v3 << endl;
        cout << max(v1, max(v2, v3)) << endl;
    }
}
