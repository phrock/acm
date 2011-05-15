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


void cross(double ax, double ay, double bx, double by, VI& v)
{
    if (ax == bx) {
	if (ax>0 && ay*by<=0) v[1]++;
	if (ax<0 && ay*by<=0) v[3]++;
	return;
    }
    if (ay == by) {
	if (ay>0 && ax*ay<=0) v[2]++;
	if (ay<0 && ax*ay<=0) v[4]++;
	return;
    }

    double y = (by-ay)*(0-ax)/(bx-ax) + ay;
    if (ax*bx <= 0) {
	if (y > 0) v[2]++;
	if (y < 0) v[4]++;
    }
    double x = (bx-ax)*(0-ay)/(by-ay) + ax;
    if (ay*by <= 0) {
	if (x > 0) v[1]++;
	if (x < 0) v[3]++;
    }
}

bool check(double ax, double ay, double bx, double by, double cx, double cy)
{
    VI v(5);
    cross(ax, ay, bx, by, v);
    cross(ax, ay, cx, cy, v);
    cross(cx, cy, bx, by, v);
    print(v);
    FSZ(i, 1, v) if (v[i] == 0) return false;
    return true;
}

int main()
{
    ifstream in("triangles.txt");

    double ax, ay, bx, by, cx, cy;
    char c;

    int count = 0;
    while (in >>ax>>c>>ay>>c>>bx>>c>>by>>c>>cx>>c>>cy) {
	cout <<ax<<" "<<ay<<" "<<bx<<" "<<by<<" "<<cx<<" "<<cy<<endl;
	if (check(ax, ay, bx, by, cx, cy) == true) count++;
    }
    
    cout<<count<<endl;
}
