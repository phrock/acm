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

const int MAX = 10000;
int v[MAX + 5];

int main()
{
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    if (m != n - 1) {
        puts("NO");
        return 0;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        if (v[a] && v[b]) {
            puts("NO");
            return 0;
        } else {
            v[a] = v[b] = 1;
        }
    }
    puts("YES");
}
