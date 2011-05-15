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


LL increaseAmount(int digits)
{
    // if (digits == 1) return 10-start;

    // LL result = 0;
    // FE(i, start, 9) result += increaseAmount(digits-1, i);

    // return result;

    if (digits == 1) return 9;

    LL x = 10;
    LL r = 1;
    R(i, digits) r *= x;
    r = (r-r/x)/2 + r/x;
    r = r-1;

    return r;
}

LL decreaseAmountHelper(int digits)
{
    if (digits == 1) return 9;

    LL x = 10;
    LL r = 1;
    R(i, digits) r *= x;
    r = (r-r/x)/2 + r/x;
    r = r-1;

    return r;
}    

LL decreaseAmount(int dights)
{
    // if (dights == 1) return start+1;

    // LL result = 0;
    // FD(i, start, 0) result += decreaseAmount(dights-1, i);

    // return result ;

    LL r = 0;
    FE(i, 1, dights) r += decreaseAmountHelper(i);
    return r;
}

LL nonBouncyAmount(int digits)
{
    LL increase = increaseAmount(digits);
    LL decrease = decreaseAmount(digits);

    return increase + decrease - digits*9;
}

int main()
{
    //    cout << nonBouncyAmount(6)<<endl;
    cout << increaseAmount(3)<<endl;
    cout << decreaseAmount(3)<<endl;
    cout << nonBouncyAmount(6)<<endl;
}
