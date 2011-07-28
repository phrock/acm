/*
  ID:   aphrodi1
  LANG: C++
  PROG: beads
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

ifstream fin("beads.in");
ofstream fout("beads.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();

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
    //////////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;
    string s;
    cin >> s;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        rotate(s.begin(), s.begin() + 1, s.end());
        int cnt = 0;
        char c = s[0];
        for (int j = 0; j < (int)(s).size(); ++j) {
            if (c == 'w') {
                c = s[j];
                ++cnt;
            } else {
                if (s[j] != 'w' && s[j] != c)
                    break;
                else
                    ++cnt;
            }
        }
        c = s[(int)(s).size() - 1];
        for (int j = (int)(s).size() - 1; j >= 0; --j) {
            if (c == 'w') {
                c = s[j];
                ++cnt;
            } else {
                if (s[j] != 'w' && s[j] != c)
                    break;
                else
                    ++cnt;
            }
        }
        res = max(res, min(cnt, n));
    }
    cout << res << endl;
}
