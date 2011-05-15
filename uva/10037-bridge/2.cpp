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


struct state
{
    multiset<int> s1;
    multiset<int> s2;
    int time;
    VII path;
    bool direction;
};

void bridge(const VI& v)
{
    if (SZ(v) == 1) { cout << v[0] << endl << v[0] << endl; return; }

    int ret_time = INT_MAX;
    VII ret_path;
    
    state start;
    start.s1 = multiset<int>(A(v));
    start.s2 = multiset<int>();
    start.time = 0;
    start.path = VII();
    start.direction = false;

    stack<state> stk;
    stk.push(start);

    while (!stk.empty()) {
	state x = stk.top();
	stk.pop();
	// print(x.s1); print(x.s2); cout <<"/////"<<endl;
	if (x.s1.empty()) {
	    if (x.time < ret_time) { ret_time = x.time; ret_path = x.path; }
	    continue;
	}

	multiset<int>::const_iterator it;
	if (!x.direction) {
	    R(i, 2) {
		state next = x;
		next.time = -1;
		next.direction = true;
		next.path.pb(MP(0, 0));
		R(j, 2) {
		    if (!i) it = next.s1.begin();
		    else { it = next.s1.end(); --it; }
		    next.s2.insert(*it);
		    next.time = max(next.time, *it);
		    if (!j) next.path.back().X = *it;
		    else next.path.back().Y = *it;
		    next.s1.erase(it);
		}
		next.time += x.time;
		stk.push(next);
	    }
	} else {
	    state next = x;
	    next.direction = false;
	    next.path.pb(MP(0, 0));
	    it = next.s2.begin();
	    next.s1.insert(*it);
	    next.time = *it;
	    next.path.back().X = *it;
	    next.s2.erase(it);
	    next.time += x.time;
	    stk.push(next);
	}
    }

    cout << ret_time << endl;
    RSZ(i, ret_path)
	if (!ret_path[i].Y) cout << ret_path[i].X << endl;
	else cout << ret_path[i].X << " " << ret_path[i].Y << endl;
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
	bridge(v);
    }
}
