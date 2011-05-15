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


bool cmpVector(const VVI::const_iterator a, const VVI::const_iterator b)
{
    // cout << a[0] <<" "<< b[0] << endl;
    return (*a)[0] - (*b)[0];
}

bool mycmp(int a, int b)
{
    return b-a;
}

bool sss(const string& a, const string& b)
{
    return a.length()-b.length();
}

int main()
{
    VVI vv;
    VI v(3);
    v[0] = 1;
    v[1] = 5;
    v[2] = 6;

    vv.PB(v);
    v[0] = 2;
    v[1] = 7;
    v[2] = 8;

    vv.PB(v);
    REPSZ(i, vv) print(vv[i]);
    // sort(vv.begin(), vv.end(), cmpVector);
    REPSZ(i, vv) print(vv[i]);
    cout << "//////"<<endl;

    VI v2;
    v2.PB(2);
    v2.PB(1);
    v2.PB(3);
    sort(v2.begin(), v2.end(), mycmp);
    //    sort(v2.begin(), v2.end());
    print(v2);

    VS vs;
    vs.PB("12");
    vs.PB("9");
    vs.PB("312");

    sort(vs.begin(), vs.end(), sss);
    print(vs);
}
