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

const int MAX = 10000;
vector<int> g[MAX + 5];
int v[MAX + 5], pre[MAX + 5];

int main()
{
    int n, m, a, b;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bool ok = true;
    queue<int> q;
    q.push(1);
    v[1] = 1;
    while (!q.empty()) {
        int ft = q.front();
        q.pop();
        for (int i = 0; i < (int)(g[ft]).size(); ++i) {
            if (v[g[ft][i]]) {
                if (g[ft][i] != pre[ft]) {
                    ok = false;
                    break;
                }
            } else {
                v[g[ft][i]] = 1;
                pre[g[ft][i]] = ft;
                q.push(g[ft][i]);
                --n;
            }
        }
    }

    cout << (ok && n == 1 ? "YES" : "NO") << endl;
}
