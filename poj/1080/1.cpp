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

// template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i = (A).begin(); i != (A).end(); ++i) { cout<<" { "; for (typeof((*i).begin()) j = (*i).begin(); j != (*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl; } cout<<"}"<<endl; }

int a[][5] = { { -10000, -3, -4, -2, -1 },
	       { -3, 5, -1, -2, -1 },
	       { -4, -1, 5, -3, -2 },
	       { -2, -2, -3, 5, -2 },
	       { -1, -1, -2, -2, 5 } };

int dp(const string& s1, const string& s2)
{
    int n = SZ(s1)+1;
    int m = SZ(s2)+1;
    vector<int> p(n);
    vector<int> q(m);
    for (int i = 0; i < s1.size(); ++i) {
	if (s1[i] == 'A') p[i+1] = 1;
	if (s1[i] == 'C') p[i+1] = 2;
	if (s1[i] == 'G') p[i+1] = 3;
	if (s1[i] == 'T') p[i+1] = 4;
    }
    for (int i = 0; i < s2.size(); ++i) {
	if (s2[i] == 'A') q[i+1] = 1;
	if (s2[i] == 'C') q[i+1] = 2;
	if (s2[i] == 'G') q[i+1] = 3;
	if (s2[i] == 'T') q[i+1] = 4;
    }
    vector< vector<int> > d(n, vector<int> (m));
    for (int i = 1; i < n; ++i) {
	d[i][0] = d[i-1][0]+a[p[i]][0];
    }
    for (int j = 1; j < m; ++j) {
	d[0][j] = d[0][j-1]+a[0][q[j]];
    }

    for (int i = 1; i < n; ++i) {
	for (int j = 1; j < m; ++j) {
	    int tmp = 0;
	    for (int k = 1; k <= j; ++k) {
		tmp = a[p[i]][q[k]]+d[i-1][k-1];
		// cout <<i<<" ::: "<<k<<endl;
		// cout <<tmp<<" "<<a[p[i]][q[k]]<<" "<<d[i-1][k-1]<<endl;
		for (int l = k+1; l <= j; ++l) {
		    tmp += a[0][q[l]];
		}
		d[i][j] = max(d[i][j], tmp);
	    }
	    for (int k = 1; k <= i; ++k) {
		tmp = a[p[k]][q[j]]+d[k-1][j-1];
		for (int l = k+1; l <= i; ++l) {
		    tmp += a[p[l]][0];
		}
		d[i][j] = max(d[i][j], tmp);
	    }
	    // cout <<i<<" : " <<j<<endl;
	    // print2(d);
	}
    }
    return d[n-1][m-1];
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	int x, y;
	string s1, s2;
	cin >> x;
	for (int j = 0; j < x; ++j) {
	    char c; cin >> c; s1.pb(c);
	}
	cin >> y;
	for (int j = 0; j < y; ++j) {
	    char c; cin >> c; s2.pb(c);
	}
	// cout<<s1<<endl<<s2<<endl;
	int res = dp(s1, s2);
	cout << res << endl;
    }
}
