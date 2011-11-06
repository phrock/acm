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

#define A(x)  (x).begin(), (x).end()
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
#define UN(a) sort(A(a)), a.erase(unique(A(a)), a.end())
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


void cutInHalf(VI& v, int n)
{
    if (v[n] > 0) return;
    
    cutInHalf(v, n-1);
    v[n-1]--;
    v[n] += 2;
}

map<VI, long double> doJobs(const VI& v, long double x)
{
    map<VI, long double> m;

    if (v[0] == 0 &&
	v[1] == 0 &&
	v[2] == 0 &&
	v[3] == 0 &&
	v[4] == 0 &&
	v[5] == 1)
	return m;

    m[v] += x;

    int papers = 0;
    RSZ(i, v) papers += v[i];

    RSZ(i, v) {
	if (v[i] == 0) continue;

	VI nextPaper = v;
	nextPaper[i]--;
	FSZ(j, i+1, nextPaper) nextPaper[j]++;
	map<VI, long double> mt = doJobs(nextPaper, x/papers);
	RA(j, mt) m[j->first] += v[i] * j->second;
    }

    return m;
}

long double countSingle(const map<VI, long double>& m)
{
    long double result = 0;

    RA(i, m) {
	if (((i->first)[2] == 1 && (i->first)[3] == 0 &&
	     (i->first)[4] == 0 && (i->first)[5] == 0) ||
	    ((i->first)[2] == 0 && (i->first)[3] == 1 &&
	     (i->first)[4] == 0 && (i->first)[5] == 0) ||
	    ((i->first)[2] == 0 && (i->first)[3] == 0 &&
	     (i->first)[4] == 1 && (i->first)[5] == 0)) {
	    result += i->second;
	    cout <<"***"<<endl;
	    cout<<i->second<<" : ";  print(i->first);
	}
    }
    return result;
}

int main()
{
    int n = 5;
    VI v(n+1);
    v[1] = 1;

    cutInHalf(v, 5);
    v[5]--;

    map<VI, long double> m = doJobs(v, 1);
    long double total = 0;
    RA(i, m) { total += i->second; cout<<i->second<<" : ";  print(i->first); }

    long double single = countSingle(m);
    cout << single << " : "<<total<<endl;
    cout <<"///////////"<<endl;

}
