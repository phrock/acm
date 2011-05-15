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
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef long long LL;
typedef vector< int > VI;
typedef vector< VI > VVI;
typedef vector< LL > VLL;
typedef vector< VLL > VVLL;
typedef vector< double > VD;
typedef vector< string > VS;
typedef pair< int, int > II;
typedef vector< II > VII;
typedef vector< VII > VVII;
typedef istringstream ISS;
typedef ostringstream OSS;

#define A(x)  (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define F(i, a, b)  for (int i=(a); i<(b); ++i)
#define R(i, n)  F(i, 0, n)
#define FE(i, a, b)  for (int i=(a); i<=(b); ++i)
#define RE(i, n)  FE(i, 0, n)
#define FD(i, a, b)  for (int i=(a); i>=(b); --i)
#define RD(i, n) FD(i, n, 0)
#define FSZ(i, a, v)  F(i, a, SZ(v))
#define RSZ(i, v)  R(i, SZ(v))
#define FDSZ(i, a, v) FD(i, SZ(v)-1, a)
#define RDSZ(i, v) RD(i, SZ(v)-1)
#define FA(i, a, x)  for (__typeof((x).begin()) i=(a); i!=(x).end(); ++i)
#define RA(i, x)  FA(i, (x).begin(), x)
#define FDA(i, a, x)  for (__typeof((x).rbegin()) i=(x).rbegin(); i!=(a); ++i)
#define RDA(i, x)  FDA(i, (x).rend(), x)
#define P(v, x) ((v).find(x) != (v).end())
#define PO(v, x) (find(A(v), x) != (v).end())
#define UN(a) sort(A(a)), (a).erase(unique(A(a)), (a).end())
#define CL(a, b) memset(a, b, sizeof(a))
#define MP(a, b)  make_pair(a, b)
#define CAST(x, type) *({ OSS oss; oss << (x); ISS iss(oss.str()); static type _cast_ret; iss >> _cast_ret; &_cast_ret; })
#define pb push_back
#define pf push_front
#define X first
#define Y second

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> inline void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> inline void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> inline void print(T A) { cout<<"{"; RA(i, A) { cout<<*i<<", "; } cout<<"}"<<endl; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


VVLL tsp(const VVLL& a)
{
    int m = SZ(a);
    int n = SZ(a[0]);
    VVLL d(m, VLL(n, LLONG_MAX));
    R(i, m) d[i][0] = a[i][0];
    F(j, 1, n) R(i, m) {
	FE(k, -1, 1) checkmin(d[i][j], d[(i+k+m)%m][j-1]);
	d[i][j] += a[i][j];
	// cout << i<<" : "<<j<<endl;
	// RSZ(i, d) print(d[i]);
    }
    return d;
}

void dfs(const VVLL& a, const VVLL& d, int i, int k, const VI& v, VVI& ret)
{
    if (k == 0) { ret.pb(v); return; }
    int m = SZ(d);
    int n = SZ(d[0]);
    FE(j, -1, 1) if (d[(i+j+m)%m][k-1]+a[i][k] == d[i][k]) {
	VI next = v;
	next.pb((i+j+m)%m);
	dfs(a, d, (i+j+m)%m, k-1, next, ret);
    }
}
	    

VI find_path(const VVLL& a, const VVLL& d, LL x)
{
    int k = SZ(d[0])-1;
    VVI ret;
 
    RSZ(i, d) if (d[i][k] == x) {
	VI v;
	v.pb(i);
	dfs(a, d, i, k, v, ret);
    }
    RSZ(i, ret) reverse(A(ret[i]));
    sort(A(ret));
    return ret[0];
}

int main()
{
    int m, n;
    while (cin >> m >> n) {
	VVLL a(m, VLL(n));
	R(i, m) R(j, n) cin >> a[i][j];
	VVLL d = tsp(a);
	// RSZ(i, d) print(d[i]);
	LL x = LLONG_MAX;
	R(i, m) checkmin(x, d[i][n-1]);
	VI path = find_path(a, d, x);
	RSZ(i, path) {
	    if (i) cout << " ";
	    cout << path[i]+1;
	}
	cout << endl;
	cout << x << endl;
    }
}
