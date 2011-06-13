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
    string s;
    while (cin >> s && s != "*") {
        int n = (int)(s).size();
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            a[i] = s[i - 1] == 'Y' ? 1 : 0;
        if (!a[1]) {
            cout << -1 << endl;
            continue;
        }
        bool ok = true;
        for (int i = 1; i <= n; ++i)
            for (int j = i; j <= n; ++j) {
                if (a[i] && a[j] && i * j <= n && !a[i * j])
                    ok = false;
                if (j % i == 0 && !a[i] && a[j])
                    ok = false;
            }
        if (!ok) {
            cout << -1 << endl;
            continue;
        }
        long long res = 1;
        for (int i = n; i >= 1; --i)
            if (a[i] && res % i)
                res *= i;
        cout << res << endl;
    }
}
