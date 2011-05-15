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


void find_path(const VS& s1, const VS& s2, const VVI& p, int n, int m, VS& path)
{
    if (!n || !m) return;
    if (!p[n][m]) { find_path(s1, s2, p, n-1, m-1, path); path.pb(s1[n]); }
    else if (p[n][m] == 1) find_path(s1, s2, p, n, m-1, path);
    else find_path(s1, s2, p, n-1, m, path);
}

void lcs(const VS& s1, const VS& s2)
{
    VVI d(SZ(s1), VI(SZ(s2)));
    VVI p(SZ(s1), VI(SZ(s2)));
    FSZ(i, 1, s1) FSZ(j, 1, s2) {
	if (s1[i] == s2[j]) { d[i][j] = d[i-1][j-1]+1; p[i][j] = 0; }
	else if (d[i][j-1] >= d[i-1][j]) { d[i][j] = d[i][j-1]; p[i][j] = 1; }
	else { d[i][j] = d[i-1][j]; p[i][j] = 2; }
    }
    VS path;
    find_path(s1, s2, p, SZ(s1)-1, SZ(s2)-1, path);
     // print(path);
    RSZ(i, path) {
	if (i) cout << " ";
	cout << path[i];
    }
    cout << endl;
}

int main()
{
    string s1;
    while (getline(cin, s1, '#')) {
	string s2;
	getline(cin, s2, '#');
	if (s2.empty()) break;
	VS v1, v2;
	v1.pb(""); v2.pb("");
	ISS iss(s1);
	string t;
	while (iss >> t) v1.pb(t);
	iss.clear();
	iss.str(s2);
	while (iss >> t) v2.pb(t);
	lcs(v1, v2);
    }
}
