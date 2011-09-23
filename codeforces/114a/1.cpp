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
    int k, l;
    cin >> k >> l;
    if (l < k) {
        cout << "NO" << endl;
        return 0;
    }
    int cnt = 0;
    while (l != 1 && l % k == 0) {
        l /= k;
        ++cnt;
    }
    if (l == 1) {
        cout << "YES" << endl;
        cout << cnt - 1 << endl;
    } else {
        cout << "NO" << endl;
    }
}
