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


const int MAX = 5000;

bool check(const bitset<MAX>& x, const bitset<MAX>& y, int n)
{
    int i = 0;
    int j = 0;
    int a = 0;
    int b = 0;
    while (n > 0) {
	while (x[i] == 0) i++;
	while (y[j] == 0) j++;
	n--;
	if (i < j) a++;
	else b++;
	i++;
	j++;
	// cout <<"****** "<<i<<" "<<j<<endl;
    }
    // cout << a<<" "<<b<<endl;
    if (a*b == 0) return false;
    else return true;
}

int compare(int n)
{
    int m = pow(2, n);
    int result = 0;
    F(i, 1, m/2) {
	bitset<MAX> x(i);
	int a = x.count();
	if (a<2 || a>n/2) continue;
	F(j, i+1, m) {
	    if ((i&j) != 0) continue;
	    bitset<MAX> y(j);
	    int b = y.count();
	    if (b<2 || b>n/2) continue;
	    if (a != b) continue;
	    // cout << "i: "<<i<<" j: "<<j<<endl;
	    // cout << "I: ";
	    // R(p, n) cout<<x[p]<<" ";
	    // cout << endl;
	    // cout << "J: ";
	    // R(p, n) cout<<y[p]<<" ";
	    // cout << endl;
	    if (check(x, y, a)) result++;
	}
    }

    return result;
}

int main()
{
    int n = 12;
    cout <<compare(n)<<endl;


}
