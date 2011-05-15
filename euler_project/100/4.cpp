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
typedef vector< VLL > VVLL;
typedef vector< double > VD;
typedef vector< string > VS;
typedef istringstream ISS;

#define ALL(x)  (x).begin(), (x).end()
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
#define UN(a) sort(ALL(a)), a.erase(unique(ALL(a)), a.end())
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

void f(const mpz_class& a, const mpz_class& b, const mpz_class& m)
{
    cout << "fffffff"<<endl;
    cout << a<<" "<< b<<endl;
    if (a >= b) { cout << b<<endl; return; }
    mpz_class x = (a+b)/2+1;
    cout << x<<endl;
    if (8*x*(x-1) > m) f(a, x, m);
    else f(x, b, m);
}

int main()
{
    mpz_class n("1000000000000");
    mpz_class m = (2*n-1)*(2*n-1)-1;
    mpz_class x = 15;
    while (true) {
	cout << x<< " "<<m<<endl;
	if (m%16 ==0 && 8*x*(x-1) > m) break;
	x = x*2;
    }

    mpz_class y("707106781187");

    //    f(y, x, m);
    bool v = 8*y*(y-1) > m;
    cout <<v<<endl;

    // while (true) {
    // 	mpz_class t = 8*y*(y-1)+1;
    // 	mpz_class sq = sqrt(t);
    // 	if (sq*sq == t) break;
    // 	y++;
    // }

    cout << 8*y*(y-1)+1<<endl;
    cout << m<<endl;
}
