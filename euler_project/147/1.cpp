#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
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
typedef istringstream ISS;

#define A(x)  (x).begin(), (x).end()
#define SIZE(x) (int)(x).size()
#define F(i, a, b)  for (int i=(a); i<(b); ++i)
#define R(i, n)  F(i, 0, n)
#define FE(i, a, b)  for (int i=(a); i<=(b); ++i)
#define RE(i, n)  FE(i, 0, n)
#define FD(i, a, b)  for (int i=(a); i>=(b); --i)
#define FSZ(i, a, v)  F(i, a, SIZE(v))
#define RSZ(i, v)  R(i, SIZE(v))
#define FA(i, a, x)  for (__typeof((x).begin()) i=(a); i!=(x).end(); ++i)
#define RA(i, x)  for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define UN(a) sort(A(a)), a.erase(unique(A(a)), a.end())
#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pf push_front
#define MP(a, b)  make_pair(a, b)

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> void print(T A) { cout<<"{"; RA(i, A) { cout<<*i<<", "; } cout<<"}"<<endl; }
template<class T> inline void intToString(const T& a, string& s) { stringstream ss; ss<<a; s=ss.str(); }
template<class T> inline void stringToInt(const string& s, T& a) { istringstream iss(s); iss>>a; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


LL nC2(LL n)
{
    if (n < 2) return 0;
    return n*(n-1)/2;
}

LL titles(LL a, LL b, const VLL& v)
{
    if (a < b) swap(a, b);
    LL result = 0;

    VLL slash;
    LL m = b*2;
    LL n = a+b-1;
    LL x = 2;
    while (x < m) { slash.pb(x); x += 2; }
    VLL tmp = slash;
    reverse(A(tmp));
    R(i, n-2*tmp.size()) slash.pb(m);
    RSZ(i, tmp) slash.pb(tmp[i]);
    
    // print(slash);

    VVLL coordinate;
    x = 0;
    R(i, b) { x--; LL y = x+slash[i]; VLL tmp(2); tmp[0]=x; tmp[1]=y; coordinate.pb(tmp); }
    F(i, b, n) { x++; LL y = x+slash[i]; VLL tmp(2); tmp[0]=x; tmp[1]=y; coordinate.pb(tmp); }

    //RSZ(i, coordinate) print(coordinate[i]);

    RSZ(i, coordinate) FSZ(j, i+1, coordinate) {
	LL p = max(coordinate[i][0], coordinate[j][0]);
	LL q = min(coordinate[i][1], coordinate[j][1]);
	if (p < q) result += v[q-p+1];
    }

    return result;
}

LL rectangles(LL a, LL b, const VLL& v)
{
    if (a < b) swap(a, b);
    
    LL x = v[a+1]*v[b+1];
    LL y = titles(a, b, v);

    return x + y;
}

LL total(LL a, LL b, const VLL& v)
{
    LL result = 0;
    FE(i, 1, a) FE(j, 1, b) result += rectangles(i, j, v);

    return result;
}

int main()
{
    int n = 100;
    VLL v(n);
    RSZ(i, v) v[i] = nC2(i);

    LL a = 47;
    LL b = 43;
    cout << total(a, b, v)<<endl;
}
    
