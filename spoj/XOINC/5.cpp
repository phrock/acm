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

const int MAX = 2005;
long long a[MAX], mem[MAX][MAX];
int n;

long long dfs(int cur, int k)
{
    if (!cur) return 0;
    if (mem[cur][k] != -1)
        return mem[cur][k];
    if (k >= n - cur + 1)
        return a[cur];
    // if (k * 2 >= n - cur + 1) {
    //     mem[cur][k] = a[cur] - a[cur + k];
    //     return mem[cur][k];
    // }

    // int k2 = k * 2;
    // k2 = min(k2, b[cur + k]);
    // k2 = min(k2, (n - (cur + k) + 1) / 2 + 1);
    // long long aux = a[cur + k];
    long long aux = -1;
    for (int i = 1; i <= (k << 1); ++i) {
        long long tmp = dfs(cur + i, 2 * i);
        aux = max(aux, tmp);
        if (2 * i >= n - (cur + i) + 1) break;
    }

    mem[cur][k] = aux;
    return mem[cur][k];
}

int main()
{
    memset(mem, -1, sizeof(mem));
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i + 1];
    for (int i = n; i >= 1; --i)
        a[i] += a[i + 1];
    cout << dfs(1, 2) << endl;
}
