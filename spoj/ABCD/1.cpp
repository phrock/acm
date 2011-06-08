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
#include "/home/rock/program/acm/topcoder/libs/debug.cpp"
#endif

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

char color[4] = {'A', 'B', 'C', 'D'};
int cnt[4];

void dfs(int cur, int n, string &res, const string &s)
{
    if (cur == n) {
        cout << res << endl;
        exit(0);
    }
    for (int i = 0; i < 4; ++i) {
        if (!cnt[i] || color[i] == s[cur] || (cur && color[i] == res[cur - 1]))
            continue;
        --cnt[i];
        res[cur] = color[i];
        dfs(cur + 1, n, res, s);
        ++cnt[i];
    }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < 4; ++i)
        cnt[i] = n;
    string s;
    cin >> s;
    for (int i = 0; i < (int)(s).size(); ++i)
        --cnt[s[i] - 'A'];
    string res(2 * n, ' ');
    dfs(0, 2 * n, res, s);
}
