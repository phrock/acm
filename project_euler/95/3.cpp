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


const long MAX = 1000001;
bitset<MAX> prime(0);

// if bit is 1, then this bit is prime.
void findPrime(bitset<MAX>& prime)
{
    prime.reset();
    prime.flip();
    prime[0] = 0;
    prime[1] = 0;

    for (int i=2; i<=sqrt(MAX-1); i++) {
     	if (prime[i] == 1) {
     	    for (int j=i*i; j<MAX; j+=i) {
     		prime[j] = 0;
     	    }
     	}
    }
}

int nextNumber(int n)
{
    int result = 0;
    int sq = sqrt(n);
    if (sq*sq == n) result += sq;
    F(i, 2, sq) if (n%i == 0) { result += i + n/i; };
    result++;

    return result;
}

void chain(int n, VI& length)
{
    int m = length.size();
    VI t;
    t.pb(n);
    int next = nextNumber(n);
    while (next < m) {
	if (length[next] != 0) {
	    RSZ(i, t) length[t[i]] = -1;
	    return;
	}
	if (find(ALL(t), next) != t.end()) break;
	t.pb(next);
	next = nextNumber(next);
    }

    if (next >= m) { RSZ(i, t) length[t[i]] = -1; return; }

    // int small = INT_MAX;
    // RSZ(i, t) checkmin(small, t[i]);

    int dec = 0;
    RSZ(i, t) { if (t[i] != next) {dec++;continue;} length[t[i]] = t.size()-dec;}}

int main()
{
    findPrime(prime);
    int n = 1000001;
    VI length(n, 0);
    length[0] = 1;
    length[1] = 1;
    R(i, n) if (prime[i]) length[1] = 2;

    RSZ (i, length) {
	if (length[i] != 0) continue;
	
	chain(i, length);
	//	cout << i<<" "<<length[i]<<endl;
    }
    // print(length);
    int len = 0;
    int result = 0;
    RSZ(i, length) if (length[i] > len) { len = length[i]; result = i; }

    cout << len << " "<<result;
}
