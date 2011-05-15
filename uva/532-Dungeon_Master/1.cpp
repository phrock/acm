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


int dungeon(const vector<VS>& v)
{
    int a = SZ(v);
    int b = SZ(v[0]);
    int c = SZ(v[0][0]);
    // cout << a<<" "<< b<<" "<<c<<endl;
    vector<VVI> visited(a, VVI(b, VI(c)));
    vector<VVI> dis(a, VVI(b, VI(c)));
    queue<VI> q;
    int s1, s2, s3;
    R(i, a) R(j, b) R(k, c) if (v[i][j][k] == 'S') { s1 = i; s2 = j; s3 = k; goto out; }
 out:
    // cout <<s1<<" "<<s2<<" "<<s3 <<endl;
    VI t(3);
    t[0] = s1; t[1] = s2; t[2] = s3;
    q.push(t);
    while (!q.empty()) {
	VI x = q.front();
	int i1 = x[0];
	int i2 = x[1];
	int i3 = x[2];
	int d = dis[i1][i2][i3];
	q.pop();
	if (v[i1][i2][i3] == 'E') return d;
	if (!visited[i1][i2][i3]) {
	    // print(x);
	    visited[i1][i2][i3] = 1;
	    if (i1 > 0 && v[i1-1][i2][i3] != '#') { dis[i1-1][i2][i3] = d+1; VI t(3); t[0] = i1-1; t[1] = i2; t[2] = i3; q.push(t); }
	    if (i1 < a-1 && v[i1+1][i2][i3] != '#') { dis[i1+1][i2][i3] = d+1; VI t(3); t[0] = i1+1; t[1] = i2; t[2] = i3; q.push(t); }
	    if (i2 > 0 && v[i1][i2-1][i3] != '#') { dis[i1][i2-1][i3] = d+1; VI t(3); t[0] = i1; t[1] = i2-1; t[2] = i3; q.push(t); }
	    if (i2 < b-1 && v[i1][i2+1][i3] != '#') { dis[i1][i2+1][i3] = d+1; VI t(3); t[0] = i1; t[1] = i2+1; t[2] = i3; q.push(t); }
	    if (i3 > 0 && v[i1][i2][i3-1] != '#') { dis[i1][i2][i3-1] = d+1; VI t(3); t[0] = i1; t[1] = i2; t[2] = i3-1; q.push(t); }
	    if (i3 < c-1 && v[i1][i2][i3+1] != '#') { dis[i1][i2][i3+1] = d+1; VI t(3); t[0] = i1; t[1] = i2; t[2] = i3+1; q.push(t); }
	}
    }

    return -1;
}

int main()
{
    int a, b, c;
    while (cin >> a >> b >> c) {
	if (!a) break;
	vector<VS> v(a, VS(b));
	R(i, a) R(j, b) cin >> v[i][j];
	int ret = dungeon(v);
	if (ret != -1) cout << "Escaped in " << ret << " minute(s)." << endl;
	else cout << "Trapped!" << endl;
    }
}
