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



int clearSet(set< set<int> > & ss)
{
    int small = INT_MAX;
    RA(i, ss) checkmin(small, (int)(*i).size());
    RA(i, ss) if ((*i).size() > small) ss.erase(i);
    return small;
}

int productHelper(vector< set< set<int> > >& vss, int a, int b, int sm)
{
    int x = a+b;

    RA(i, vss[a]) {
	if ((*i).size() >= sm) continue;
	RA(j, vss[b]) {
	    if ((*j).size() >= sm) continue;
	    set<int> s = *i;
	    s.insert(x);
	    RA(k, *j) {
		s.insert(*k);
	    }
	    vss[x].insert(s);
	}
    }
    int small = clearSet(vss[x]);
    return small;
}

int product(int k)
{
    vector< set< set<int> > > vss(k+1);
    set< set<int> > ss;
    set<int> s;
    s.insert(1);
    ss.insert(s);
    vss[1] = ss;

    int r = 0;
    FSZ(i, 2, vss) {
	int small = INT_MAX;
	FE(j, 1, i/2) {
	    int r = productHelper(vss, j, i-j, small);
	    checkmin(small, r);
	}
	r += small-1;
    }

    // RSZ(i, vss) {
    // 	cout << "********* "<< i<<endl;
    // 	RA(j, vss[i]) print(*j);
    // }

    RA(j, vss[k]) print(*j);
    cout << r<<endl;
    return 0;
}

int main()
{
    int k = 200;

    product(k);
}
