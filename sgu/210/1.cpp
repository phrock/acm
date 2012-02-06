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

int findAugmentingPath(vector<vector<int> > &g, int source, int dest)
{
    int n = (int)(g).size();
    vector<int> from(n, -1);
    queue<int> q;
    q.push(source);
    while (!q.empty()) {
	int cur = q.front();
	q.pop();
	if (cur == dest) break;
	for (int next = 0; next < n; ++next)
	    if (next != source && from[next] == -1 && g[cur][next] > 0) {
                from[next] = cur;
                q.push(next);
            }
    }
    int cur = dest;
    int res = INT_MAX;
    while (from[cur] != -1) {
        res = min(res, g[from[cur]][cur]);
        cur = from[cur];
    }
    cur = dest;
    while (from[cur] != -1) {
        g[from[cur]][cur] -= res;
        g[cur][from[cur]] += res;
        cur = from[cur];
    }
    return res == INT_MAX ? 0 : res;
}

// Ford-Fulkerson algorithm
int maxFlow(const vector<vector<int> > &g, int source, int dest, vector< vector<int> > &residual)
{
    // vector<vector<int> > residual = g; // residual graph for original graph
    int res = 0, cap = 0;
    while ((cap = findAugmentingPath(residual, source, dest)) > 0)
        res += cap;
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector< vector<int> > g(n + n + 2, vector<int>(n + n + 2));
    vector<int> preferences(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> preferences[i];
        preferences[i] *= preferences[i];
    }
    for (int i = 1; i <= n; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int tmp;
            cin >> tmp;
            tmp += n;
            g[i][tmp] = preferences[i];
        }
    }
    for (int i = 1; i <= n; ++i)
        g[0][i] = preferences[i];
    for (int i = n + 1; i <= n + n; ++i)
        g[i][n + n + 1] = 1000005;

    vector< vector<int> > residual = g;
    maxFlow(g, 0, n + n + 1, g);
    vector<int> res;
    for (int i = 1; i <= n; ++i) {
        if (g[0][i] != 0) {
            res.push_back(0);
            continue;
        }
        for (int j = n + 1; j <= n + n + 1; ++j)
            if (g[i][j] != residual[i][j]) {
                res.push_back(j - n);
                break;
            }
    }
    for (int i = 0; i < (int)(res).size(); ++i) {
        if (i)
            cout << " ";
        cout << res[i];
    }
    cout << endl;
}
