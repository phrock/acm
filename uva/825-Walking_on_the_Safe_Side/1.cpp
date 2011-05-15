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
#define MP(a, b)  make_pair(a, b)
#define X first
#define Y second


int main()
{
    string s;
    getline(cin, s);
    int m = *({ ostringstream oss; oss << (s); istringstream iss(oss.str()); static int _cast_ret; iss >> _cast_ret; &_cast_ret; });
    for (int i = 0; i < m; ++i) {
	if (i) cout << endl;
	getline(cin, s);
	getline(cin, s);
	int w, n;
	istringstream iss(s);
	iss >> w >> n;
	vector< vector<int> > a(w+1, vector<int>(n+1));
	vector< vector<int> > d = a;
	for (int j = 0; j < w; ++j) {
	    getline(cin, s);
	    iss.clear();
	    iss.str(s);
	    int p, q;
	    iss >> p;
	    while (iss >> q) a[p][q] = 1;
	}
	if (a[1][1]) { cout << 0 << endl; continue; }
	d[0][1] = 1;
	for (int j = 1; j <= w; ++j) {
	    for (int k = 1; k <= n; ++k) {
		if (!a[j][k]) d[j][k] = d[j-1][k] + d[j][k-1];
	    }
	}
	cout << d[w][n] << endl;
    }


}
