/*
  ID:   aphrodi1
  LANG: C++
  PROG: ditch
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
#include "/Users/Aphrodite/program/acm/lib/debug.cpp"
#endif

ifstream fin("ditch.in");
ofstream fout("ditch.out");
streambuf *cin_buf = cin.rdbuf();
streambuf *cout_buf = cout.rdbuf();

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
int maxFlow(const vector<vector<int> > &g, int source, int dest)
{
    vector<vector<int> > residual = g; // residual graph for original graph
    int res = 0, cap = 0;
    while ((cap = findAugmentingPath(residual, source, dest)) > 0)
        res += cap;
    return res;
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int n, m;
    cin >> n >> m;
    vector< vector<int> > g(m, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        int x, y, capacity;
        cin >> x >> y >> capacity;
        --x, --y;
        g[x][y] += capacity;
        // g[y][x] += capacity;
    }
    cout << maxFlow(g, 0, m - 1) << endl;
}
