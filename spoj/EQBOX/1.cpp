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

bool check(long long a, long long b, long long x, long long y)
{
    if (x < a && y < b) return true;
    if (x >= a && y >= b) return false;
    double beta = atan2(y, x);
    double alpha = asin(b / sqrt(x * x + y * y)) - beta;
    if (alpha < 0) return false;
    double p = y * sin(alpha), q = sqrt(x * x + y * y - b * b);
    if (2 * p + q - a >= 0) return false;
    else return true;
}

int main()
{
    int T, a, b, x, y;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ++ti) {
        scanf("%d%d%d%d", &a, &b, &x, &y);
        if (check(max(a, b), min(a, b), max(x, y), min(x, y)))
            puts("Escape is possible.");
        else puts("Box cannot be dropped.");
    }
}
