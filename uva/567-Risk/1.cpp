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

#define EPS 1e-11
#define SZ(x) (int)(x).size()
#define MP(a, b) make_pair(a, b)
#define X first
#define Y second
#define pb push_back
////////////////////////////////////////////////////////////////////////////////


int distance(const vector< vector<int> > &g, int x, int y)
{
    vector<int> v(SZ(g));
    queue<int> q;
    q.push(x);
    v[x] = 1;
    while (!q.empty()) {
	int x = q.front();
	q.pop();
	if (x == y) return v[x]-1;
	for (int i = 0; i < g[x].size(); ++i) {
	    if (!v[g[x][i]]) {
		q.push(g[x][i]);
		v[g[x][i]] = v[x]+1;
	    }
	}
    }
}

int main()
{
    int n;
    int k = 0;
    while (cin >> n) {
	cout << "Test Set #" << ++k << endl;
	vector< vector<int> > g(20);
	int x;
	for (int i = 0; i < n; ++i) {
	    cin >> x;
	    x--;
	    g[0].pb(x);
	    g[x].pb(0);
	}
	for (int i = 1; i <= 18; ++i) {
	    cin >> n;
	    for (int j = 0; j < n; ++j) {
		cin >> x;
		x--;
		g[i].pb(x);
		g[x].pb(i);
	    }
	}
	cin >> n;
	for (int i = 0; i < n; ++i) {
	    int x, y;
	    cin >> x >> y;
	    int res = distance(g, x-1, y-1);
	    printf("%2d to %2d: %d\n", x, y, res);
	}
	cout << endl;
    }
}
