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

template<class T> inline void gcdxy(T a, T b, T &g, T& x, T& y) { if (!b) { g = a; x = 1; y = 0; } else { gcdxy(b, a%b, g, y, x); y -= x*(a/b); } }
int main()
{
    long long a, b, x, y, p, q;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	cin >> a >> b;
	if (a%b == 0) { cout << b << " " << 0 << endl; continue; }
	p = a/b;
	q = a/b+1;
	long long g;
	gcdxy(p, q, g, x, y);
	cout << x*a << " " << y*a << endl;
    }
}
