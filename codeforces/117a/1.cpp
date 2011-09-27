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

pair<int, int> need_time(int m, int start, int end, int dir)
{
    #ifdef DEBUG
    cout << start << " " << end << " " << dir << endl;    
    #endif
    if (dir == 1) {
        if (start <= end) {
            if (end == m)
                dir = -1;
            return make_pair(end - start, dir);
        }
        else {
            dir = end == 0 ? 1 : -1;
            return make_pair(2 * m - end - start, dir);
        }
    } else {
        if (start < end) {
            dir = end == m ? -1 : 1;
            return make_pair(start + end, dir);
        }
        else {
            if (end == 0)
                dir = 1;
            return make_pair(start - end, dir);
        }
    }
}


int main()
{
    int n, m;
    cin >> n >> m;
    --m;
    int cycle = 2 * m;
    for (int i = 0; i < n; ++i) {
        int s, f, t;
        cin >> s >> f >> t;
        --s, --f;
        if (s == f) {
            cout << t << endl;
            continue;
        }
        int start = t % cycle;
        int dir = 1;
        if (start >= m) {
            dir = -1;
            start = 2 * m - start;
        }
        pair<int, int> t1 = need_time(m, start, s, dir);
        pair<int, int> t2 = need_time(m, s, f, t1.second);
        cout << t + t1.first + t2.first << endl;
    }
}
