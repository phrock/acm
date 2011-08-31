/*
  ID:   aphrodi1
  LANG: C++
  PROG: nuggets
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

ifstream fin("nuggets.in");
ofstream fout("nuggets.out");
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

const int MAX = 300;
int dp[MAX];

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort((v).begin(), (v).end());
    int g = v[0];
    for (int i = 0; i < n; ++i)
        g = __gcd(g, v[i]);
    if (g > 1 || v[0] == 1) {
        cout << 0 << endl;
        return 0;
    }
    int res = v[0] - 1;
    dp[0] = 1;
    int length = 1;
    int x = 1;
    while (true) {
        bool ok = false;
        for (int i = 0; i < n; ++i)
            if (dp[(x + MAX - v[i]) % MAX]) {
                ok = true;
                break;
            }
        if (ok) {
            dp[x % MAX] = 1;
            ++length;
            if (length == v[0])
                break;
        } else {
            dp[x % MAX] = 0;
            length = 0;
            res = x;
        }
        // cout << x << " " << ok << " " << length << endl;
        ++x;
    }
    cout << res << endl;
}
