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
    long long x, y;
    cin >> n >> x >> y;
    if (n > y) {
        cout << -1 << endl;
        return 0;
    }
    long long res = y - (n - 1);
    if (res * res + n - 1 >= x) {
        cout << res;
        for (int i = 0; i < n - 1; ++i)
            cout << " " << 1;
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}
