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


bool check(const VLL& book, LL x, int k)
{
    int i = 0;
    while (k) {
	LL m = 0;
	while (i < SZ(book)) {
	    m += book[i];
	    if (m > x) break;
	    i++;
	}
	if (i == SZ(book)) return true;
	k--;
    }
    return false;
}

void copying(const VLL& book, int k)
{
    // cout <<check(book, 1700, k)<<endl;
    LL a = 0;
    LL b = 0;
    RSZ(i, book) b += book[i];
    while (a < b) {
	LL x = (a+b)/2;
	// cout <<a<<" "<<b<<" "<<x<<endl;
	if (check(book, x, k)) b = x;
	else a = x+1;
    }

    VVLL vv;
    int i = SZ(book)-1;
    while (k) {
	LL m = 0;
	VLL v;
	while (i >= k-1) {
	    m += book[i];
	    if (m > a) break;
	    v.pb(book[i]);
	    i--;
	}
	k--;
	vv.pb(v);
    }
    // RSZ(i, vv) print(vv[i]);
    RDSZ(i, vv[SZ(vv)-1]) { if (i != SZ(vv[SZ(vv)-1])-1) cout << " "; cout << vv[SZ(vv)-1][i]; }
    for (int i = SZ(vv)-2; i >= 0; i--) {
	cout << " /";
	RDSZ(j, vv[i]) cout << " " << vv[i][j];
    }
    cout << endl;
}   

int main()
{
    LL n;
    cin >> n;
    R(i, n) {
	LL m, k;
	cin >> m >> k;
	VLL book;
	R(j, m) { int x; cin >> x; book.pb(x); }
	copying(book, k);
    }
}
