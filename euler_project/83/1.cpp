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


bool cmpVector(const VI& a, const VI& b)
{
    // cout << a[0] <<" "<< b[0] << endl;
    return a[0] < b[0];
}

bool findNext(const VVI& vv, const VVI& result, int i, int j, int& x, int& y)
{
    int n = vv.size();
    int tmp = INT_MAX;
    bool flag = false;
    if (i-1>=0 && result[i-1][j]==INT_MAX && tmp>vv[i-1][j]) {
	x=i-1; y=j; flag = true; tmp = vv[i-1][j];
    }
    if (i+1<n && result[i+1][j]==INT_MAX && tmp>vv[i+1][j]) {
	x=i+1; y=j; flag = true; tmp = vv[i+1][j];
    }
    if (j-1>=0 && result[i][j-1]==INT_MAX && tmp>vv[i][j-1]) {
	x=i; y=j-1; flag = true; tmp = vv[i][j-1];
    }
    if (j+1<n && result[i][j+1]==INT_MAX && tmp>vv[i][j+1]) {
	x=i; y=j+1; flag = true; tmp = vv[i][j+1];
    }
    // cout << flag <<"***"<<x<<" "<<y<<endl;
    return flag;
}

int main()
{
    int n = 80;
    // int n = 5;
    VVI vv(n, VI(n));

    int x = 0;
    REPSZ(i, vv) REPSZ(j, vv[i]) { cin>>x; vv[i][j] = x; };

    // REPSZ(i, vvi) print(vvi[i]);

    VVI result(n, VI(n, INT_MAX));
    result[0][0] = vv[0][0];

    VVI used;
    VI v(3);
    v[0] = vv[0][0];
    v[1] = 0;
    v[2] = 0;
    used.PB(v);

    while (true) {
	// REPSZ(i, result) print(result[i]);
	sort(used.begin(), used.end(), cmpVector);
	int x = 0;
	int y = 0;
	int i = 0;
	for (i=0; i<used.size(); i++) {
	    if (findNext(vv, result, used[i][1], used[i][2], x, y) == true) break;
	}
	// cout << x <<" : "<< y<< " ::  "<<i<<endl;
	result[x][y] = vv[x][y] + used[i][0];

	VI v(3);
	v[0] = result[x][y];
	v[1] = x;
	v[2] = y;
	used.PB(v);

	if (result[n-1][n-1] < INT_MAX) break;
	// if (used.size() == n*n) break;
    }

    // REPSZ(i, result) print(result[i]);
   
    cout << result[n-1][n-1] << endl;
}
