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

const long MAX = 1000000;
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

int f(LL n)
{
    LL sq = sqrt(n);
    int result = 1;

    FE(i, 2, n) {
	if (prime[i] == 0) continue;
	if (n%i == 0) {
	    int x = 0;
	    while (n%i == 0) {
		x++;
		n /= i;
	    }
	    result *= 2*x+1;
	}
    }

    result = (result+1)/2;
    return result;
}

LL guess(LL n, map<LL, LL>& m)
{
    map<LL, LL> t;
    FE(i, 2, n) {
	if (prime[i] == 0) continue;
	if (n%i == 0) {
	    while (n%i == 0) {
		t[i]++;
		n /= i;
	    }
	}
    }
    RA(i, t) while (i->second > m[i->first]*2) m[i->first]++;
    // cout <<"********* "<<n<<endl;
    // RA(i, m) cout<<i->first<<" "<<i->second<<endl;
    LL result = 1;
    RA(i, m) { result *= pow(i->first, i->second); }
    return result;
}


LL base(LL n)
{
    LL r = 1;
    LL k = 1;
    map<LL, LL> m;
    while (r <= n) { k++; r = guess(k, m); }
    cout << k<<endl;
    return r;
}

int main()
{
    findPrime(prime);
    // cout << f(6)<<endl;
    int n = 1000;
    LL b = 2*3*5*7;
    cout << b<<endl;
    LL r = b;

    while (true) {
	cout <<r<<endl;

	LL sq = r*r;
	LL count = 2;
	F(i, 2, n) if (sq%i == 0) count++;
	if (count > 1000) { cout << n<<endl; break; }
	cout <<r<< " "<<count<<endl;
  	r += b;
    }
}
