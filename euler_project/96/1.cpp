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


VI createCandidate(const VVI& vv, int x, int y)
{
    VI result;
    FE(i, 1, 9) {
	bool flag = true;
	R(j, 9) if (vv[x][j] == i || vv[j][y] == i) { flag = false; break; }
	if (flag == false) continue;

	int a1 = x/3;
	int b1 = y/3;
	a1 *= 3;
	b1 *= 3;
	int a2 = a1+3;
	int b2 = b1+3;

	F(a, a1, a2) {
	    if (flag == false) break;
	    F(b, b1, b2) {
		if (vv[a][b] == i) { flag = false; break; }
	    }
	}

	if (flag == true) result.pb(i);
    }
    return result;
}

bool check(const VVI& vv, int& x, int& y)
{
    bool ok = true;
    RSZ(i, vv) {
	if (ok == false) break;
	RSZ(j, vv[i]) if (vv[i][j] == 0) { ok = false; x=i; y=j; break; }
    }
    if (ok == true) return true;
    else return false;
}
    

bool play(const VVI& vv, VVI& result)
{
    result = vv;


    // RSZ(x, vv) print(vv[x]);
    // cout <<"///////"<<endl;

    int x = -1;
    int y = -1;

    check(result, x, y);
    if (x == -1 && y == -1) return true;
    
    VI candidate = createCandidate(vv, x, y);
    // cout <<"x: "<<x<<" y: "<<y<<"  ** :";
    // print(candidate);
    if (candidate.size() == 0) return false;
    RSZ(i, candidate) {
	result[x][y] = candidate[i];
	VVI next;
	if (play(result, next) == true) { result = next; return true; }
    }
    
    return false;
}
	
    

int main()
{
    int sum = 0;
    string s;
    int tmp;
    int n = 50;
    R(i, n) {
	cin >> s >> tmp;
	VVI vv(9, VI(9));
	R(x, 9) {
	    string a;
	    cin >> a;
	    R(y, 9) vv[x][y] = a[y] - '0';
	}
	// cout <<"///////"<<endl;
	// RSZ(x, vv) print(vv[x]);
	VVI result;
	play(vv, result);

	cout <<"*********"<<endl;
	RSZ(x, vv) print(vv[x]);
	cout <<"///////"<<endl;
	RSZ(x, result) print(result[x]);
	cout <<"*********"<<endl;
	int tmpsum = 0;
	tmpsum = result[0][0]*100 + result[0][1]*10 + result[0][2];
	sum += tmpsum;
    }

    cout << sum << endl;
}
