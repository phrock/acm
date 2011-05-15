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


int monocycle(const VVI& g, int sx, int sy, int tx, int ty)
{
    // cout << sx<<" "<<sy<<" "<<tx<<" "<<ty<<endl;
    int n = SZ(g);
    int m = SZ(g[0]);
    VVI visited(n*m, VI(4*5));
    visited[sx*m+sy][0] = 1;
    queue<II> q;
    q.push(MP(sx*m+sy, 0));
    while (!q.empty()) {
	II a = q.front();
	q.pop();
	int x = a.X/m;
	int y = a.X%m;
	int dir = a.Y/5;
	int color = a.Y%5;
	int time = visited[a.X][a.Y]+1;
	if (x == tx && y == ty && !color) return visited[a.X][a.Y]-1;
	if (!visited[a.X][((dir+1)%4)*5+color]) { visited[a.X][((dir+1)%4)*5+color] = time; q.push(MP(a.X, ((dir+1)%4)*5+color)); }
	if (!visited[a.X][((dir+3)%4)*5+color]) { visited[a.X][((dir+3)%4)*5+color] = time; q.push(MP(a.X, ((dir+3)%4)*5+color)); }
	int next_color = (color+1)%5;
	int next = dir*5+next_color;
	if (x > 0 && dir == 0 && !visited[a.X-m][next] && !g[x-1][y]) { visited[a.X-m][next] = time; q.push(MP(a.X-m, next)); }
	if (x < n-1 && dir == 2 && !visited[a.X+m][next] && !g[x+1][y]) { visited[a.X+m][next] = time; q.push(MP(a.X+m, next)); }
	if (y > 0 && dir == 3 && !visited[a.X-1][next] && !g[x][y-1]) { visited[a.X-1][next] = time; q.push(MP(a.X-1, next)); }
	if (y < m-1 && dir == 1 && !visited[a.X+1][next] && !g[x][y+1]) { visited[a.X+1][next] = time; q.push(MP(a.X+1, next)); }
    }
    return -1;
}

int main()
{
    int a, b;
    int k = 0;
    while (cin >> a >> b) {
	if (!a) break;
	if (k) cout << endl;
	cout << "Case #" << ++k << endl;
	int sx, sy, tx, ty;
	VVI g(a, VI(b));
	R(i, a) {
	    string s;
	    cin >> s;
	    R(j, b) {
		if (s[j] == '#') g[i][j] = 1;
		if (s[j] == 'S') { sx = i; sy = j; }
		if (s[j] == 'T') { tx = i; ty = j; }
	    }
	}
	int ret = monocycle(g, sx, sy, tx, ty);
	if (ret > 0) cout << "minimum time = " << ret << " sec" << endl;
	else cout << "destination not reachable" << endl;
    }
}
