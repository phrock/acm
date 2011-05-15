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
int main()
{
    int n;
    int k = 0;
    vector< vector<int> > v;
    for (int i = 1; i <= 1000; ++i) {
	for (int j = i+1; j <= 1000; ++j) {
	    if (i*i+j*j > 2000000) break;
	    if ((i*i+j*j)%2) continue;
	    int c = (i*i+j*j)/2;
	    int a = (j*j-i*i)/2;
	    int b = i*j;
	    // cout << c << " " << a << " " << b << endl;
	    if (gcd(gcd(a, b), c) == 1) {
		vector<int> x(3);
		x[0] = c; x[1] = a; x[2] = b;
		v.push_back(x);
	    }
	}
    }
    sort((v).begin(), (v).end());
    vector<int> m(10000001);
    while (cin >> n) {
	vector<int> x(3);
	x[0] = n+1;
	x[1] = x[2] = 0;
	int p = lower_bound((v).begin(), (v).end(), x)-v.begin();
	memset(&m[0], 0, SZ(m)*sizeof(m[0]));
	for (int i = 0; i < p; ++i) {
	    int k = 1;
	    while (v[i][0]*k <= n) {
		// cout << v[i][0]*k << " " << v[i][1]*k<<" "<<v[i][2]*k<<endl;
		m[v[i][0]*k] = m[v[i][1]*k] = m[v[i][2]*k] = 1; k++;
	    }
	    
	}
	int res = 0;
	for (int i = 1; i <= n; ++i) {
	    if (!m[i]) res++;
	}
	cout << p << " " << res << endl;
    }
}
