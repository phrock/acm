/*
  ID:   rock2to1
  LANG: C++
  PROG: crypt1
*/

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


bool check(const VI& a, int x, const VI& v)
{
	int carry = 0;
	RSZ(i, a) {
		int tmp = x*a[i] + carry;
		if (tmp > 9) { carry = tmp/10; tmp %= 10; }
		else carry = 0;
		
		if (find(A(v), tmp) == v.end()) return false;
	}
	if (carry > 0) return false;
	else return true;
	
	// int m = 0;
	// int t = 1;
	// RSZ(i, a) { m += a[i]*t; t *= 10; }
	// m *= x;
	// if (m/1000 > 0) return false;
	// while (m > 0) {
	// 	t = m%10;
	// 	if (find(A(v), t) == v.end()) return false;
	// 	m /= 10;
	// }
	// return true;
}

bool checkall(const VI& a, const VI& b, const VI& v)
{
	int x = 0;
	int t = 1;
	RSZ(i, a) { x += a[i]*t; t *= 10; }
	
	int y = 0;
	t = 1;
	RSZ(i, b) { y += b[i]*t; t *= 10; }

	int z = x*y;
	if (z/10000 > 0) return false;
	while (z > 0) {
		t = z % 10;
		if (find(A(v), t) == v.end()) return false;
		z /= 10;
	}
	// cout << x << " "<<y<<" "<<x*y<<endl;
	return true;
}

void dfs(const VI& a, int ai, const VI& b, int bi, const VI& v, int& ret)
{
	// cout << ret << endl;
	if (ai < a.size()) {
		VI at(a);
		RSZ(i, v) { at[ai] = v[i]; dfs(at, ai+1, b, bi, v, ret); }
	} else if (bi < b.size()) {
		RSZ(i, v) {
			VI bt(b);
			bt[bi] = v[i];
			if (check(a, bt[bi], v)) dfs(a, ai, bt, bi+1, v, ret);
		}
	} else if (checkall(a, b, v)) {
		ret++;
	}
}

int crypt(int n, const VI& v)
{
	int ret = 0;
	VI a(3);
	VI b(2);

	dfs(a, 0, b, 0, v, ret);
	return ret;
}

int main()
{
	ifstream fin("crypt1.in");
	ofstream fout("crypt1.out");

	int n;
	fin >> n;
	VI v(n);
	R(i, n) fin >> v[i];

	int ret = crypt(n, v);
	fout << ret << endl;

	return 0;
}
