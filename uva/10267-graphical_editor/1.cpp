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
template<class T> void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> void print(T A) { cout<<"{"; RA(i, A) { cout<<*i<<", "; } cout<<"}"<<endl; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


void fill_region(vector< vector<char> >& vv, int x, int y, char color)
{
    int m = SZ(vv);
    int n = SZ(vv[0]);
    II p = MP(x, y);
    set<II> s;
    VII v;
    s.insert(p);
    char c = vv[x][y];
    bool flag = true;
    while (flag) {
	flag = false;
	v.clear();
	RA(i, s) {
	    int a, b;
	    a = i->X-1; b = i->Y;
	    if (a > 0 && vv[a][b]==c && !P(s, MP(a,b))) v.pb(MP(a, b));
	    a = i->X+1; b = i->Y;
	    if (a < m && vv[a][b]==c && !P(s, MP(a,b))) v.pb(MP(a, b));
	    a = i->X; b = i->Y-1;
	    if (b > 0 && vv[a][b]==c && !P(s, MP(a,b))) v.pb(MP(a, b));
	    a = i->X; b = i->Y+1;
	    if (b < n && vv[a][b]==c && !P(s, MP(a,b))) v.pb(MP(a, b));
	}
	if (SZ(v)) flag = true;
	RSZ(i, v) s.insert(v[i]);
    }
    RA(i, s) vv[i->X][i->Y] = color;
}

int main()
{
    vector< vector<char> > vv;

    string s;
    while (getline(cin, s)) {
	ISS iss(s);
	char c;
	iss >> c;
	if (c == 'X') break;

	switch (c) {
	case 'I':
	    int m, n;
	    iss >> m >> n;
	    vv = vector< vector<char> >(m+1, vector<char>(n+1, 'O'));
	    break;
	case 'C':
	    RSZ(i, vv) RSZ(j, vv[i]) vv[i][j] = 'O';
	    break;
	case 'L':
	    int xc, yc;
	    char color;
	    iss >> xc >> yc >> color;
	    vv[xc][yc] = color;
	    break;
	case 'V':
	    int x, y1, y2;
	    char colorv;
	    iss >> x >> y1 >> y2 >> colorv;
	    FE(i, y1, y2) vv[i][x] = colorv;
	    break;
	case 'H':
	    int x1, x2, y;
	    char colorh;
	    iss >> x1 >> x2 >> y >> colorh;
	    FE(i, x1, x2) vv[y][i] = colorh;
	    break;
	case 'F':
	    int xf, yf;
	    char colorf;
	    iss >> xf >> yf >> colorf;
	    fill_region(vv, xf, yf, colorf);
	    break;
	case 'S':
	    string name;
	    iss >> name;
	    cout << name << endl;
	    FSZ(i, 1, vv) {
		FSZ(j, 1, vv[i]) cout << vv[i][j];
		cout << endl;
	    }
	}
    }
}
