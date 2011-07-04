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
    int a[20];
    a[0] = 5;
    for (int i = 1; i < 20; ++i)
        a[i] = a[i - 1] * 5;
    #ifdef DEBUG
    print(a, 20);    
    #endif
    int T, n;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        cin >> n;
        int cur = 0;
        int res = 0;
        while (n) {
            if (n % 2) res += a[cur];
            n /= 2;
            ++cur;
        }
        cout << res << endl;
    }
}
