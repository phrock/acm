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

int p[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int q[] = {-1, 1, -2, 2, -2, 2, -1, 1};

void dfs(vector<vector<int> > &g, int x, int y, int cnt, int &res)
{
    res = max(res, cnt);
    for (int i = 0; i < 8; ++i) {
        if (x + p[i] >= 0 && y + q[i] >=0 && x + p[i] < 10 && y + q[i] < 10 && g[x + p[i]][y + q[i]] == 1) {
            g[x + p[i]][y + q[i]] = 2;
            dfs(g, x + p[i], y + q[i], cnt + 1, res);
            g[x + p[i]][y + q[i]] = 1;
        }
    }
}
            

int main()
{
    int cnt = 0, n;
    while (cin >> n && n) {
        vector<vector<int> > g(10, vector<int>(10));
        int total = 0;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            total += y;
            for (int j = 0; j < y; ++j)
                g[i][x + j] = 1;
        }
        int x = -1, y = -1;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < 10; ++j)
                if (x == -1 && g[i][j]) {
                    x = i;
                    y = j;
                }
        int res = 0;
        g[x][y] = 2;
        dfs(g, x, y, 1, res);
        cout << "Case " << ++cnt << ", "
             << total - res
             << (total - res == 1 ? " square " : " squares ")
             << " can not be reached." << endl;
    }
}
