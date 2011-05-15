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


II convert_time(string s)
{
    II ret;
    ISS iss(s);
    string aux;
    R(i, 2) {
	iss >> aux;
    	int x = 0;
	x = CAST(aux.substr(0, 2), int);
	x *= 60;
	x += CAST(aux.substr(3, 2), int);
	if (!i) ret.X = x; else ret.Y = x;
    }
    return ret;
}

void nap(const VII& v, int day)
{
    int m = -1;
    int k = 0;
    FSZ(i, 1, v) {
	int gap = v[i].X-v[i-1].Y;
	if (gap > m) { m = gap; k = i-1; }
    }
    int longest = v[k+1].X-v[k].Y;
    int hour = v[k].Y/60;
    int minute = v[k].Y%60;

    cout << "Day #" << day << ": the longest nap starts at "
	 << hour <<":";
    if (minute < 10) cout << "0";
    cout<<minute<<" and will last for ";
    if (longest >= 60)
	cout <<longest/60<<" hours and ";
    cout <<longest%60<<" minutes."<<endl;
}

int main()
{
    int day = 0;
    int n;
    string s;
    while (getline(cin, s)) {
	day++;
	n = CAST(s, int);
	// cout << n << endl;
	VII v;
	v.pb(MP(10*60, 10*60));
	R(i, n) {
	    getline(cin, s);
	    // cout << s << endl;
	    v.pb(convert_time(s));
	}
	v.pb(MP(18*60, 18*60));
	// RSZ(i, v) cout << v[i].X<<" "<<v[i].Y<<endl;
	sort(A(v));
	nap(v, day);
    }
}
