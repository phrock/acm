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

int a[105];

int main()
{
    int T, n;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        cin >> n;
        int cnt = 0;
        for (int i = 0; i < n; ++i) cin >> a[i+1];
        for (int i = 1; i <= n; ++i) cnt += a[i] / i;
        cout << (cnt % 2 ? "ALICE" : "BOB") << endl;
    }
}
