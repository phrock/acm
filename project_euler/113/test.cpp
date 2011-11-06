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


bool decrease(LL n)
{
    LL a = n%10;
    n /= 10;
    while (n != 0) {
	LL b = n%10;
	if (b < a) return false;
	n /= 10;
	a = b;
    }
    return true;
}

bool increase(LL n)
{
    LL a = n%10;
    n /= 10;
    while (n != 0) {
	LL b = n%10;
	if (b > a) return false;
	n /= 10;
	a = b;
    }
    return true;
}


bool bouncy(LL n)
{
    if (increase(n) || decrease(n)) return false;
    return true;
}

LL proportion(int numerator, int denominator)
{
    LL x = 1;
    LL b = 0;

    while (denominator*b < numerator*x) {
	x++;
	if (bouncy(x)) b++;
    }

    return x;
}

int main()
{
    // LL a = proportion(1, 2);
    // LL b = proportion(9, 10);
    // cout << a <<endl;
    // cout <<b<<endl;

    // LL c = proportion(99, 100);
    // cout<<c<<endl;

    int a  = 0;
    int b = 0;
    FE(i, 1, 999999) {
	if (increase(i)) { /*cout<<i<<" ***"<<endl*/;a++; }
	if (decrease(i)) b++;
    }
    cout<<"//////"<<endl;
    cout <<a<<endl;
    cout <<b<<endl;
}
