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


bool combine(const VVI& vvi, int n, const VI& state)
{
    if (n == vvi.size()) { print(state); return true; }

    int len = state.size();
    VI v = vvi[n];
    FOR(i, 0, len-2) {
	if ((state[i] != -1) && (state[i] != v[0])) continue;
	FOR(j, i+1, len-1) {
	    if ((state[j] != -1) && (state[j] != v[1])) continue;
	    FOR(k, j+1, len) {
		if ((state[k] != -1) && (state[k] != v[2])) continue;
		VI newState = state;
		newState[i] = v[0];
		newState[j] = v[1];
		newState[k] = v[2];

		if (combine(vvi, n+1, newState) == true) return true;
	    }
	}
    }
    return false;
}

bool mycmp(const VI& a, const VI& b)
{
    REPSZ(i, a) if(a[i] != b[i]) return a[i]-b[i];
}

int main()
{
    VVI vvi;
    set< VI > st;
    int a = 0;
    while (cin >> a) {
	VI v(3);
	v[0] = a/100;
	v[1] = (a%100)/10;
	v[2] = a%10;
	st.insert(v);
    }
    // FOREACH(i, st) print(*i);
    FOREACH(i, st) vvi.PB(*i);
    REPSZ(i, vvi) print(vvi[i]);

    int len = 3;

    VI v(len, -1);
    while (combine(vvi, 0, v) == false) {
	v.PB(-1);
    }

}
