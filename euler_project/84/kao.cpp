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
#define FA(i, x)  for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define UN(a) sort(ALL(a)), a.erase(unique(ALL(a)), a.end())
#define CL(a, b) memset(a, b, sizeof(a))
#define pb push_back
#define pf push_front
#define MP(a, b)  make_pair(a, b)

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> inline void intToString(const T& a, string& s) { stringstream ss; ss<<a; s=ss.str(); }
template<class T> inline void stringToInt(const string& s, T& a) { istringstream iss(s); iss>>a; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }

int nextPosition2(int p, int s, int& d, queue<int>& cc, queue<int>& ch)
{
    int x = (p+s)%40;
    return x;
}
int nextPosition(int p, int s, int& d, queue<int>& cc, queue<int>& ch)
{
    if (d == 3) { d = 0; return 10; }
    int x = (p+s)%40;
    if (x == 30) return 10;

    if (x==2 || x==17 || x==33) {
	int r = cc.front();
	cc.pop();
	cc.push(r);

	switch (r) {
	case 0: return 0;
	case 1: return 10;
	}
    }

    if (x==7 || x==22 || x==36) {
	int r = ch.front();
	ch.pop();
	ch.push(r);

	switch (r) {
	case 0: return 0;
	case 1: return 10;
	case 2: return 11;
	case 3: return 24;
	case 4: return 39;
	case 5: return 5;
	case 6:
	    if (x==7) return 15;
	    if (x==22) return 25;
	    if (x==36) return 5;
	case 7:
	    if (x==7) return 15;
	    if (x==22) return 25;
	    if (x==36) return 5;
	case 8:
	    if (x==7 || x==36) return 12;
	    if (x==22) return 28;
	case 9:
	    if (x==7) return 4;
	    if (x==22) return 19;
	    if (x==36) return 33;

	}
    }

    return x;
}
queue<int> shuffleQueue()
{
    int n = 16;
    queue<int> q;
    VI v(n);
    int r = 0;
    R(i, n) {
	r = rand()%16;

	while (v[r] != 0) {
	    r = rand()%16;
	}
	q.push(r);
	v[r]++;

    }
    return q;
}

void play(VI& v, int m, int times)
{
    int n = v.size();
    int p = 0;

    int d = 0;

    queue<int> cc = shuffleQueue();
    queue<int> ch = shuffleQueue();

    srand(time(NULL));
    R(i, times) {
	int s = rand()%(2*m-1)+2;
	// if (s%2 == 0) d++;
	// else d = 0;
	// cout << s << endl;
	p = nextPosition2(p, s, d, cc, ch);
	v[p]++;
    }
    // while (! cc.empty()) {
    // 	cout << cc.front()<<endl;
    // 	cc.pop();
    // }
    // cout <<"?////////////"<<endl;
    // while (! ch.empty()) {
    // 	cout << ch.front()<<endl;
    // 	ch.pop();
    // }
    // cout <<"?////////////"<<endl;
}

bool cmpVector(const VI& a, const VI& b)
{
    return a[1] > b[1];
}

int main()
{
    int n = 40;
    int m = 6;
    int times = 10000000;
    VI v(n);

    play(v, m, times);
    print(v);

    VVI vv;
    RSZ(i, v) {
	VI tmp(2);
	tmp[0] = i;
	tmp[1] = v[i];
	vv.pb(tmp);
    }

    sort(ALL(vv), cmpVector);
    RSZ(i, vv) print(vv[i]);
}
