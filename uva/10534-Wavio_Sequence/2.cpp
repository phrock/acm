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


vector<int> lis(const vector<int> &a)
{
    int n = SZ(a);
    vector<int> g(n, INT_MAX);
    vector<int> d(n);
    for (int i = 0; i < n; ++i) {
	int x = lower_bound((g).begin(), (g).end(), a[i]) - g.begin();
	d[i] = x+1;
	g[x] = a[i];
    }
    return d;
}

int main()
{
    int n;
    while (cin >> n) {
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
	    cin >> a[i];
	}
	vector<int> d1 = lis(a);
	reverse((a).begin(), (a).end());
	vector<int> d2 = lis(a);
	reverse((d2).begin(), (d2).end());

	int m = 0;
	for (int i = 0; i < n; ++i) {
	    m = max(m, min(d1[i],d2[i])*2-1);
	}
	cout << m << endl;
    }
}
