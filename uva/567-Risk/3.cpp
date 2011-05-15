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


vector< vector<int> > floyd_warshall(const vector< vector<int> > &g)
{
    int n = SZ(g);
    vector< vector<int> > dis(n, vector<int> (n));
    for (int i = 0; i < g.size(); ++i) {
	for (int j = i+1; j < g[i].size(); ++j) {
	    if (g[i][j]) dis[i][j] = dis[j][i] = g[i][j];
	    else dis[i][j] = dis[j][i] = INT_MAX;
	}
    }
    for (int k = 0; k < n; ++k) {
	for (int i = 0; i < n; ++i) {
	    for (int j = i+1; j < n; ++j) {
		if (dis[i][k] != INT_MAX && dis[j][k] != INT_MAX && dis[i][k]+dis[j][k] < dis[i][j]) {
		    dis[i][j] = dis[i][k]+dis[j][k];
		    dis[j][i] = dis[i][k]+dis[j][k];
		}
	    }
	}
    }
    return dis;
}

int main()
{
    int n;
    int k = 0;
    while (cin >> n) {
	cout << "Test Set #" << ++k << endl;
	vector< vector<int> > g(20, vector<int> (20));
	int x;
	for (int i = 0; i < n; ++i) {
	    cin >> x;
	    x--;
	    g[0][x] = 1;
	    g[x][0] = 1;
	}
	for (int i = 1; i <= 18; ++i) {
	    cin >> n;
	    for (int j = 0; j < n; ++j) {
		cin >> x;
		x--;
		g[i][x] = 1;
		g[x][i] = 1;
	    }
	}
	vector< vector<int> > dis = floyd_warshall(g);
	cin >> n;
	for (int i = 0; i < n; ++i) {
	    int x, y;
	    cin >> x >> y;
	    printf("%2d to %2d: %d\n", x, y, dis[x-1][y-1]);
	}
	cout << endl;
    }
}
