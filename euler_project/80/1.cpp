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

#include <gmpxx.h>

bool sqrtNum(int n)
{
    int x = sqrt(n);
    if (x*x == n) {
	return true;
    } else {
	return false;
    }
}
vector<int> initVector(int n)
{
    vector<int> v(4);
    int sq = sqrt(n);

    v[0] = sq;
    v[1] = 1;
    v[2] = n;
    v[3] = sq;

    return v;
}

vector<int> nextVector(const vector<int>& v)
{
    vector<int> result(4);

    int a = v[2] - v[3]*v[3];
    a /= v[1];
    int b = v[2];
    int c = v[3];

    int sq = sqrt(b);
    
    int d = 0;
    while ((d*a - c) <= sq) {
	d++;
    }
    d--;

    c = d*a - c;
    // cout <<d<<" "<< a<< " " <<b<<" "<<c<<endl;
    result[0] = d;
    result[1] = a;
    result[2] = b;
    result[3] = c;

    return result;
}

int get100Ditigs(int n)
{
    VI v = initVector(n);
    VI s;
    s.PB(v[0]);
    int m = 1000;
    FOR(i, 0, m) { v = nextVector(v); s.PB(v[0]); }

    mpz_class a = 1;
    mpz_class b = s[s.size()-1];
    FORD(i, s.size()-2, 0) {
	mpz_class c = s[i]*b + a;

	mpz_class gcd;
	mpz_gcd(gcd.get_mpz_t(), b.get_mpz_t(), c.get_mpz_t());
	c /= gcd;
	b /= gcd;

	a = b;
	b = c;
    }
    mpz_class result = 0;

    FOR(i, 0, 100) { result += (b/a); b = b%a*10; }
    cout << result << endl;
    return result.get_si();
}

int main()
{
    int n = 100;
    int result = 0;
    FORE(i, 1, n) {
 	if (sqrtNum(i) == true) continue;
 	result += get100Ditigs(i);
    }
    cout << result << endl;
    // get100Ditigs(2);
}
