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
    F(i, 2, sq) if (n%i == 0) { result += i + n/i; };
    result++;

    return result;
}

VI chain(int n, int m, map<int, int>& mp)
{
    // if (mp[n] != 0) {
	
    // 	VI v;
	
    // 	return v;
    // }
    VI t;
    t.pb(n);
    int next = 0;
    // cout <<"!!!! "<<n<<endl;
    while ((next=nextNumber(n)) <= m) {
	// cout << "** "<<next<<endl;
	if (find(ALL(t), next) != t.end()) break;
	t.pb(next);
	n = next;
    }

    VI v;
    if (next > m) return v;

    int small = INT_MAX;
    // print(t);
    RSZ(i, t) {
	// if (t[i] != next) continue;
	small = t[i]<small ? t[i] : small;
    }
    int len = t.end()-find(ALL(t), next);
    v.pb(len);
    v.pb(small);

    RSZ(i, t) mp[t[i]] = len;

    return v;
}

int main()
{
    int m = 1000000;


    // VI v = chain(14288, m);

    // if (v.size() == 2) cout <<v[0] <<" "<<v[1]<<endl;

    int length = 0;
    int result = INT_MAX;

    map<int, int> mp;
    FE(i, 1, 10000000) {
	if (mp[i] > 0) continue;
	VI v = chain(i, m, mp);
	if (v.size() == 0) continue;

	if (v[0] > length) { result = v[1]; length = v[0]; }
	if (v[0] == length) result = v[1]<result ? v[1] : result;
    }

    cout <<"////////////"<<endl;
    cout << length<<" : "<<result<<endl;

    cout << nextNumber(220)<<endl;
}
