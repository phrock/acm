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

VVI createScores()
{
    VVI r;
    VI v(2);
    v[0] = 25;
    v[1] = 1;
    r.pb(v);
    v[1] = 2;
    r.pb(v);

    FE(i, 1, 20) FE(j, 1, 3) { v[0] = i; v[1] = j; r.pb(v); }

    return r;
}

bool cmpScores(const VI& a, const VI& b)
{
    return a[0]*a[1] < b[0]*b[1];
}

int checkout(const VVI& s, int n)
{
    int result = 0;

    RSZ(i, s) { if (s[i][1] == 2) {
	    int r = s[i][0]*2;
	    if (r == n) { result++; continue; }
	    if (r > n) break;
	    RSZ(j, s) {
		int r2 = r + s[j][0]*s[j][1];
		if (r2 == n) { result++; continue; }
		if (r2 > n) break;
		FSZ(k, j, s) {
		    int r3 = r2 + s[k][0]*s[k][1];
		    if (r3 == n) { result++; continue; }
		    if (r3 > n) break;
		}
	    }
	}
    }
    return result;
}

int main()
{
    VVI s = createScores();
    sort(ALL(s), cmpScores);
    // RSZ(i, s) print(s[i]);
    int result = 0;
    int n = 100;
    F(i, 1, n) result += checkout(s, i);
    cout<<result <<endl;
}
