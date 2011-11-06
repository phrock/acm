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


void dfs(const VVI& vv, VI& explored, int start)
{
    if (explored[start] == 1) return;
    explored[start] = 1;

    RSZ(i, vv[start]) if (vv[start][i] != -1) dfs(vv, explored, i);
}

bool isConnected(const VVI& vv)
{
    int n = vv.size();

    int start = 0;
    VI explored(n);
    dfs(vv, explored, start);
    
    RSZ(i, explored) if (explored[i] == 0) return false;
    return true;
}

bool isJoin(const VVI& vv, int x, int y)
{
    int start = x;

    VI explored(vv.size());
    dfs(vv, explored, start);

    if (explored[y] == 1) return true;
    else return false;
}

VVI buildMinPath(const VVI& vv)
{
    int n = vv.size();
    VVI path(n, VI(n, -1));
    
    while (isConnected(path) == false) {
	int x = 0;
	int y = 0;
	int p = INT_MAX;
	R(i, n) F(j, i+1, n) {
	    if (vv[i][j]!=-1 && isJoin(path, i, j)==false && vv[i][j]<p) {
		p = vv[i][j];
		x = i;
		y = j;
	    }
	}
	path[x][y] = p;
	path[y][x] = p;
    }

    return path;
}

int countWeight(const VVI& vv)
{
    int result = 0;
    RSZ(i, vv) R(j, i) if (vv[i][j] != -1) result += vv[i][j];
    return result;
}

int main()
{
    ifstream ifs("input");
    // ifstream ifs("test.in");
    VVI vv;
    string s;
    while (getline(ifs, s)) {
	ISS is(s);
	string t;
	VI v;
	while (is >> t) {
	    if (t == "-") v.pb(-1);
	    else { int x = 0; stringToInt(t, x); v.pb(x); }
	}
	vv.pb(v);
    }

    // RSZ(i, vv) print(vv[i]);
    // cout<< isConnected(vv)<<endl;

    VVI minPath = buildMinPath(vv);
    // cout <<"************"<<endl;
    // RSZ(i, minPath) print(minPath[i]);

     cout <<countWeight(vv)<<endl;
     cout<<countWeight(minPath)<<endl;
    cout << countWeight(vv) - countWeight(minPath) << endl;
}
