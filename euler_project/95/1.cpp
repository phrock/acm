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


int nextNumber(int n)
{
    int result = 0;
    int sq = sqrt(n);
    if (sq*sq == n) result += sq;
    F(i, 1, sq) if (n%i == 0) { result += i + n/i; };
    result -= n;

    return result;
}

void chain()
{
}

int main()
{
    int m = 1000000;

    int result = 0;
    int length = -1;

    map<int, int> mp;

    FE(i, 2, 220) {
	cout << i<<endl;
	if (mp[i] != 0) continue;
	int next = 0;
	map<int, int> t;
	int len = 1;
	t[i] = len;
	int small = i;
	int k = i;
	while ((next=nextNumber(k)) <= m) {
	    if (mp[next] != 0) break;
	    if (t[next] > 0) break;
	    small = next<small ? next : small;
	    len++;
	    t[next] = len;
	    k = next;
	}

	if (mp[next] != 0) { RA(j, t) mp[j->first] = mp[next]; continue; }
	if (next > m) RA(j, t) mp[j->first] = -1;
	else {
	    len = len - t[next];
	    if (len > length) { length = len; result = small; }
	    else if (len == length) { result = small<result ? small : result; }
	    RA(j, t) mp[j->first] = len;
	}
    }

    cout <<"//////////////"<<endl;
    cout << result << endl;
    cout << length<<endl;
}
