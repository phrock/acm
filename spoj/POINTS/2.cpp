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

int a[100005];
int b[100005];
int c[100005];
int dp[100005];

struct node {
    int x;
    bool operator <(const node &a) const { return b[x] <= b[a.x] && c[x] <= c[a.x]; }
    // bool operator >(const node &a) const { return b[x] > b[a.x] || c[x] > c[a.x]; }
};

node g[100005];
node p[100005];

bool cmp(node x, node y)
{
    if (a[x.x] != a[y.x]) return a[x.x] < a[y.x];
    if (b[x.x] != b[y.x]) return b[x.x] < b[y.x];
    if (c[x.x] != c[y.x]) return c[x.x] < c[y.x];
    return true;
}

int main()
{
    const int inf = 100003;
    node inf_node;
    inf_node.x = inf;
    a[inf] = b[inf] = c[inf] = INT_MAX;

    int T, n;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ++ti) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) scanf("%d%d%d", &a[i], &b[i], &c[i]), p[i].x = i;
        sort(p, p+n, cmp);
        for (int i = 0; i < n; ++i) cout<<p[i].x<<endl;
        cout<<endl;
        memset(dp, 0, sizeof(dp));
        fill(g, g+n, inf_node);
        cout << b[p[3].x] << " /// " << b[p[2].x] << endl;
        if (p[1] < p[3]) cout<<"kkk"<<endl;
        for (int i = 0; i < n; ++i) {
            int j = lower_bound(g, g+n, p[i]) - g;
            cout << i << " ** " << j << endl;
            dp[i] = j + 1;
            g[j] = p[i];
            cout << b[g[0].x] << " &&& " << c[g[0].x] << endl;
            for (int k = 0; k < n; ++k) cout << g[k].x << endl;
        }
        cout << *max_element(dp, dp + n) << endl;
    }
}
