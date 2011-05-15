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
#define P(v, x) (v.find(x) != v.end())
#define PO(v, x) (find(A(v), x) != v.end())
#define UN(a) sort(A(a)), a.erase(unique(A(a)), a.end())
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


void fifteen_puzzle(const VVI& orig, const VVI& dst)
{
    const int max_path = 45;
    pair<VVI, string> start;
    start.X = orig;
    start.Y = "";

    set<VVI> s;
    s.insert(orig);
    queue< pair<VVI, string> > q;
    q.push(start);

    while (!q.empty()) {
	pair<VVI, string> x = q.front();
	q.pop();

	if (x.X == dst) { cout << x.Y << endl; return; }

	int i = 0;
	int j = 0;
	R(k, SZ(x.X)*SZ(x.X[0])) if (x.X[k/4][k%4] == 0) { i = k/4; j = k%4; break; }

	pair<VVI, string> next;
	if (j > 0) {
	    next = x;
	    swap(next.X[i][j], next.X[i][j-1]);
	    if (!P(s, next.X)) { s.insert(next.X); if (SZ(next.Y) < max_path) { next.Y += "L"; q.push(next); } }
	}
	if (j < 3) {
	    next = x;
	    swap(next.X[i][j], next.X[i][j+1]);
	    if (!P(s, next.X)) { s.insert(next.X); if (SZ(next.Y) < max_path) { next.Y += "R"; q.push(next); } }
	}
	if (i > 0) {
	    next = x;
	    swap(next.X[i][j], next.X[i-1][j]);
	    if (!P(s, next.X)) { s.insert(next.X); if (SZ(next.Y) < max_path) { next.Y += "U"; q.push(next); } }
	}
	if (i < 3) {
	    next = x;
	    swap(next.X[i][j], next.X[i+1][j]);
	    if (!P(s, next.X)) { s.insert(next.X); if (SZ(next.Y) < max_path) { next.Y += "D"; q.push(next); } }
	}
    }

    cout << "This puzzle is not solvable." << endl;
}

int main()
{
    int n;
    cin >> n;
    VVI dst(4, VI(4));
    RSZ(i, dst) RSZ(j, dst[i]) dst[i][j] = 4*i+j+1;
    dst[3][3] = 0;
    // RSZ(i, dst) print(dst[i]);

    VVI orig(4, VI(4));
    R(k, n) {
	RSZ(i, orig) RSZ(j, orig[i]) cin >> orig[i][j];
	fifteen_puzzle(orig, dst);
    }
}
