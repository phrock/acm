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

void run(int n, set<VI>& s, const VI& v)
{
    int l = v[3];
    int k = n/l;

    VI tmp = v;
    FORE(i, 1, k) {
	REPSZ(j, tmp) tmp[j] = i*v[j];
	s.insert(tmp);
    }
}

bool cmp(const VI& a, const VI& b)
{
    return a[3] < b[3];
}

int main()
{
    int N = 2000000;
    int M = 1000;
    int result = 0;

    set<VI> s;
    
    FOR(m, 1, M) FOR(n, 1, m) {
	int a = m*m - n*n;
	int b = 2*m*n;
	int c = m*m + n*n;

	if (a+b > c && gcd(m, n) == 1) {
	    VI v(4);
	    v[0] = a;
	    v[1] = b;
	    v[2] = c;
	    v[3] = a+b+c;
	    sort(v.begin(), v.end());
	    //print(v);

	    run(N, s, v);
	}
    }
    cout << s.size() << endl;

    // VVI vvi(s.begin(), s.end());
    // cout << vvi.size()<<endl;

    // sort(vvi.begin(), vvi.end(), cmp);
    // REPSZ(i, vvi) print(vvi[i]);

    VI r(N+1);
    FOREACH(i, s) r[(*i)[3]]++;
    REPSZ(i, r) if (r[i] == 1) result++;

    cout << result << endl;
}
