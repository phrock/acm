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

    mpz_class p1 = 11;
    mpz_class q1 = 5;

    mpz_class p2 = 76;
    mpz_class q2 = 34;

    mpz_class p3 = 521;
    mpz_class q3 = 233;

    R(i, 9) {
	cout<<"/////////////////"<<endl;
	// cout << x<<" "<<y<<endl;
	// cout << p<<" "<<q<<endl;
	// cout << "******** "<<(p-1)/5<<" "<<q<<endl;

	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
	cout <<p1*x+d*q1*y<< " "<<p1*y+q1*x<<" : "<<endl;
	if ((p1*x+d*q1*y-1)%5 == 0)
	    cout<<">>>>>>>>>>>>>>>>> "<<(p1*x+d*q1*y-1)/5<<" "<<p1*y+q1*x<<endl;

	if (p1*x-d*q1*y>0) {
	    cout <<p1*x-d*q1*y<< " "<<p1*y+q1*x<<endl;
	    if ((p1*x-d*q1*y-1)%5 == 0)
		cout<<">>>>>>>>>>>>>>>>> "<<(p1*x-d*q1*y-1)/5<<" "<<p1*y+q1*x<<endl;
	}

	if (p1*y-q1*x > 0) {
	    cout <<p1*x+d*q1*y<< " "<<p1*y-q1*x<<endl;
	    if ((p1*x+d*q1*y-1)%5 == 0)
		cout<<">>>>>>>>>>>>>>>>> "<<(p1*x+d*q1*y-1)/5<<" "<<p1*y-q1*x<<endl;
	}

	if (p1*x-d*q1*y>0 && p1*y-q1*x > 0) {
	    cout <<p1*x-d*q1*y<< " "<<p1*y-q1*x<<endl;
	    if ((p1*x-d*q1*y-1)%5 == 0)
		cout<<">>>>>>>>>>>>>>>>> "<<(p1*x-d*q1*y-1)/5<<" "<<p1*y-q1*x<<endl;
	}
	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;


	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
	cout <<p2*x+d*q2*y<< " "<<p2*y+q2*x<<" : "<<endl;
	if ((p2*x+d*q2*y-1)%5 == 0)
	    cout<<">>>>>>>>>>>>>>>>> "<<(p2*x+d*q2*y-1)/5<<" "<<p2*y+q2*x<<endl;

	if (p2*x-d*q2*y>0) {
	    cout <<p2*x-d*q2*y<< " "<<p2*y+q2*x<<endl;
	    if ((p2*x-d*q2*y-1)%5 == 0)
		cout<<">>>>>>>>>>>>>>>>> "<<(p2*x-d*q2*y-1)/5<<" "<<p2*y+q2*x<<endl;
	}

	if (p2*y-q2*x > 0) {
	    cout <<p2*x+d*q2*y<< " "<<p2*y-q2*x<<endl;
	    if ((p2*x+d*q2*y-1)%5 == 0)
		cout<<">>>>>>>>>>>>>>>>> "<<(p2*x+d*q2*y-1)/5<<" "<<p2*y-q2*x<<endl;
	}

	if (p2*x-d*q2*y>0 && p2*y-q2*x > 0) {
	    cout <<p2*x-d*q2*y<< " "<<p2*y-q2*x<<endl;
	    if ((p2*x-d*q2*y-1)%5 == 0)
		cout<<">>>>>>>>>>>>>>>>> "<<(p2*x-d*q2*y-1)/5<<" "<<p2*y-q2*x<<endl;
	}
	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;


	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
	cout <<p3*x+d*q3*y<< " "<<p3*y+q3*x<<" : "<<endl;
	if ((p3*x+d*q3*y-1)%5 == 0)
	    cout<<">>>>>>>>>>>>>>>>> "<<(p3*x+d*q3*y-1)/5<<" "<<p3*y+q3*x<<endl;

	if (p3*x-d*q3*y>0) {
	    cout <<p3*x-d*q3*y<< " "<<p3*y+q3*x<<endl;
	    if ((p3*x-d*q3*y-1)%5 == 0)
		cout<<">>>>>>>>>>>>>>>>> "<<(p3*x-d*q3*y-1)/5<<" "<<p3*y+q3*x<<endl;
	}

	if (p3*y-q3*x > 0) {
	    cout <<p3*x+d*q3*y<< " "<<p3*y-q3*x<<endl;
	    if ((p3*x+d*q3*y-1)%5 == 0)
		cout<<">>>>>>>>>>>>>>>>> "<<(p3*x+d*q3*y-1)/5<<" "<<p3*y-q3*x<<endl;
	}

	if (p3*x-d*q3*y>0 && p3*y-q3*x > 0) {
	    cout <<p3*x-d*q3*y<< " "<<p3*y-q3*x<<endl;
	    if ((p3*x-d*q3*y-1)%5 == 0)
		cout<<">>>>>>>>>>>>>>>>> "<<(p3*x-d*q3*y-1)/5<<" "<<p3*y-q3*x<<endl;
	}
	cout<<"!!!!!!!!!!!!!!!!!!!!!!!!"<<endl;
	
	nextSolution(d, x0, y0, x, y);

    }
}
