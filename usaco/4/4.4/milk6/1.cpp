/*
  ID:   aphrodi1
  LANG: C++
  PROG: milk6
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

ifstream fin("milk6.in");
ofstream fout("milk6.out");
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
pair<int, vector< vector<int> > > maxFlow(const vector<vector<int> > &g, int source, int dest)
{
    vector<vector<int> > residual = g; // residual graph for original graph
    int res = 0, cap = 0;
    while ((cap = findAugmentingPath(residual, source, dest)) > 0)
        res += cap;
    return make_pair(res, residual);
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    /////////////////////////////////////////////////////////////////////////

    int n, m;
    cin >> n >> m;
    vector< vector<int> > g(n, vector<int>(n));
    vector< pair<int, int> > idx(m);
    for (int i = 0; i < m; ++i) {
        int x, y, c;
        cin >> x >> y >> c;
        --x, --y;
        g[x][y] += c;
        idx[i].first = x;
        idx[i].second = y;
    }
    pair<int, vector< vector<int> > > res = maxFlow(g, 0, n - 1);
    int flow = res.first;
    vector< vector<int> > residual = res.second;
    
    vector<int> v(n);
    v[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int ft = q.front();
        q.pop();
        for (int i = 0; i < n; ++i)
            if (!v[i] && residual[ft][i]) {
                v[i] = 1;
                q.push(i);
            }
    }
    vector<int> delete_path;
    for (int i = 0; i < m; ++i)
        if (v[idx[i].first] != v[idx[i].second])
            delete_path.push_back(i + 1);
    cout << flow << " " << (int)(delete_path).size() << endl;
    for (int i = 0; i < (int)(delete_path).size(); ++i)
        cout << delete_path[i] << endl;
}
