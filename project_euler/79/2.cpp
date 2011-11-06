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
#define FOR(i, a, b)  for (int i=(a); i<(b); ++i)
#define REP(i, n)  FOR(i, 0, n)
#define FORE(i, a, b)  for (int i=(a); i<=(b); ++i)
#define REPE(i, n)  FORE(i, 0, n)
#define FORD(i, a, b)  for (int i=(a); i>=(b); --i)
#define FORSZ(i, a, v)  FOR(i, a, SIZE(v))
#define REPSZ(i, v)  REP(i, SIZE(v))
#define FOREACH(i, x)  for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define PB push_back
#define PF push_front
#define MP(a, b)  make_pair(a, b)

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> inline void intToString(const T& a, string& s) { stringstream ss; ss<<a; s=ss.str(); }
template<class T> inline void stringToInt(const string& s, T& a) { istringstream iss(s); iss>>a; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }

bool check(int x, string s)
{
    string t;
    intToString(x, t);

    int j = 0;
    REPSZ(i, s) {
	while (t[j] != s[i]) j++;
	if (j>=t.size()) return false;
	j++;
    }

    return true;
}
    

int vectorToInt(const VI& v)
{
    int n = v.size();
    int result = 0;
    REPSZ(i, v) result = result*10 + v[i];

    return result;
}

void intToVector(int n, VI& v)
{
    int i = 0;
    int len = v.size();
    while (n != 0) {
	v[len-1-i] = n%10;
	n /= 10;
	i++;
    }

}

bool testVectorAndVector(const VI& a, const VI& b)
{
    int j = 0;
    REPSZ(i, b) {
	while (j<a.size() && a[j] != b[i]) j++;
	if (j>=a.size()) return false;
	j++;
    }
    return true;
}
	
bool testMap(const map< VI, int >& m, const VI& v)
{
    FOREACH(i, m) if (testVectorAndVector(i->first, v) == true) return true;
    return false;
}

bool match(int len, const VVI& vvi)
{
    map< VI, int > m;
    VI v = vvi[0];
    cout << len<<endl;
    int M = 1;
    int t = len;
    while (t > 0) { M *= 10; t--; }

    FOR(i, 0, len-2) FOR(j, i+1, len-1) FOR(k, j+1, len) {
	VI container(len);
	container[i] = v[0];
	container[j] = v[1];
	container[k] = v[2];
    cout <<"//////////"<<endl;
	int start = vectorToInt(container);
	while (start < M) {
	    cout << "sssssss: "<< start<<endl;
	    intToVector(start, container);
	    print(container);
	    if (container[i] == v[0] && container[j] == v[1] && container[k] == v[2]) {
		print(container);
		m[container]++;
	    }
	    start++;
	}
    }
    cout <<"//////////"<<endl;
    FOR(i, 1, SIZE(vvi)) if (testMap(m, vvi[i]) == false) return false;

    return true;
	
}

int main()
{
    VVI vvi;
    int a = 0;
    while (cin >> a) {
	VI v(3);
	v[0] = a%100;
	v[1] = (a%100)/10;
	v[2] = a%10;
	vvi.PB(v);
    }

    int len = 3;

    // while (match(x, vs) != true) { cout << x << endl; x++; }
    while (match(len, vvi) != true) {  len++; }
 
    cout << len << endl;
}
