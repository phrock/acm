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

pair<int, int> edge[MAX + 5];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i)
        scanf("%d%d", &edge[i].first, &edge[i].second);
    initSet();
    bool ok = true;
    for (int i = 0; i < m; ++i) {
        int a = edge[i].first, b = edge[i].second;
        if (findRoot(a) == findRoot(b)) {
            ok = false;
            break;
        }
        mergeDisjointSet(a, b);
        --n;
    }
    cout << (ok && n == 1 ? "YES" : "NO") << endl;
}
