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
    int idx = 1;
    int n;
    while (cin >> n) {
        if (!n) break;
        cout << "Game " << idx++ << ":" << endl;
        vector<int> s(n), g(n);
        for (int i = 0; i < n; ++i)
            cin >> s[i];
        while (true) {
            for (int i = 0; i < n; ++i)
                cin >> g[i];
            if (!g[0])
                break;
            int strong = 0, weak = 0;
            vector<int> a(10), b(10);
            for (int i = 0; i < n; ++i) {
                if (s[i] == g[i]) {
                    ++strong;
                } else {
                    ++a[s[i]];
                    ++b[g[i]];
                }
            }
            for (int i = 1; i <= 9; ++i)
                weak += min(a[i], b[i]);
            cout << "    (" << strong << "," << weak << ")" << endl;
        }
    }
}
