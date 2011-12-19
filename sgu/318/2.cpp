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
#include "/Users/Aphrodite/program/acm/lib/debug.cpp"
#endif

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

const int MAX = 100;
int root[MAX + 5];
int rank[MAX + 5];

void initSet()
{
    for (int i = 1; i <= MAX; ++i) {
        root[i] = i;
        rank[i] = 1;
    }
}

int findRoot(int x)
{
    if (root[x] != x)
        root[x] = findRoot(root[x]);
    return root[x];
}

void mergeDisjointSet(int a, int b)
{
    int ra = findRoot(a), rb = findRoot(b);
    if (rank[ra] > rank[rb]) {
        root[rb] = ra;
        ++rank[ra];
    } else {
        root[ra] = rb;
        ++rank[rb];
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    initSet();
    vector<bitset<MAX + 5> > bs(MAX + 5);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        int tmp;
        for (int j = 0; j < k; ++j) {
            cin >> tmp;
            bs[tmp][i] = 1;
        }
    }

    for (int i = 1; i <= n; ++i)
        for (int j = i + 1; j <= n; ++j)
            if (bs[i] == bs[j])
                mergeDisjointSet(i, j);

    int res = 0;
    for (int i = 1; i <= n; ++i)
        if (bs[i].count() && root[i] == i)
            ++res;

    cout << res << endl;
}
