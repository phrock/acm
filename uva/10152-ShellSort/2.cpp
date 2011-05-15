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


int main()
{
    int k;
    string s;
    getline(cin, s);
    k = CAST(s, int);
    R(i, k) {
	getline(cin, s);
	int n = CAST(s, int);
	list<string> l1;
	R(j, n) { getline(cin, s); l1.pf(s); }
	list<string> l2;
	R(j, n) { getline(cin, s); l2.pf(s); }

	VS ret;
	list<string>::iterator p1 = l1.begin();
	list<string>::const_iterator p2 = l2.begin();
	while (p2 != l2.end()) {
	    if (*p1 != *p2) {
		list<string>::iterator x = find(A(l1), *p2);
		vector< pair<int, string> > v;
		for (list<string>::const_iterator j=p1; j!=x; j++) {
		    list<string>::const_iterator x = l2.begin();
		    int t = 0;
		    while (*x != *j) { t++; x++; }
		    v.pb(MP(t, *j));
		}
		sort(A(v));
		// RSZ(j, v) cout << v[j].Y << endl;
		RSZ(j, v) ret.pb(v[j].Y);
		l1.erase(p1, x);
		RSZ(j, v) l1.pb(v[j].Y);
		p1 = x;
	    }
	    p1++;
	    p2++;
	}
	VS ret2;
	set<string> st;
	RDSZ(j, ret) if (!P(st, ret[j])) { st.insert(ret[j]); ret2.pb(ret[j]); }
	RDSZ(j, ret2) cout << ret2[j] << endl;
	cout << endl;
    }
}
