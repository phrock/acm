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

#include <gmpxx.h>

void nextSolution(mpz_class d, mpz_class x0, mpz_class y0,
		  mpz_class& x, mpz_class& y)
{
    mpz_class tx = x;
    mpz_class ty = y;
    x = tx*x0 + ty*y0*d;
    y = tx*y0 + ty*x0;
}

int main()
{
    mpz_class x0 = 9;
    mpz_class y0 = 4;
    mpz_class d = 5;

    mpz_class x = x0;
    mpz_class y = y0;

    mpz_class p1 = 7;
    mpz_class q1 = 1;

    mpz_class p2 = 17;
    mpz_class q2 = 7;

    mpz_class p3 = 32;
    mpz_class q3 = 14;

    mpz_class p4 = 112;
    mpz_class q4 = 50;

    mpz_class p5 = 217;
    mpz_class q5 = 97;

    mpz_class p6 = 767;
    mpz_class q6 = 343;


    vector< vector<mpz_class> > vv;
    vector<mpz_class> v(2);

    v[0] = p1;
    v[1] = q1;
    vv.pb(v);

    v[0] = p2;
    v[1] = q2;
    vv.pb(v);

    v[0] = p3;
    v[1] = q3;
    vv.pb(v);

    v[0] = p4;
    v[1] = q4;
    vv.pb(v);

    v[0] = p5;
    v[1] = q5;
    vv.pb(v);

    v[0] = p6;
    v[1] = q6;
    vv.pb(v);


    mpz_class result = 0;
    
    RSZ(i, vv) result += (vv[i][0]-7)/5;

    int count = 5;
    int M = 30;
    while (count < M) {
	cout<<"/////////////////"<<endl;

	RSZ(i, vv) {
	    mpz_class p = vv[i][0];
	    mpz_class q = vv[i][1];
	    cout <<p*x+d*q*y<< " "<<p*y+q*x<<" : "<<endl;
	    if ((p*x+d*q*y-7)%5 == 0) {
		cout<<">>>>>>>>>>>>>>>>> "<<(p*x+d*q*y-7)/5<<" "<<p*y+q*x<<endl;
		result += (p*x+d*q*y-7)/5;
		count++;
	    }
	    if (count == M) break; 
	}

	nextSolution(d, x0, y0, x, y);
    }
    cout << result << endl;
}
