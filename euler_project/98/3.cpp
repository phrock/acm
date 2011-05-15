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


bool isSqureNum(int n)
{
    int x = sqrt(n);
    if (x*x == n) return true;
    else return false;
}

VVI squreNum()
{
    int m = 1000000000;

    VVI vv;
    for (int i=1; i*i<=m; i++) {
	int n = i*i;
	VI v;
	while (n != 0) { v.pb(n%10); n /= 10; }
	reverse(ALL(v));
	vv.pb(v);
    }

    return vv;
}

int anagramNum(const string& a, const string& b, const VVI& sq)
{
    int result = 0;
    RSZ(i, sq) {
	if (a.size() != sq[i].size()) continue;
	map<char, int> m;
	vector<char> vc(10, '*');
	bool flag = true;
	RSZ(j, a) {
	    int t = sq[i][j];
	    if (m[a[j]] > 0 && m[a[j]] != t) { flag = false; break; }
	    if (vc[t] != '*' && a[j] != vc[t]) { flag = false; break; }

	    vc[t] = a[j];
	    m[a[j]] = t;
	}
	if (flag == false) continue;

	int bn = 0;
	RSZ(j, b) bn = bn*10 + m[b[j]];
	if (isSqureNum(bn)) {
	    if (vc[0] != '*' && vc[0] == b[0]) continue;
	    int an = 0;
	    RSZ(j, a) an = an*10 + m[a[j]];
	    int tmp = max(an, bn);
	    checkmax(result, tmp);
	    cout << "aaa "<<a<<" : "<<b<<"  "<<an<< ":"<<bn<<endl;
	}
    }

    RSZ(i, sq) {
	if (b.size() != sq[i].size()) continue;
	map<char, int> m;
	vector<char> vc(10, '*');
	bool flag = true;
	RSZ(j, b) {
	    int t = sq[i][j];
	    if (m[b[j]] > 0 && m[b[j]] != t) { flag = false; break; }
	    if (vc[t] != '*' && b[j] != vc[t]) { flag = false; break; }

	    vc[t] = b[j];
	    m[b[j]] = t;
	}
	if (flag == false) continue;

	int an = 0;
	RSZ(j, a) an = an*10 + m[a[j]];
	if (isSqureNum(an)) {
	    if (vc[0] != '*' && vc[0] == a[0]) continue;
	    int bn = 0;
	    RSZ(j, b) an = bn*10 + m[b[j]];
	    int tmp = max(an, bn);
	    checkmax(result, tmp);
	    cout <<"bbb "<< a<<" : "<<b<<"  "<<an<< ":"<<bn<<endl;
	}

    }

    return result;
}

bool check(const string& a, const string& b)
{
    VI va(26);
    VI vb(26);

    RSZ(i, a) va[a[i]-'A']++;
    RSZ(i, b) vb[b[i]-'A']++;

    if (va == vb) return true;
    else return false;
}

int main()
{
    VS vs;
    string s;
    while (cin >> s) vs.pb(s);

    set<VS> st;
    RSZ(i, vs) FSZ(j, i+1, vs) {
	if (check(vs[i], vs[j])) {
	    VS v(2); v[0] = vs[i]; v[1] = vs[j];
	    st.insert(v);
	}
    }

    RA(i, st) print(*i);

    VVI sq = squreNum();
    // RSZ(i, sq) print(sq[i]);

    // cout << anagramNum("CARE", "RACE", sq) << endl;

 int result = 0;
 int tmp = 0;
 RA(i, st) {
 	tmp = anagramNum((*i)[0], (*i)[1], sq);
 	checkmax(result, tmp);
 }

 cout << result << endl;
}
