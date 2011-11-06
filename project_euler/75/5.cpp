#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <bitset>
#include <deque>
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
typedef vector< double > VD;
typedef vector< string > VS;
typedef istringstream ISS;

#define ALL(x)  (x).begin(), (x).end()
#define SIZE(x) (int)(x).size()
#define FOR(i, a, b)  for (int i=(a); i<(b); ++i)
#define REP(i, n)  FOR(i, 0, n)
#define FORE(i, a, b)  for (int i=(a); i<=(b); ++i)
#define REPE(i, n)  FORE(i, 0, n)
#define FORD(i, a, b)  for (int i=(a); i>=(b); --i)
#define FORSZ(i, a, v)  FOR(i, a, SIZE(v))
#define REPSZ(i, v)  REP(i, SIZE(v))
#define FOREACH(i, x)  for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define PB push_back
#define PF push_front
#define MP(a, b)  make_pair(a, b)

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> inline void intToString(const T& a, string& s) { stringstream ss; ss<<a; s=ss.str(); }
template<class T> inline void stringToInt(const string& s, T& a) { istringstream iss(s); iss>>a; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


bool primitiveTriangle(int a, int b, int c)
{
    int x = gcd(a, b);
    int y = gcd(b, c);
    int z = gcd(a, c);

    if (x==1 || y==1 || z==1 ||
	gcd(x, y)!=gcd(y, z) ||
	gcd(x, y)!=gcd(x, z)) {
	return true;
    }
    return false;
}

// assume a<=b<=c
bool isRightTriangle(int a, int b, int c)
{
    if (a+b<=c) return false;

    LL x = (LL)a;
    LL y = (LL)b;
    LL z = (LL)c;
    if (x*x + y*y == z*z) {
	return true;
    } else {
	return false;
    }
}

int main()
{
    int n = 5000;
    VI v(n, 0);
    FORE(i, 1, n/3) FORE(j, i, n-j) FORE(k, j, n-i-j) {
	if (i+j+k>n) break;
	if (k<i || k<j) continue;
	// cout << i<<" "<<j<<" "<<k<<endl;
	if (v[i+j+k]==0 && isRightTriangle(i, j, k) && primitiveTriangle(i, j, k)) {
	    cout << i<<" "<<j<<" "<<k<<endl;
	    int t = i+j+k;
	    while (t<=n) { v[t]++; t *= 2; }
	}
    }
}
