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


void bridge(const VI& v, const priority_queue<int,vector<int>,greater<int> >& q,
	    const VII& process,
	    int cost, int& ret, VII& ret_process, bool direction)
{
    // cout << direction << " *** "<<cost <<" "<<ret<<endl;
    // print(v);
    if (cost >= ret) return;
    int flag = true;
    RSZ(i, v) if (v[i] != -1) { flag = false; break; }
    if (flag && cost < ret) { ret = cost; ret_process = process; }
    if (flag) return;

    int n = SZ(v);
    if (!direction) {
	R(i, n-1) if (v[i] != -1) {
	    F(j, i+1, n) if (v[j] != -1) {
		// cout <<v[i]<<" /// "<<v[j]<<endl;
		VI v2 = v;
		priority_queue<int,vector<int>,greater<int> > q2 = q;
		VII process2 = process;
		q2.push(v[i]);
		q2.push(v[j]);
		process2.pb(MP(v[i], v[j]));
		int m = max(v[i], v[j]);
		v2[i] = -1;
		v2[j] = -1;
		bridge(v2, q2, process2, cost+m, ret, ret_process, !direction);
	    }
	}
    } else {
	VI v2 = v;
	priority_queue<int,vector<int>,greater<int> > q2 = q;
	VII process2 = process;
	int x = q2.top();
	q2.pop();
	RSZ(i, v) if (v2[i] == -1) { v2[i] = x; break; }
	process2.pb(MP(x, 0));
	bridge(v2, q2, process2, cost+x, ret, ret_process, !direction);
    }
}

int main()
{
    int cases;
    cin >> cases;
    R(i, cases) {
	if (i) cout << endl;
	int n;
	cin >> n;
	VI v(n);
	R(j, n) cin >> v[j];
	int ret = INT_MAX;
	priority_queue<int, vector<int>, greater<int> > q;
	VII process;
	VII ret_process;
	bool direction;
	bridge(v, q, process, 0, ret, ret_process, 0);
	cout << ret << endl;
	RSZ(j, ret_process)
	    if (ret_process[j].Y == 0) cout << ret_process[j].X << endl;
	    else cout << ret_process[j].X << " " << ret_process[j].Y << endl;
    }
}
