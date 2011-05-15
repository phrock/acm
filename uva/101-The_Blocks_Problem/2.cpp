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


bool check(int a, int b, const vector< list<int> >& v)
{
    if (a<0 || b<0 || a >= SZ(v) || b >= SZ(v) || a == b) return false;
    int x, y;
    RSZ(i, v) {
	if (PO(v[i], a)) x = i;
	if (PO(v[i], b)) y = i;
    }
    if (x == y) return false;
    return true;
}

void move_onto(int a, int b, vector< list<int> >& v)
{
    list<int>::iterator ci;
    int x;
    RSZ(i, v) { ci = find(A(v[i]), a); if (ci != v[i].end()) { x = *ci; v[i].erase(ci); break; } }
    RSZ(i, v) { ci = find(A(v[i]), b); if (ci != v[i].end()) { ci++; v[i].insert(ci, x); break; } }
}

void move_over(int a, int b, vector< list<int> >& v)
{
    list<int>::iterator ci;
    int x;
    RSZ(i, v) { ci = find(A(v[i]), a); if (ci != v[i].end()) { x = *ci; v[i].erase(ci); break; } }
    RSZ(i, v) { ci = find(A(v[i]), b); if (ci != v[i].end()) { v[i].pb(x); break; } }
}

void pile_onto(int a, int b, vector< list<int> >& v)
{
    list<int>::iterator ci, di;
    list<int> lst;
    RSZ(i, v) { ci = find(A(v[i]), a); if (ci != v[i].end()) { lst.insert(lst.begin(), ci, v[i].end()); v[i].erase(ci, v[i].end()); break; } }
    RSZ(i, v) { di = find(A(v[i]), b); if (di != v[i].end()) { di++; v[i].insert(di, A(lst)); break; } }
}

void pile_over(int a, int b, vector< list<int> >& v)
{
    list<int>::iterator ci, di;
    list<int> lst;
    RSZ(i, v) { ci = find(A(v[i]), a); if (ci != v[i].end()) { lst.insert(lst.begin(), ci, v[i].end()); v[i].erase(ci, v[i].end());break; } }
    RSZ(i, v) if (PO(v[i], b)) v[i].insert(v[i].end(), A(lst));
}

int main()
{
    string s;
    getline(cin, s);
    ISS iss(s);
    int n;
    iss >> n;
    vector< list<int> > v(n);
    RSZ(i, v) { list<int> l; l.pb(i); v[i] = l; }

    while (getline(cin, s)) {
	if (s == "quit") break;
	string s1, s2;
	int a, b;
	ISS iss(s);
	iss >> s1 >> a >> s2 >> b;
	if (!check(a, b, v)) continue;
	if (s1 == "move" && s2 == "onto") move_onto(a, b, v);
	if (s1 == "move" && s2 == "over") move_over(a, b, v);
	if (s1 == "pile" && s2 == "onto") pile_onto(a, b, v);
	if (s1 == "pile" && s2 == "over") pile_over(a, b, v);
    }

    RSZ(i, v) {
	cout << i << ":";
	RA(j, v[i]) cout << " " << *j;
	cout << endl;
    }
}
