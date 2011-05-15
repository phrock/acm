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


VVLL createScores()
{
    VVLL r;
    VLL v(2);
    v[0] = 25;
    v[1] = 1;
    r.pb(v);
    v[1] = 2;
    r.pb(v);

    FE(i, 1, 20) FE(j, 1, 3) { v[0] = i; v[1] = j; r.pb(v); }

    return r;
}

set< vector<VLL> > checkResult(const VVLL& scores, const VVLL& vv, LL a, LL b)
{
    set< vector<VLL> > ss;
    if (a == 0) { vector<VLL> s; ss.insert(s); return ss; }

    FE(i, 1, b) {
	LL product = scores[i-1][0] * scores[i-1][1];
	    
	if (a >= product) {
    	    set< vector<VLL> >  x = checkResult(scores, vv, a-product, b);
	    RA(j, x) { vector<VLL> s = *j; s.pb(scores[i-1]); sort(ALL(s)); ss.insert(s); }
	}
    }
    return ss;
}

VVLL checkout(const VVLL& scores, int n)
{
    int s = scores.size();
    VVLL vv(n+1, VLL(s+1, 0));

    RSZ(i, vv[0]) vv[0][i] = 1;
    FE(i, 1, n) FE(j, 1, s) {
	LL product = scores[j-1][0] * scores[j-1][1];

	if (i < product) vv[i][j] = vv[i][j-1];
	else vv[i][j] = vv[i-product][j] + vv[i][j-1];

    }

    return vv;
}

LL findResult(int n)
{
    VVLL scores = createScores();
    VVLL vv = checkout(scores, n);
    LL result = 0;
    FSZ(i, 1, vv[n]) {
    	if (scores[i-1][1] != 2) continue;
    	LL product = scores[i-1][0] * scores[i-1][1];
    	// if (n >= product) result += vv[n-product][s];
    	if (n >= product) {
	    set< vector<VLL> > ss = checkResult(scores, vv, n-product, scores.size());
	    RA(j, ss) if ((*j).size() <=2) result++;
	}
    }
    return result;
}    

int main()
{
    // int r = 0;
    // F(i, 1, 100) {cout << i<<endl;r += findResult(i);}
    // cout<<r<<endl;

    cout << findResult(100) << endl;
}
