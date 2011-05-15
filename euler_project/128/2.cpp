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

const long MAX = 10000000;
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

bool check(LL x, LL r)
{
    LL k = 0;
    LL s0 = 0;
    LL s1 = 0;
    LL s2 = 0;

    LL size0 = 0;
    LL size1 = 0;
    LL size2 = 0;

    s1 = 3*r*(r-1)+2;
    size1 = 6*r;
    if (r == 1) {
	s0 = 1;
	size0 = 1;
    } else {
	s0 = 3*(r-1)*(r-2)+2;
	size0 = 6*(r-1);
    }

    s2 = 3*r*(r+1)+2;
    size2 = 6*(r+1);
    // cout <<"x: "<<x<<" r: "<<r<<"  : "<<s1<<" "<<s0<<" "<<s2<<endl;

    LL p = x - s1;
    
    LL a1 = s1 + (p+size1-1)%size1;
    LL b1 = s1 + (p+1)%size1;
    LL a2 = 0;
    LL b2 = 0;
    LL c2 = 0;
    LL d2 = 0;

    if (p%r == 0) {
	LL m = p/r;
	a2 = s0 + m*(r-1);
	b2 = s2 + m*(r+1);
	c2 = s2 + (m*(r+1)+size2-1)%size2;
	d2 = s2 + (m*(r+1)+1)%size2;
    } else {
	LL m1 = p/r;
	LL m2 = p%r;

	a2 = s0 + (m1*(r-1)+m2-1)%size0;
	b2 = s0 + (m1*(r-1)+m2)%size0;
	c2 = s2 + (m1*(r+1)+m2)%size2;
	d2 = s2 + (m1*(r+1)+m2+1)%size2;
    }

    if (prime[abs(x-a1)]) ++k;
    if (prime[abs(x-b1)]) ++k;
    if (prime[abs(x-a2)]) ++k;
    if (prime[abs(x-b2)]) ++k;
    if (prime[abs(x-c2)]) ++k;
    if (prime[abs(x-d2)]) ++k;

    if (k == 3) return true;
    else return false;
}

void createRing(LL n)
{
    LL count = 1;
    LL r = 1;

    LL x = 2;
    while (x < n) {
	LL t = 0;
	LL m = 6*r;
	while (t < m) {
	    if (check(x, r)) {
		++count;
		cout << "******* "<<x<<" "<<count<<endl;
		if (count == 2000) return;
	    }
	    x++;
	    t++;
	}

	r++;
    }

}

int main()
{
    findPrime(prime);

    LL n = 100000000000LL;
    createRing(n);
    // prLL(v);

}
