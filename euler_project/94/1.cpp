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

void pythagoreanTriangle(int a, int b, int c, int M, set<VI>& s)
{
    int m = max(a, b);
    m = max(m, c);
    if (m > M) return;

    int t = min(a, b);
    t = min(t, c);

    for (int i=1; i*m<=M; i++) {
	int x = i*m;
	int y = i*t;
	if (2*y == x+1 || 2*y == x-1) {
	    VI v(2);
	    v[0] = m;
	    v[1] = t;
	    s.insert(v);
	}
    }

    pythagoreanTriangle(a-2*b+2*c, 2*a-b+2*c, 2*a-2*b+3*c, M, s);
    pythagoreanTriangle(a+2*b+2*c, 2*a+b+2*c, 2*a+2*b+3*c, M, s);
    pythagoreanTriangle(-a+2*b+2*c, -2*a+b+2*c, -2*a+2*b+3*c, M, s);
}

int check(int n, const set<VI> s)
{
    if (n%2 == 0) return 0;

    int result = 0;
    VI v(2);
    v[0] = n;
    v[1] = (n+1)/2;
    if (s.find(v) != s.end()) result += 3*n+1;
    v[1] = (n-1)/2;
    if (s.find(v) != s.end()) result += 3*n-1;

    return result;
}
    

int main()
{
    int n = 1000000000;
    int m = (n-1)/3;

    set<VI> s;
    pythagoreanTriangle(3, 4, 5, m, s);

    RA(i, s) print(*i);

    int result = 0;

    RA(i, s) result += 2*((*i)[0] + (*i)[1]);

    cout << result << endl;
}
