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

bool isPrime(int n)
{
    if (n < 2) return false;
    int sq = sqrt(n);
    FE(i, 2, sq) if (n%i == 0) return false;
    return true;
}

int rad(int n)
{
    // if (prime[n]) return n;
    if (isPrime(n)) return n;
    int r = 1;
    FE(i, 2, n) {
	if (isPrime(i) && (n%i==0)) {
	    r *= i;
	    while (n%i == 0) n /= i;
	}
    }
    return r;
}

VVI factorization(int n)
{
    VVI vv(n);
    FSZ(i, 1, vv) {
	VI v;
	int x = i;
	FE(j, 2, x) {
	    if (prime[j] && (x%j==0)) {
		v.pb(j);
		while (x%j == 0) x /= j;
	    }
	}
	vv[i] = v;
    }
    return vv;
}
	
bool check(const VI& a, const VI& b)
{
    int x = 0;
    int y = 0;

    while ((x!=a.size()) && (y!=b.size())) {
	if (a[x] == b[y]) return false;
	if (a[x] < b[y]) x++;
	else y++;
    }
    
    return true;
}

int main()
{
    findPrime(prime);

    int m = 1000;

    VVI vv = factorization(m);
    // RSZ(i, vv) {cout<<i<<" : "; print(vv[i]);}
    cout <<"haha"<<endl;
    int r = 0;

    F(c, 2, m) {
	//	cout <<c <<endl;
	if (prime[c]) continue;
	int x = c;
	RSZ(i, vv[c]) x /= vv[c][i];

	F(a, 1, c/2) {
	    int b = c - a;
	    if (check(vv[a], vv[b])) {
		LL y = 1;
		RSZ(i, vv[a]) y *= vv[a][i];
		RSZ(i, vv[b]) y *= vv[b][i];
		if (y < x) { r+=c; cout << "/////////// "<<a<<" "<<b<<" "<<c<<" x: "<<x<<endl;  }
	    }

	}
    }
    cout <<r<<endl;
}
