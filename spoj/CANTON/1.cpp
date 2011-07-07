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

int a[1000000];
int n;

int main()
{
    n = 1;
    int sum = 0;
    while (sum <= 10000000) {
        sum += n;
        a[n++] = sum;
    }
    // cout << n << endl;
    #ifdef DEBUG
    print(a, 10);
    #endif

    int ts;
    cin >> ts;
    for (int ti = 0; ti < ts; ++ti) {
        int x;
        cin >> x;
        int idx = lower_bound(a, a + n, x) - a;
        int diff = a[idx] - x;
        int p, q;
        if (idx % 2 == 1) {
            p = 1 + diff;
            q = idx - diff;
        } else {
            p = idx - diff;
            q = 1 + diff;
        }
        cout << "TERM " << x << " IS " << p << "/" << q << endl;
    }
}
