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

VI initVector(int n)
{
    VI v(4);
    int sq = sqrt(n);

    v[0] = sq;
    v[1] = 1;
    v[2] = n;
    v[3] = sq;

    return v;
}

VI nextVector(const VI& v)
{
    VI result(4);

    int a = v[2] - v[3]*v[3];
    a /= v[1];
    int b = v[2];
    int c = v[3];

    int sq = sqrt(b);
    
    int d = 0;
    while ((d*a - c) <= sq) {
	d++;
    }
    d--;

    c = d*a - c;
    // cout <<d<<" "<< a<< " " <<b<<" "<<c<<endl;
    result[0] = d;
    result[1] = a;
    result[2] = b;
    result[3] = c;

    return result;
}

bool checkPQ(mpz_class p, mpz_class q, int D, int c)
{
    if (p*p-D*q*q == c) return true;
    else return false;
}

void getPQ(int D, int c, mpz_class& p, mpz_class& q)
{
    VI v = initVector(D);
    int a0 = v[0];

    v = nextVector(v);
    int a1 = v[0];

    mpz_class p0 = a0;
    mpz_class q0 = 1;

    if (checkPQ(p0, q0, D, c)) { p = p0; q = q0; return; }

    mpz_class p1 = a0*a1+1;
    mpz_class q1 = a1;

    if (checkPQ(p1, q1, D, c)) { p = p1; q = q1; return; }

    v = nextVector(v);
    int an = v[0];
    p = an*p1 + p0;
    q = an*q1 + q0;
    while (checkPQ(p, q, D, c) == false) {
	cout<<"*** "<<p<<" "<<q<<endl;
	p0 = p1;
	q0 = q1;
	p1 = p;
	q1 = q;
	
	v = nextVector(v);
	an = v[0];
	p = an*p1 + p0;
	q = an*q1 + q0;
    }
}

int main()
{
    mpz_class p, q;
    int D = 2;
    int c = 3;

    getPQ(D, c, p, q);
    cout << p<<" "<<q<<endl;
}
