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

#define eps 1e-11
#define sz(x) (int)(x).size()
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second
#define pb push_back
////////////////////////////////////////////////////////////////////////////////


int main()
{
    int n;
    while (cin >> n) {
	if (!n) break;
	vector< pair<double, double> > a;
	for (int i = 0; i < n; ++i) {
	    double x, y;
	    cin >> x >> y;
	    a.pb(mp(x, y));
	}
	int p;
	double x = 0, y = INT_MAX;
	for (int i = 0; i < a.size(); ++i) {
	    if (a[i].Y >= 0 && a[i].Y <= y) { p = i; y = a[i].Y; }
	}
	double dis = 4.5;
	double t = 3600;
	bool flag = true;
	while (flag) {
	    flag = false;
	    for (int i = 0; i < a.size(); ++i) {
		if (a[i].X > a[p].X && a[i].Y > a[p].Y && dis/a[i].X*t+a[i].Y < dis/a[p].X*t+a[p].Y) { p = i; flag = true; }
	    }
	}
	// cout << p<<endl;
	cout << ceil(dis/a[p].X*t+a[p].Y) << endl;
    }
}
