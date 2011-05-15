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

// 返回结果中vv[x][y]是x行y列可以容纳的矩形数目，
// 使用动态规划， 现括展行，求出a行1列，然后扩展列。
VVI rectangles(int a, int b)
{
    VVI vv(a+1, VI(b+1));
    vv[1][1] = 1;

    FE(i, 2, a) vv[i][1] = vv[i-1][1] + i;

    FSZ(i, 1, vv) FSZ(j, 2, vv[i]) {
	int c = (i*(i+1)/2)*j;

	vv[i][j] = vv[i][j-1] + c;
    }
    return vv;
}

int main()
{
    int a = 500;
    int b = 500;
    VVI vv = rectangles(a, b);

    // cout << vv[2][3] << endl;
    RSZ(i, vv) print(vv[i]);

    int target = 2000000;
    int x = 0;
    int y = 0;
    int diff = INT_MAX;
    
    RSZ(i, vv) RSZ(j, vv[i]) {
	int tmp = abs(target-vv[i][j]);
	if (tmp < diff) {
	    diff = tmp;
	    x = i;
	    y = j;
	}
    }

    cout << x*y<<endl;
}
