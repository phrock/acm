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

LL fac(LL n)
{
    LL r=1;
    REP(i, n) r*=(i+1);

    return r;
}

LL nextN(LL n, const VI& v)
{
    LL r = 0;
    while (n != 0) {
	r += v[n%10];
	n /= 10;
    }
    return r;
}
int countChain(int n, const VI& v)
{
    int r=1;
    map<int, int> mp;
    
    mp[n]++;

    LL next = nextN(n,v);

    while (mp[next] == 0) {
	// cout << next<<" && ";

	mp[next]++;
	r++;
	next = nextN(next,v);
	// cout << next<<endl;
		
    }

    cout << "********* "<<n<<" "<<r<<endl;
    return r;
}

int main()
{
    VI v(10);
    REPSZ(i, v) v[i] = fac(i);
    print(v);

    int n = 1000000;
    int m = 60;
    int r = 0;
    REP(i, n) if (countChain(i, v) == m) r++;

    cout << r << endl;
}
