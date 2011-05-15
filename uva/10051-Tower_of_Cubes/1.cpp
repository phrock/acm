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


int main()
{
    int n;
    int k = 0;
    while (cin >> n) {
	if (!n) break;
	if (k) cout << endl;
	cout << "Case #" << ++k << endl;
	vector< vector<int> > a(n+1, vector<int> (6));
	for (int i = 1; i <= n; ++i) {
	    for (int j = 0; j < 6; ++j) {
		cin >> a[i][j];
	    }
	}
	vector< vector<int> > d(n+1, vector<int> (6));
	vector< vector< pair<int, int> > > vp(n+1, vector< pair<int, int> > (6));
	// vector< vector< vector<int> > > vp(n+1, vector< vector<int> >(6, vector<int>(2)));
	for (int i = 1; i <= n; ++i) {
	    for (int j = 0; j < 6; ++j) {
		int m = -1;
		for (int p = 0; p < i; ++p) {
		    for (int q = 0; q < 6; ++q) {
			// cout <<i<<" "<<j<<" "<<p<<" "<<q<<endl;
			int u;
			if (q%2 == 0) u = q+1; else u = q-1;
			if ((a[p][u] == a[i][j] || !p) && d[p][q] > m) { m = d[p][q]; vp[i][j].X = p; vp[i][j].Y = q; }
			// if (d[p][q] > m) ;{ m = d[p][q]; vp[i][j][0] = p; /*vp[i][j].Y = q;*/ }
		    }
		}
		d[i][j] = m+1;
	    }
	}
	int m = 0;
	int x, y;
	for (int i = 1; i <= n; ++i) {
	    for (int j = 0; j < 6; ++j) {
		if (d[i][j] > m) { m = d[i][j]; x = i; y = j; }
	    }
	}
	cout << m << endl;
	vector< pair<int, string> > res;
	while (x != 0) {
	    string s;
	    switch (y) {
	    case 0: s = "front"; break;
	    case 1: s = "back"; break;
	    case 2: s = "left"; break;
	    case 3: s = "right"; break;
	    case 4: s = "top"; break;
	    case 5: s = "bottom"; break;
	    }
	    res.push_back(MP(x, s));
	    // cout << x << " " << s << endl;
	    int t1 = vp[x][y].X;
	    int t2 = vp[x][y].Y;
	    x = t1; y = t2;
	}
	reverse((res).begin(), (res).end());
	for (int i = 0; i < res.size(); ++i) {
	    cout << res[i].X << " " << res[i].Y << endl;
	}
    }
}
