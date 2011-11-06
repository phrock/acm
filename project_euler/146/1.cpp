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

int main()
{
    mpz_class n = 150000000;
    // mpz_class n = 1000000;

    mpz_class result = 0;

    mpz_class x = 0;
    mpz_class x1 = 0;
    mpz_class x2 = 0;
    mpz_class x3 = 0;
    mpz_class x4 = 0;
    mpz_class x5 = 0;
    mpz_class x6 = 0;
    for (mpz_class i=10; i<n; i+=10) {
	x = i*i;
	x1 = x+1;
	x2 = x+3;
	x3 = x+7;
	x4 = x+9;
	x5 = x+13;
	x6 = x+27;
	if (mpz_probab_prime_p(x1.get_mpz_t(), 1)) {
	    mpz_nextprime(x.get_mpz_t(), x1.get_mpz_t());
	    if (x == x2) {
		mpz_nextprime(x.get_mpz_t(), x2.get_mpz_t());
		    if (x == x3) {
			mpz_nextprime(x.get_mpz_t(), x3.get_mpz_t());
			if (x == x4) {
			    mpz_nextprime(x.get_mpz_t(), x4.get_mpz_t());
			    if (x == x5) {
				mpz_nextprime(x.get_mpz_t(), x5.get_mpz_t());
				if (x == x6) {
				    cout << i << endl;
				    result += i;
				}}}}
	    }
	}
    }

    cout << "*** "<<result << endl;
}
