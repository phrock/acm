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

    vector<int> m(1000001);
    while (cin >> n) {
	int sq = sqrt(n);
	int k = 0;
	memset(&m[0], 0, SZ(m)*sizeof(m[0]));
	for (int i = 1; i <= sq; ++i) {
	    int sq2 = sqrt(2*n-i*i);
	    for (int j = i+1; j <= sq2; ++j) {
		// cout << i << "**"<<j<<endl;
		if (i*i+j*j > n*2) break;
		if ((i*i+j*j)%2) continue;
		int c = (i*i+j*j)/2;
		int a = (j*j-i*i)/2;
		int b = i*j;
		m[a] = m[b] = m[c] = 1;
		if (gcd(gcd(a, b), c) == 1) {
		    int t = 1;
		    while (t*c <= n) { m[a*t] = m[b*t] = m[c*t] = 1; t++; }
		    k++;
		}
	    }
	}
	int r = 0;
	for (int i = 1; i <= n; ++i) {
	    if (!m[i]) r++;
	}
	cout << k << " " << r << endl;

    }
}
