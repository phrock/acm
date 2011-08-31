/*
  ID:   aphrodi1
  LANG: C++
  PROG: rockers
*/

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

ifstream fin("rockers.in");
ofstream fout("rockers.out");
streambuf *cin_buf = cin.rdbuf();
streambuf *cout_buf = cout.rdbuf();

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

bool check(int n, int t, int m, const vector<int> &v, int x)
{
    int remain = 0;
    for (int i = 0; i < n; ++i)
        if ((1 << i) & x) {
            if (v[i] <= remain) {
                remain -= v[i];
            } else if (m && v[i] <= t) {
                --m;
                remain = t - v[i];
            } else {
                return false;
            }
        }
    return true;
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int n, t, m;
    cin >> n >> t >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int res = 0;
    for (int i = 0; i < (1 << n); ++i)
        if (__builtin_popcount(i) > res && check(n, t, m, v, i))
            res = __builtin_popcount(i);
    cout << res << endl;
}
