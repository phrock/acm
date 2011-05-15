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
#define P(v, x) ((v).find(x) != (v).end())
#define PO(v, x) (find(A(v), x) != (v).end())
#define UN(a) sort(A(a)), (a).erase(unique(A(a)), (a).end())
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


pair<LL, LL> calculate(const string& s)
{
    VLL v;
    VI sign_add, sign_multi;
    int p = 0;
    while (true) {
	int a = s.find('+', p);
	int b = s.find('*', p);
	if (a == string::npos && b == string::npos) { v.pb(CAST(s.substr(p), LL)); break; }
	if (a == string::npos) { v.pb(CAST(s.substr(p, b-p), LL)); sign_multi.pb(SZ(v)-1); p = b+1; continue; }
	if (b == string::npos) { v.pb(CAST(s.substr(p, a-p), LL)); sign_add.pb(SZ(v)-1); p = a+1; continue; }
	if (a < b) { v.pb(CAST(s.substr(p, a-p), LL)); sign_add.pb(SZ(v)-1); p = a+1; continue; }
	else { v.pb(CAST(s.substr(p, b-p), LL)); sign_multi.pb(SZ(v)-1); p = b+1; continue; }
    }
    print(v); print(sign_multi); print(sign_add);
    LL x = 0;
    VLL t = v;
    RSZ(i, sign_multi) { int a = sign_multi[i]; int b = a+1; x = t[a]*t[b]; t[b] = x;
	RD(j, i-1) if (sign_multi[j]+1 == sign_multi[j+1]) t[sign_multi[j]] = x; else break; print(t); }
    RSZ(i, sign_add) { int a = sign_add[i]; int b = a+1; x = t[a]+t[b]; t[a] = x;
	RD(j, b-1) if (sign_add[j]+1 == sign_add[j+1]) t[j] = x; else break; print(t); }
    
    LL y = 0;
    t = v;
    RSZ(i, sign_add) { int a = sign_add[i]; int b = a+1; y = t[a]+t[b]; t[a] = y; t[b] = y; }
    RSZ(i, sign_multi) { int a = sign_multi[i]; int b = a+1; y = t[a]*t[b]; t[a] = y; t[b] = y; }

    return MP(x, y);
}

int main()
{
    int n;
    string s;
    cin >> n;
    R(i, n) {
	cin >> s;
	pair<LL, LL> ret = calculate(s);
	cout << "The maximum and minimum are " << ret.X << " and " << ret.Y << "." << endl;
    }
}
