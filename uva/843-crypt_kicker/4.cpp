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
template<class T> void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> void print(T A) { cout<<"{"; RA(i, A) { cout<<*i<<", "; } cout<<"}"<<endl; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


void decrypt(const vector< set<string> >& dic, const VS& v, const string& s)
{
    map<char, char> m;
    pair<map<char, char>, int> state = MP(m, 0);
    stack< pair<map<char, char>, int> > stk;
    stk.push(state);

    while (!stk.empty()) {
	state = stk.top();
	stk.pop();

	if (state.Y == SZ(v)) {
	    RSZ(i, s) if (s[i] != ' ') cout <<state.X[s[i]]; else cout <<' ';
	    cout << endl;
	    return;
	}
	int n = state.Y;
	RA(i, dic[SZ(v[n])]) {
	    bool flag = true;
	    m = state.X;
	    RSZ(j, v[n])
		if (!P(m, v[n][j])) m[v[n][j]] = (*i)[j];
		else if (m[v[n][j]] != (*i)[j]) { flag = false; break; }
	    if (flag) stk.push(MP(m, n+1));
	}
    }
    
    RSZ(i, s) if (s[i] != ' ') cout << '*'; else cout <<' ';
    cout << endl;
}

bool cmp(const string& a, const string& b)
{
    return SZ(a) > SZ(b);
}

int main()
{
    int n;
    string s;
    getline(cin, s);
    ISS iss(s);
    iss >> n;
    vector< set<string> > dic(17);
    R(i, n) { getline(cin, s); dic[SZ(s)].insert(s); }
    // RSZ(i, dic) print(dic[i]);
    while (getline(cin, s)) {
	// if (!SZ(s)) continue;

	ISS iss(s);
	VS v;
	string t;
	while (iss >> t) v.pb(t);
	UN(v);
	sort(A(v), cmp);
	// print(v);
	decrypt(dic, v, s);
    }
}
