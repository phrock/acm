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
#define FA(i, x)  for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define UN(a) sort(ALL(a)), a.erase(unique(ALL(a)), a.end())
#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pf push_front
#define MP(a, b)  make_pair(a, b)

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> void print(T A) { cout<<"{"; FA(i, A) { cout<<*i<<", "; } cout<<"}"<<endl; }
template<class T> inline void intToString(const T& a, string& s) { stringstream ss; ss<<a; s=ss.str(); }
template<class T> inline void stringToInt(const string& s, T& a) { istringstream iss(s); iss>>a; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


void factorizationHelper(const VI& x, set<VI>& s, map< VI, set<VI> >& m)
{
    RSZ(i, x) {
	int n = x[i];
	for (int j=2; j*j<=n; j++) {
	    if (n%j == 0) {
		VI v = x;
		    
		v[i] = j;
		v.pb(n/j);
		sort(ALL(v));

		if (m.find(v) != m.end()) FA(k, m[v]) s.insert(*k);
		else factorizationHelper(v, s, m);
	    }

	}
    }
    s.insert(x);
    m[x] = s;
}

set<VI> factorization(int n)
{
    set<VI> s;
    VI v;
    v.pb(n);
    map< VI, set<VI> > m;
    factorizationHelper(v, s, m);

    return s;
}

void update(VI& v, int n, int limit)
{
    set<VI> s = factorization(n);
    FA(i, s) {
	if ((*i).size() == 1) continue;
	int sum = 0;
	RSZ(j, *i) sum += (*i)[j];
	int k = n-sum+(*i).size();
	if (k<0 || k>limit) continue;
	if (v[k] == 0) v[k] = n;
    }
}

int main()
{

    int k = 12000;
    int m = 2*k;

    VI v(k+1, 0);

    FE(i, 4, m) {
	cout << i<<endl;
	update(v, i, k);
    }
    // print(v);
    UN(v);
    // print(v);

    int sum = 0;
    RSZ(i, v) sum += v[i];
    cout << sum << endl;
}
