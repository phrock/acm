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

const int MAX = 1000000;
long double res[MAX];

int main()
{
    res[1] = (long double)2 / 3;
    int a = 1, b = 2, c = 3;
    for (int i = 2; i < MAX; ++i) {
        ++a, ++b, ++c;
        res[i] += res[i - 1] + (long double)1 / a / b / c;
    }
    int T;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ++ti) {
        int n;
        scanf("%d", &n);
        if (n < MAX) printf("%.11Lf\n", res[n]);
        else printf("%.11Lf\n", res[MAX - 1]);
    }
}
