#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
typedef pair< int, int > II;
typedef vector< II > VII;
typedef vector< VII > VVII;
typedef istringstream ISS;
typedef ostringstream OSS;

#define A(x)  (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define F(i, a, b)  for (int i=(a); i<(b); ++i)
#define R(i, n)  F(i, 0, n)
#define FE(i, a, b)  for (int i=(a); i<=(b); ++i)
#define RE(i, n)  FE(i, 0, n)
#define FD(i, a, b)  for (int i=(a); i>=(b); --i)
#define RD(i, n) FD(i, n, 0)
#define FSZ(i, a, v)  F(i, a, SZ(v))
#define RSZ(i, v)  R(i, SZ(v))
#define FDSZ(i, a, v) FD(i, SZ(v)-1, a)
#define RDSZ(i, v) RD(i, SZ(v)-1)
#define FA(i, a, x)  for (__typeof((x).begin()) i=(a); i!=(x).end(); ++i)
#define RA(i, x)  FA(i, (x).begin(), x)
#define FDA(i, a, x)  for (__typeof((x).rbegin()) i=(x).rbegin(); i!=(a); ++i)
#define RDA(i, x)  FDA(i, (x).rend(), x)
#define P(v, x) (v.find(x) != v.end())
#define PO(v, x) (find(A(v), x) != v.end())
#define UN(a) sort(A(a)), a.erase(unique(A(a)), a.end())
#define CL(a, b) memset(a, b, sizeof(a))
#define MP(a, b)  make_pair(a, b)
#define CAST(x, type) *({ OSS oss; oss << (x); ISS iss(oss.str()); static type _cast_ret; iss >> _cast_ret; &_cast_ret; })
#define pb push_back
#define pf push_front
#define X first
#define Y second

template<class T> inline void checkmin(T &a, T b) { if (b<a) a=b; }
template<class T> inline void checkmax(T &a, T b) { if (b>a) a=b; }
template<class T> inline void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> inline void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> inline void print(T A) { cout<<"{"; RA(i, A) { cout<<*i<<", "; } cout<<"}"<<endl; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


struct tree
{
    int value;
    tree* left;
    tree* right;
};

tree* create_tree(const VI& v1, const VI& v2)
{
    tree* tr = NULL;
    if (!v1.empty()) {
	tr = new tree;
	int x = v2.back();
	VI::const_iterator it = find(A(v1), x);
	VI p1(v1.begin(), it);
	VI p2(++it, v1.end());
	VI q1(v2.begin(), v2.begin()+SZ(p1));
	VI q2(v2.begin()+SZ(p1), v2.begin()+SZ(p1)+SZ(p2));
	tr->value = x;
	tr->left = create_tree(p1, q1);
	tr->right = create_tree(p2, q2);
    }
    return tr;
}

void dfs(tree* tr, int total, int& min_path, int& leaf)
{
    if (tr) {
	total += tr->value;
	if (!tr->left && !tr->right && total < min_path) {
	    min_path = total;
	    leaf = tr->value;
	}
	dfs(tr->left, total, min_path, leaf);
	dfs(tr->right, total, min_path, leaf);
    }
}

int main()
{
    string s;
    while (getline(cin, s)) {
	ISS iss(s);
	VI v1;
	int x;
	while (iss >> x) v1.pb(x);
	getline(cin, s);
	ISS iss2(s);
	VI v2;
	while (iss2 >> x) v2.pb(x);
	// print(v1); print(v2);
	tree* tr = create_tree(v1, v2);

	int min_path = INT_MAX;
	int leaf = 0;
	int total = 0;
	dfs(tr, total, min_path, leaf);
	cout << leaf << endl;
    }
}
