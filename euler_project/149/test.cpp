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

#define A(x)  (x).begin(), (x).end()
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
#define UN(a) sort(A(a)), a.erase(unique(A(a)), a.end())
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


LL maxline(const VLL& v)
{
    int n = v.size();
    LL result = 0;

    int i = 0;
    while (i < n) {
	LL x = 0;
	while (i<n && x>=0) { x += v[i]; checkmax(result, x); i++; }
    }
    return result;
}

int main()
{
    // int n = 4000000;
    
    // VLL v(n+1);
    // FE(i, 1, 55) {
    // 	v[i] = (i*i*i*300007LL - i*200003LL + 100003LL)%1000000LL - 500000LL;
    // }
    // FE(i, 56, n) {
    // 	v[i] = (v[i-24] + v[i-55] + 1000000)%1000000 - 500000;
    // }

    // // cout << v[10] << " "<< v[100] <<" "<<v[n]<< endl;

    // n = 2000;
    // VVLL vv(n, VLL(n));

    // RSZ(i, vv) RSZ(j, vv[i]) {
    // 	vv[i][j] = v[n*i+j+1];
    // }
    // // cout <<vv[0][9]<<" "<<vv[0][99]<<" "<<vv[n-1][n-1]<<endl;

    int n = 4;

    VVLL vv(n, VLL(n));
    VLL v;

    vv[0][0] = -2;
    vv[0][1] = 5;
    vv[0][2] = 3;
    vv[0][3] = 2;
    vv[1][0] = 9;
    vv[1][1] = -6;
    vv[1][2] = 5;
    vv[1][3] = 1;
    vv[2][0] = 3;
    vv[2][1] = 2;
    vv[2][2] = 7;
    vv[2][3] = 3;
    vv[3][0] = -1;
    vv[3][1] = 8;
    vv[3][2] = -4;
    vv[3][3] = 8;

    cout << maxline(vv[0])<<endl;

    RSZ(i, vv) print(vv[i]);

    LL result = 0;
    RSZ(i, vv) { cout << maxline(vv[i])<<endl;checkmax(result, maxline(vv[i]));}
    cout <<result<<endl;
    cout <<"///////////////"<<endl;
    R(j, n) {
	v.clear();
	R(i, n) v.pb(vv[i][j]);
	cout << maxline(v)<<endl;
	checkmax(result, maxline(v));
    }
    cout <<result<<endl;
    cout <<"///////////////"<<endl;
    R(i, n) {
	v.clear();
	RE(j, i) v.pb(vv[i-j][j]);
	cout << maxline(v)<<endl;
	checkmax(result, maxline(v));
    }
    cout <<result<<endl;
    cout <<"///////////////"<<endl;
    F(j, 1, n) {
	v.clear();
	FD(i, n-1, j) cout <<i<<" "<<j+n-i-1<<endl;
	FD(i, n-1, j) v.pb(vv[i][j+n-i-1]);
	cout << maxline(v)<<endl;
	checkmax(result, maxline(v));
    }
    cout <<result<<endl;
    cout <<"\\\\\\\\\\\\\\"<<endl;
    R(i, n) {
	v.clear();
	RE(j, i) cout << n-i-1+j<<" "<<j<<endl;
	RE(j, i) v.pb(vv[n-i-1+j][j]);
	cout <<"****"<<endl;
	cout << maxline(v)<<endl;
    }
    cout <<result<<endl;

    cout <<"\\\\\\\\\\\\\\"<<endl;
    F(i, 1, n) {
	v.clear();
	R(j, i) cout <<j<<" "<<j+n-i<<endl;
	R(j, i) v.pb(vv[j][j+n-i]);
	cout<<"***"<<endl;
	cout << maxline(v)<<endl;
    }
    cout <<result<<endl;
}
