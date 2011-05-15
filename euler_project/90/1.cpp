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
//#define FA(i, x)  for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
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


bool check(const set<int>& s1, const set<int>& s2)
{
    set<int> p = s1;
    set<int> q = s2;
    RA(i, p) { if (*i == 6) p.insert(9); if(*i == 9) p.insert(6); }
    RA(i, q) { if (*i == 6) q.insert(9); if(*i == 9) q.insert(6); }

    F(i, 1, 9) {
	int sq = i*i;
	int a = sq / 10;
	int b = sq % 10;

	if ((p.count(a)>0 && q.count(b)>0) ||
	    (p.count(b)>0 && q.count(a)>0)) continue;
	else return false;
    }
    cout <<"*******"<<endl;print(p);print(q);
    return true;
}

int main()
{
    int count = 0;
    set< set<int> > s;
    FE(i1, 0, 4) FE(i2, i1+1, 5) FE (i3, i2+1, 6)
	FE (i4, i3+1, 7) FE(i5, i4+1, 8) FE(i6, i5+1, 9) {
	set<int> s1;
	s1.insert(i1);	s1.insert(i2);	s1.insert(i3);
	s1.insert(i4);	s1.insert(i5);	s1.insert(i6);
	// RA(i, s1) { if (*i == 6) s1.insert(9); if(*i == 9) s1.insert(6); }

	s.insert(s1);
    }

    // RA(i, s) print(*i);

    RA(i, s) FA(j, i, s) {
	// cout <<"*******"<<endl;print(*i);print(*j);}
	if (check(*i, *j)) count++;
    }
    cout << count<<endl;
}
