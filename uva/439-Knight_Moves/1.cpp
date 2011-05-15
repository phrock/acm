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


int knight(int x1, int y1, int x2, int y2)
{
    VVI v(8, VI(8));
    VVI visited(8, VI(8));
    int dis = 0;
    queue<II> q;
    q.push(MP(x1, y1));
    while (!q.empty()) {
	II x = q.front();
	q.pop();
	int a = x.X;
	int b = x.Y;
	if (a == x2 && b == y2) return v[a][b];
	if (!visited[a][b]) {
	    visited[a][b] = 1;
	    if (a >= 2 && b >= 1) { q.push(MP(a-2, b-1)); v[a-2][b-1] = v[a][b]+1; }
	    if (a >= 2 && b <= 6) { q.push(MP(a-2, b+1)); v[a-2][b+1] = v[a][b]+1; }
	    if (a <= 5 && b >= 1) { q.push(MP(a+2, b-1)); v[a+2][b-1] = v[a][b]+1; }
	    if (a <= 5 && b <= 6) { q.push(MP(a+2, b+1)); v[a+2][b+1] = v[a][b]+1; }
	    if (a >= 1 && b >= 2) { q.push(MP(a-1, b-2)); v[a-1][b-2] = v[a][b]+1; }
	    if (a >= 1 && b <= 5) { q.push(MP(a-1, b+2)); v[a-1][b+2] = v[a][b]+1; }
	    if (a <= 6 && b >= 2) { q.push(MP(a+1, b-2)); v[a+1][b-2] = v[a][b]+1; }
	    if (a <= 6 && b <= 5) { q.push(MP(a+1, b+2)); v[a+1][b+2] = v[a][b]+1; }
	}
    }
}

int main()
{
    string s1, s2;
    while (cin >> s1 >> s2) {
	int x1, y1, x2, y2;
	x1 = s1[0]-'a';
	y1 = s1[1]-'1';
	x2 = s2[0]-'a';
	y2 = s2[1]-'1';
	int ret = knight(x1, y1, x2, y2);
	cout << "To get from " << s1 << " to " << s2 << " takes " << ret << " knight moves." << endl;
    }
}
