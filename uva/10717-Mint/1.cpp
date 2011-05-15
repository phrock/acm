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

template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }
int lcm(int a, int b)
{
    int g = gcd(a, b);
    return (a/g) * b;
}

int main()
{
    int a, b;
    while (cin >> a >> b) {
	if (!a) break;
	vector<int> v(a);
	for (int i = 0; i < v.size(); ++i) {
	    cin >> v[i];
	}
	vector<int> g;
	for (int i = 0; i < v.size(); ++i) {
	    for (int j = i+1; j < v.size(); ++j) {
		int t1 = lcm(v[i], v[j]);
		for (int k = j+1; k < v.size(); ++k) {
		    int t2 = lcm(t1, v[k]);
		    for (int l = k+1; l < v.size(); ++l) {
			g.push_back(lcm(t2, v[l]));
		    }
		}
	    }
	}
	for (int i = 0; i < b; ++i) {
	    int x;
	    cin >> x;
	    int p = 0;
	    int q = INT_MAX;
	    for (int j = 0; j < g.size(); ++j) {
		int t1 = x/g[j] * g[j];
		int t2 = t1==x ? x : t1+g[j];
		if (t1 > p) p = t1;
		if (t2 < q) q = t2;
	    }
	    cout << p << " " << q << endl;
	}
    }
}
