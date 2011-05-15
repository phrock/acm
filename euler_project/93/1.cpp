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


void calculate(const VD& v, set<double>& s)
{
    if (v.size() == 1) s.insert(v[0]);
    else {
	FSZ(i, 1, v) R(j, 4) {
	    VD t;
	    F(k, 0, i-1) t.pb(v[k]);

	    switch(j) {
	    case 0: t.pb(v[i-1]+v[i]); break;
	    case 1: t.pb(v[i-1]-v[i]); break;
	    case 2: t.pb(v[i-1]*v[i]); break;
	    case 3: if (v[i] == 0) continue; else t.pb(v[i-1]/v[i]); break;
	    }

	    FSZ(k, i+1, v) t.pb(v[k]);

	    calculate(t, s);
	}
    }
}

int consecutiveIntegers(set<double>& s)
{
    double result = 1;
    while(s.count(result) > 0) result++;

    return --result;
}

int main()
{
 // VD v;
 // v.pb(1); v.pb(2); v.pb(3); v.pb(4);

 // set<double> s;

 // vector< VD > vv;
 // vv.pb(v);
 // while (next_permutation(ALL(v))) vv.pb(v);

 // RSZ(i, vv) calculate(vv[i], s);

 // print(s);
 // cout << consecutiveIntegers(s)<<endl;

    int result = 0;
    VD rv;
    FE(i, 0, 6) FE(j, i+1, 7) FE(k, j+1, 8) FE(l, k+1, 9) {
 	VD v;
 	v.pb(i); v.pb(j); v.pb(k); v.pb(l);
 	VD v2 = v;

 	set<double> s;

 	vector< VD > vv;
 	vv.pb(v);
 	while (next_permutation(ALL(v))) vv.pb(v);

 	RSZ(i, vv) calculate(vv[i], s);

 	int r = consecutiveIntegers(s);
 	// cout <<"*****"<<endl;
 	// print(v2);
 	// cout<<r<<endl;
 	if (r > result) { result = r; rv = v2; }
    }

    print(rv);
    cout << result<<endl;
}
