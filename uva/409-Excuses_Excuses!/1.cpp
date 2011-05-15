#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
typedef pair< int, int > II;
typedef vector< II > VII;
typedef vector< VII > VVII;
typedef istringstream ISS;
typedef ostringstream OSS;

#define A(x)  (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define F(i, a, b)  for (int i=(a); i<(b); ++i)
#define R(i, n)  F(i, 0, n)
#define FE(i, a, b)  for (int i=(a); i<=(b); ++i)
#define RE(i, n)  FE(i, 0, n)
#define FD(i, a, b)  for (int i=(a); i>=(b); --i)
#define RD(i, n) FD(i, n, 0)
#define FSZ(i, a, v)  F(i, a, SZ(v))
#define RSZ(i, v)  R(i, SZ(v))
#define FDSZ(i, a, v) FD(i, SZ(v)-1, a)
#define RDSZ(i, v) RD(i, SZ(v)-1)
#define FA(i, a, x)  for (__typeof((x).begin()) i=(a); i!=(x).end(); ++i)
#define RA(i, x)  FA(i, (x).begin(), x)
#define FDA(i, a, x)  for (__typeof((x).rbegin()) i=(x).rbegin(); i!=(a); ++i)
#define RDA(i, x)  FDA(i, (x).rend(), x)
#define P(v, x) (v.find(x) != v.end())
#define PO(v, x) (find(A(v), x) != v.end())
#define UN(a) sort(A(a)), a.erase(unique(A(a)), a.end())
#define CL(a, b) memset(a, b, sizeof(a))
#define MP(a, b)  make_pair(a, b)
#define CAST(x, type) *({ OSS oss; oss << (x); ISS iss(oss.str()); static type _cast_ret; iss >> _cast_ret; &_cast_ret; })
#define pb push_back
#define pf push_front
#define X first
#define Y second

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> inline void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> inline void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> inline void print(T A) { cout<<"{"; RA(i, A) { cout<<*i<<", "; } cout<<"}"<<endl; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


int check(const string& s, const string& dest_case)
{
    // cout <<"///"<<endl<< s << endl<<dest<<endl<<"///"<<endl;
    string dest = dest_case;
    RSZ(i, dest) dest[i] = tolower(dest[i]);
    int k = 0;
    int ret = 0;
    int x = 0;
    while (true) {
	x = dest.find(s, k);
	if (x == string::npos) break; else k = x+SZ(s);
	if ((x == 0 || !isalpha(dest[x-1])) && !isalpha(dest[x+SZ(s)])) ret++;
    }
    return ret;
}

void excuse(const VS& vs1, const VS& vs2)
{
    VI v(SZ(vs2));
    RSZ(i, vs2) RSZ(j, vs1) v[i] += check(vs1[j], vs2[i]);
    // print(v);
    int m = -1;
    RSZ(i, v) checkmax(m, v[i]);
    RSZ(i, v) if (v[i] == m) cout << vs2[i] << endl;
}

int main()
{
    string s;
    int a, b;
    int k = 0;
    while (getline(cin, s)) {
	cout << "Excuse Set #" << ++k << endl;
	ISS iss(s);
	iss >> a >> b;
	VS vs1(a);
	VS vs2(b);
	RSZ(i, vs1) { getline(cin, s); ISS t(s); t >> vs1[i]; }
	RSZ(i, vs2) getline(cin, vs2[i]);
	// print(vs1); print(vs2);
	excuse(vs1, vs2);
	cout << endl;
    }
}
