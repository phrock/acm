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


void cutInHalf(VI& v, int n)
{
    if (v[n] > 0) return;
    
    cutInHalf(v, n-1);
    v[n-1]--;
    v[n] += 2;
}

void repeatJob(VI& paper, int t)
{
    paper[t]--;
    VI v(paper.size());
    v[t] = 1;
    cutInHalf(v, 5);
    RSZ(i, v) paper[i] += v[i];
}

int doJobs(const VI& v, int times)
{

    int single = 0;

    VI x;

    srand(time(NULL));

    R(time, times) {
    VI paper = v;

    int jobs = 14;

	while (jobs > 0) {
	x.clear();
	RSZ(i, paper) if (paper[i] > 0) x.pb(i);
	if (x.size() == 1) single++;
	int t = x[rand()%x.size()];

	if (t == 5) ;
	else repeatJob(paper, t);

	paper[5]--;
	jobs--;

    }
    }
    return single;
}

int main()
{
    int n = 5;
    VI v(n+1);
    v[1] = 1;

    cutInHalf(v, 5);
    v[5]--;
    // print(v);

    int times = 10000000-77;
    int total = 0;
    // while (times-- > 0) total += doJobs(v);
    
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout << (double)doJobs(v, times)/times << endl;
}
