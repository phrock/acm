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
        vector< vector<int> > a(n + 1, vector<int>(n + 1));
        for (int i = 1; i <= n; ++i) {
            int x = i, p = 2;
            while (x != 1) {
                int cnt = 0;
                while (x % p == 0) {
                    ++cnt;
                    x /= p;
                }
                a[i][p] = cnt;
                ++p;
            }
        }
        vector<int> b(n + 1);
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'Y') {
                for (int j = 2; j <= i; ++j)
                    b[j] = max(b[j], a[i][j]);
            }
        }
        #ifdef DEBUG
        print(b);        
        #endif
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'N') {
                bool check = true;
                for (int j = 1; j <= i; ++j)
                    if (a[i][j] > b[j]) {
                        check = false;
                        break;
                    }
                if (check) {
                    ok = false;
                    break;
                }
            }
        }
        if (!ok) { cout << -1 << endl; continue; }
        long long res = 1;
        for (int i = 1; i <= n; ++i)
            for (int j = 0; j < b[i]; ++j)
                res *= i;
        cout << res << endl;
    }
}
