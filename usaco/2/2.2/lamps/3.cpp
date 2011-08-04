/*
  ID:   aphrodi1
  LANG: C++
  PROG: lamps
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

ifstream fin("lamps.in");
ofstream fout("lamps.out");
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


int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int n, c;
    cin >> n >> c;
    vector<int> on, off;
    int x;
    while (cin >> x && x != -1)
        on.push_back(x - 1);
    while (cin >> x && x != -1)
        off.push_back(x - 1);

    set<string> st;
    for (int i = 0; i < (1 << 4); ++i) {
        int cnt = __builtin_popcount(i);
        if (cnt > c) continue;
        if ((c - cnt) % 2) continue;
        string s(n, '1');
        for (int j = 0; j < n; ++j) {
            if (i & 1) s[j] = s[j] == '1' ? '0' : '1';
            if ((j % 2 == 0) && (i & 2)) s[j] = s[j] == '1' ? '0' : '1';
            if ((j % 2 == 1) && (i & 4)) s[j] = s[j] == '1' ? '0' : '1';
            if ((j % 3 == 0) && (i & 8)) s[j] = s[j] == '1' ? '0' : '1';
        }
        bool ok = true;
        for (int j = 0; j < (int)(on).size(); ++j)
            if (s[on[j]] == '0') {
                ok = false;
                break;
            }
        for (int j = 0; j < (int)(off).size(); ++j)
            if (s[off[j]] == '1') {
                ok = false;
                break;
            }
        if (ok) st.insert(s);
    }
    if (st.empty()) cout << "IMPOSSIBLE" << endl;
    for (__typeof((st).begin()) i = (st).begin(); i != (st).end(); ++i)
        cout << *i << endl;
}
