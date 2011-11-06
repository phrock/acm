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
typedef vector< double > VD;
typedef vector< string > VS;
typedef istringstream ISS;

#define ALL(x)  (x).begin(), (x).end()
#define SIZE(x) (int)(x).size()
#define FOR(i, a, b)  for (int i=(a); i<(b); ++i)
#define REP(i, n)  FOR(i, 0, n)
#define FORE(i, a, b)  for (int i=(a); i<=(b); ++i)
#define REPE(i, n)  FORE(i, 0, n)
#define FORD(i, a, b)  for (int i=(a); i>=(b); --i)
#define FORSZ(i, a, v)  FOR(i, a, SIZE(v))
#define REPSZ(i, v)  REP(i, SIZE(v))
#define FOREACH(i, x)  for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define PB push_back
#define PF push_front
#define MP(a, b)  make_pair(a, b)

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> inline void intToString(const T& a, string& s) { stringstream ss; ss<<a; s=ss.str(); }
template<class T> inline void stringToInt(const string& s, T& a) { istringstream iss(s); iss>>a; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


int triangleNum(int n)
{
    int result = 0;
    FORE(i, 1, n-2) FORE(j, i, n-i-1) {
	int k = n-i-j;
	if (i+j<=k || i+k<=j || j+k<=i) continue;

	if (k<i || k<j) continue;

	LL x = (LL)i;
	LL y = (LL)j;
	LL z = (LL)k;
	if (x*x + y*y == z*z) {
	    result++;
	}
    }

    return result;
}

void countTriangle(VI& v)
{
    int n = SIZE(v);
    FOR(i, 12, n) {
	cout << i << endl;
	if (v[i] == 0) {
	    v[i] = triangleNum(i);
	    int j = i+i;
	    while (j < n) {
		v[j] = v[i];
		j +=i;
	    }
	}
    }
}

int main()
{
    int n = 2000001;
    //    int n = 51;
    VI v(n);
    countTriangle(v);
    int result = 0;
    
    FOR(i, 0, n) if (v[i] == 1) result++;

    cout << result << endl;
}
