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

long long a[100], b[100];
int n;

char p[] = {'2', '3', '5', '7'};

int main()
{
    n = 1;
    long long k = 4;
    long long sum = 0;
    while (sum <= 1e10) {
        sum += k;
        a[n++] = sum;
        k <<= 2;
    }
    b[0] = 1;
    for (int i = 1; i < n; ++i)
        b[i] = 4 * b[i - 1];
    #ifdef DEBUG
    cout << n << endl;
    print(a, 10);
    print(b, 10);
    #endif

    int ts;
    cin >> ts;
    for (int ti = 0; ti < ts; ++ti) {
        int x;
        cin >> x;
        int idx = lower_bound(a, a + n, x) - a;
        int cur = x - a[idx - 1] - 1;
        string res;
        for (int i = 1; i <= idx; ++i) {
            res = p[cur % 4] + res;
            cur >>= 2;
        }
        cout << res << endl;
    }
}
