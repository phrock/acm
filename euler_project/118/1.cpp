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


bool isPrime(int n)
{
    if (n < 2) return false;
    int sq = sqrt(n);
    FE(i, 2, sq) if (n%i == 0) return false;
    return true;
}

int vectorToInt(const VI& v, int a, int b)
{
    int r = 0;
    FE(i, a, b) r = r*10 + v[i];
    return r;
}

void allPrime(const VI& v, int a, const set<int>& ts, set< set<int> >& s)
{
    if (a == 9) s.insert(ts);

    FSZ(i, a, v) {
	int x = vectorToInt(v, a, i);
	if (isPrime(x) == false) continue;
	set<int> tmp = ts;
	tmp.insert(x);
	allPrime(v, i+1, tmp, s);
    }
}

int main()
{
    VI v(9);
    RSZ(i, v) v[i] = i+1;

    LL r = 0;
    // while (next_permutation(ALL(v))) {
    // 	r++;
    // 	print(v);
    // }
    // cout << r<<endl;

    set< set<int> > s;
    set<int> ts;

    // v[0]= 2;    v[1]= 5;    v[2]= 4;    v[3]= 7;    v[4]= 8;    v[5]= 9;    v[6]= 6;    v[7]= 3;    v[8]= 1;
    // print(v);
    allPrime(v, 0, ts, s);
    while (next_permutation(ALL(v))) { ts.clear(); allPrime(v, 0, ts, s); }
    RA(i, s) print(*i);
    cout << s.size()<<endl;
}
