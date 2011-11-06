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

VVI createRing(int n)
{
    VVI vv;
    VI v;
    v.pb(1);
    vv.pb(v);
    int r = 1;

    int x = 2;
    while (x < n) {
	int t = 0;
	int m = 6*r;
	VI v;
	while (t < m) {
	    v.pb(x);
	    x++;
	    t++;
	}

	vv.pb(v);
	r++;
    }
    return vv;
}

int main()
{
    findPrime(prime);

    int n = 1000;
    VVI vv = createRing(n);
    // RSZ(i, vv) print(vv[i]);
    // cout << vv.size()<<endl;

    VI result;
    result.pb(0);
    result.pb(1);

    int r = vv.size()-1;
    F(i, 1, r) {
	// print(vv[i]);

	RSZ(j, vv[i]) {
	    int k = 0;
	    // cout << vv[i][j]<<" : "<<vv[i][(j+vv[i].size()-1)%vv[i].size()]<<" "<<vv[i][(j+1)%vv[i].size()]<<" ";

	    int x = 0;
	    x = abs(vv[i][j] - vv[i][(j+vv[i].size()-1)%vv[i].size()]);
	    if (prime[x]) k++;
		    
	    x = abs(vv[i][j] - vv[i][(j+1)%vv[i].size()]);
	    if (prime[x]) k++;

	    if (j%i == 0) {
		int p = j/i;

		// cout <<vv[i-1][(i-1)*p]<<" "<<vv[i+1][(i+1)*p]<<" "<<vv[i+1][((i+1)*p+vv[i+1].size()-1)%vv[i+1].size()]<<" "<<vv[i+1][((i+1)*p+1)%vv[i+1].size()]<< " &&&&"<<endl;

		x = abs(vv[i][j] - vv[i-1][(i-1)*p]);
		if (prime[x]) k++;

		x = abs(vv[i][j] - vv[i+1][(i+1)*p]);
		if (prime[x]) k++;

		x = abs(vv[i][j] - vv[i+1][((i+1)*p+vv[i+1].size()-1)%vv[i+1].size()]);
		if (prime[x]) k++;

		x = abs(vv[i][j] - vv[i+1][((i+1)*p+1)%vv[i+1].size()]);
		if (prime[x]) k++;

	    } else {
		int p = j/i;
		int q = j%i;
		
		 // cout <<vv[i-1][((i-1)*p+(q-1))%vv[i-1].size()]<<" "<<vv[i-1][((i-1)*p+q)%vv[i-1].size()]<<" "<<vv[i+1][((i+1)*p+q)%vv[i+1].size()]<<" "<<vv[i+1][((i+1)*p+(q+1))%vv[i+1].size()]<<endl;

		x = abs(vv[i][j] - vv[i-1][((i-1)*p+(q-1))%vv[i-1].size()]);
		if (prime[x]) k++;

		x = abs(vv[i][j] - vv[i-1][((i-1)*p+q)%vv[i-1].size()]);
		if (prime[x]) k++;

		x = abs(vv[i][j] - vv[i+1][((i+1)*p+q)%vv[i+1].size()]);
		if (prime[x]) k++;

		x = abs(vv[i][j] - vv[i+1][((i+1)*p+(q+1))%vv[i+1].size()]);
		if (prime[x]) k++;
	    }
	    if (k == 3) { result.pb(vv[i][j]); cout << "****** " <<vv[i][j]<<endl; if (result.size()>2000) break;}
	}
    }

    cout << result.size()<<endl;
    cout << result[2000]<<endl;
}
