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

int n, m, k, cur;
string s, res;
char c[105];

void dfs(int len)
{
    // cout << string(c, c + len) << endl;
    if (!res.empty()) return;
    if (len > m) return;
    if (s.find(string(c, c + len)) == string::npos) {
        res = string(c, c + len);
        return;
    }
    if (c[cur] - 'a' + 1 < k) {
        ++c[cur];
        dfs(len);
        --c[cur];
    }
    if (cur + 1 < len) {
        ++cur;
        ++c[cur];
        dfs(len);
        --c[cur];
        --cur;
    }
    if (len < m) {
        dfs(len + 1);
    }
}

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        cin >> n >> m >> k >> s;
        cur = 0;
        res = "";
        for (int i = 0; i < m; ++i) c[i] = 'a';
        dfs(1);
        cout << res << endl;
    }
}
