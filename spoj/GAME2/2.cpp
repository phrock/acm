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

long long func(vector<int> &v, int x)
{
    
    int y = 1, cur = 0;
    while (y <= x) {
        if (x & y) --v[cur];
        y <<= 1;
        ++cur;
    }
    long long res = 0;
    for (int i = 0; i < x; ++i) {
        int y = 1, cur = 0;
        bool ok = true;
        while (y <= i) {
            if (((i & y) && (v[cur] % 2 == 0)) ||
                (!(i & y) && (v[cur] % 2 == 1))) {
                ok = false;
                break;
            }
            y <<= 1;
            ++cur;
        }
        if (ok) ++res;
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ++ti) {
        int n, x, max_num = -1, max_cnt = 0;
        vector<int> v(22);
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%x", &x);
            if (x > max_num) {
                max_num = x;
                max_cnt = 1;
            } else if (x == max_num) {
                ++max_cnt;
            }
            int y = 1, cur = 0;
            while (y <= x) {
                if (x & y) ++v[cur];
                y <<= 1;
                ++cur;
            }
        }
        #ifdef DEBUG
        print(v);        
        #endif
        bool ok = false;
        for (int i = 0; i < (int)(v).size(); ++i)
            if (v[i] % 2) {
                ok = true;
                break;
            }
        cout << (ok ? max_cnt * func(v, max_num) : 0) << endl;
    }
}
