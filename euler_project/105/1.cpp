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

set< set<int> > buildSubset(const set<int>& s)
{
    set< set<int> > ss;
    if (s.size() == 0) { ss.insert(s); return ss; }

    int x = *s.begin();
    set<int> a = s;
    a.erase(a.begin());

    set< set<int> > b = buildSubset(a);
    RA(i, b) { set<int> t = *i; ss.insert(t); t.insert(x); ss.insert(t); }

    return ss;
}

vector< pair<int, int> > buildProperty(const set< set<int> >& ss)
{
    vector< pair<int, int> > vp;
    RA(i, ss) {
	int sz = (*i).size();
	int sum = 0;
	RA(j, *i) sum += *j;
	pair<int, int> p(sz, sum);
	vp.pb(p);
    }
    
    return vp;
}

bool isSpecialSet(const set<int>& s)
{
    set< set<int> > ss = buildSubset(s);
    RA(i, ss) { if ((*i).size() == 0 || (*i).size() == s.size()) ss.erase(i); }

    vector< pair<int, int> > vp = buildProperty(ss);
    RSZ(i, vp) FSZ(j, i+1, vp) {
	if ((vp[i].second == vp[j].second) ||
	    (vp[i].first > vp[j].first && vp[i].second <= vp[j].second) ||
	    (vp[i].first < vp[j].first && vp[i].second >= vp[j].second)) {
	    return false;
	}
    }

    return true;
}

int main()
{
    string s;
    ifstream in("input");

    int result = 0;
    while (getline(in, s)) {
	istringstream is(s);
	int x;
	set<int> st;
	while (is >> x) { st.insert(x); }
	// print(s);
	if (isSpecialSet(st)) {
	    int sum = 0;
	    RA(i, st) sum += *i;
	    result += sum;
	}
    }

    cout << result << endl;
}
