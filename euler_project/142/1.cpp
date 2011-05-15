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

bool isSquareNumber(LL x)
{
    if (x < 1) return false;
    LL sq = sqrt(x);
    if (sq*sq == x) return true;
    else return false;
}

bool check(LL a, LL b, LL c, LL d, LL e, LL f, LL& x, LL&y, LL& z)
{
    if ((a*a+b*b)%2 == 0) { x = (a*a+b*b)/2; y = (a*a-b*b)/2; }
    else return false;

    if ((c*c-d*d)%2 == 0) { z = (c*c-d*d)/2; }
    else return false;

    return true;
}

int main()
{
    int n = 10000;
    VLL v(n);
    for (LL i=1; i<n; i++) v[i] = i*i;
    // print(v);

    LL x;
    LL y;
    LL z;
    LL result = 99999999LL;

    FSZ(i, 1, v) {
	LL a = i;
	F(j, 1, i) {
	    LL c = j;
	    LL x = v[a]-v[c];
	    if (isSquareNumber(x)) {
		LL f = sqrt(x);
		F(k, f, c) {
		    LL e = k;
		    LL y = v[a]-v[e];
		    if (isSquareNumber(y)) {
			LL d = sqrt(y);
			LL z = v[d]-v[f];
			if (isSquareNumber(z)) {
			    LL b = sqrt(z);
			    if (check(a, b, c, d, e, f, x, y, z)) {
				cout << x<<" "<<y<<" "<<z<<" "<<x+y+z<<endl;
				checkmin(result, x+y+z);
			    }
			}
		    }
		}
	    }
	}
    }
    cout <<"////////// "<<result<<endl;
}
