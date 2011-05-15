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


void output(int i, int j, VVI& path)
{
    if (i == j) cout << "A"<<i;
    else {
	cout << "(";
	output(i, path[i][j], path);
	cout << " x ";
	output(path[i][j]+1, j, path);
	cout << ")";
    }
}

void dp(const VLL& v)
{
    int n = SZ(v)-1;
    VVI path(n+1, VI(n+1));
    VVLL d(n+1, VLL(n+1, INT_MAX));
    FE(i, 1, n) d[i][i] = 0;
    FE(l, 2, n) {
	FE(i, 1, n-l+1) {
	    int j = i+l-1;
	    F(k, i, j) {
		int u = v[i-1]*v[k]*v[j]+d[i][k]+d[k+1][j];
		if (u < d[i][j]) {
		    d[i][j] = u;
		    path[i][j] = k;
		}
	    }
	}
    }
    // RSZ(i, d) print(d[i]);
    // cout <<"????????? "<< d[1][n]<<endl;
    output(1, n, path);
    cout << endl;
}

int main()
{
    int n;
    int k = 0;
    while (cin >> n) {
	if (!n) break;
	VLL v;
	int a, b;
	cin >> a >> b;
	v.pb(a);
	v.pb(b);
	F(i, 1, n) { cin >> a >> b; v.pb(b); }
	cout << "Case " << ++k << ": ";
	dp(v);
    }
}
