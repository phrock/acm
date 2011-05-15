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

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> void print(T A) { cout<<"{"; RA(i, A) { cout<<*i<<", "; } cout<<"}"<<endl; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


void dfs(const VII& p, const VII& path, const set<int>& s, VII& ret, bool& flag)
{
    // cout <<"*******"<<endl;
    // print(s);
    // cout <<"//////////"<<endl;
    // RSZ(i, path) cout << path[i].first<<" "<<path[i].second<<endl;
    // cout <<"*******"<<endl;
    
    if (flag) return;
    if (SZ(path) == SZ(p)) { flag = true; ret = path; return; }

    RSZ(i, p) if (!P(s, i)) {
	II x;
	if (SZ(path) == 0) {
	    x.first = i;
	    R(j, 2) {
		x.second = j;
		VII tmp_path = path;
		tmp_path.pb(x);
		set<int> tmp_s = s;
		tmp_s.insert(i);
		dfs(p, tmp_path, tmp_s, ret, flag);
	    }
	} else {
	    II pre = path.back();
	    int test;
	    if (!pre.second) test = p[pre.first].second;
	    else test = p[pre.first].first;

	    R(j, 2) {
		if ((!j && p[i].first == test) ||
		    (j && p[i].second == test)) {
		    x.first = i;
		    x.second = j;
		    VII tmp_path = path;
		    tmp_path.pb(x);
		    set<int> tmp_s = s;
		    tmp_s.insert(i);
		    dfs(p, tmp_path, tmp_s, ret, flag);
		}
	    }
	}
    }
}

int main()
{
    int n, a, b;
    cin >> n;
    VII p(n);
    R(i, n) { cin >> p[i].first >> p[i].second; }

    VII path, ret;
    set<int> s;
    bool flag = false;
    dfs(p, path, s, ret, flag);
    
    if (!flag) cout << "No solution"<<endl;
    else {
	RSZ(i, ret) {
	    cout << ret[i].first+1 << " ";
	    if (!ret[i].second) cout << "+" << endl;
	    else cout << "-" << endl;
	}
    }
}
