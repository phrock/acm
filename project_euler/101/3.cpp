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


LL gen(LL n)
{
    LL result = 0;
    RE(i, 10) { if (i%2 == 0) result += pow(n, i); else result -= pow(n, i); }
    return result;
}

VVLL f(LL n)
{
    VVLL vv;
    FE(i, 1, n) {
	VLL v(n+1);
	v[0] = gen(i);
	R(j, n) v[j+1] = pow(i, j);
	vv.pb(v);
    }
    return vv;
}

VLL solution(const VVLL& vv)
{
    int n = vv.size();
    int m = vv[0].size();
    if (n == 1) { VLL v; v.pb(vv[0][0]/vv[0][1]); return v; }
    VVLL next;
    FSZ(i, 1, vv) {
	VLL a = vv[i-1];
	VLL b = vv[i];
	LL g = gcd(a[1], b[1]);
	LL x = b[1]/g;
	LL y = a[1]/g;
	RSZ(j, a) a[j] *= x;
	RSZ(j, b) b[j] *= y;
	VLL t(m-1);
	t[0] = a[0]-b[0];
	FSZ(j, 1, t) t[j] = a[j+1]-b[j+1];
	next.pb(t);
    }
    VLL r = solution(next);
    LL x = vv[0][0];
    RSZ(i, r) x -= r[i]*vv[0][2+i];
    x /= vv[0][1];
    VLL result;
    result.pb(x);
    RSZ(i, r) result.pb(r[i]);

    return result;
}

int main()
{
    // FE(i, 1, 10) cout << gen(i) << endl;

    // VVLL vv = f(10);
    // RSZ(i, vv) {
    // 	cout <<"/////////"<<endl;
    // 	print(vv[i]);
    // 	cout <<"/////////"<<endl;
    // }

    // VLL r = solution(vv);
    // print(r);

    LL result = 0LL;
    FE(i, 1, 10) {
	VVLL vv = f(i);
	VLL r = solution(vv);
	LL x = 0LL;
	RSZ(j, r) x += r[j]*pow(i+1, j);
	cout << x << endl;
	result += x;
    }
    cout <<"*********"<<endl;
    cout << result<<endl;
}
