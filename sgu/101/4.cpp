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
#define P(v, x) ((v).find(x) != (v).end())
#define PO(v, x) (find(A(v), x) != (v).end())
#define UN(a) sort(A(a)), (a).erase(unique(A(a)), (a).end())
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


bool connect(const VVI& g, int x)
{
    VI visited(SZ(g));
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
	int a = q.front();
	q.pop();
	if (!visited[a]) { visited[a] = 1; RSZ(i, g[a]) q.push(g[a][i]); }
    }
    RSZ(i, g) if (SZ(g[i]) && !visited[i]) return false;
    return true;
}

II euler_check(const VVI& g)
{
    VI v;
    int odd = 0;
    RSZ(i, g) { int n = SZ(g[i]); RSZ(j, g[i]) if (g[i][j] == i) n++; if (n%2 == 1) { odd++; v.pb(i); } }
    if (!odd) RSZ(i, g) if (SZ(g[i])) { v.pb(i); v.pb(-1); break; }
    if ((odd == 0 || odd == 2) && connect(g, v[0])) return MP(v[0], v[1]);
    else return MP(-1, -1);
}

void print_euler_path(const VVI& g, const VII& node, II odd)
{
    int s = odd.X;
    int t = odd.Y;
    RSZ(i, g) print(g[i]);
    cout << s << " "<<t<<" >>>>>>>>>>>>"<<endl;
    RSZ(i, node) cout << node[i].X<<" "<<node[i].Y<<endl;
    int n = SZ(node);
    VI visited(n);
    int x = s;
    R(k, n) {
	cout <<"kkkkkkkkk: "<<k+1<<endl;
	RSZ(i, g[x]) {
	    cout << "// "<<x <<" "<<g[x][i]<<endl;
	    if (g[x][i] == t) {
		bool f = false;
		RSZ(j, g[x]) if (g[x][j] != t) { f = true; break; }
		if (f) continue;
	    }
	    cout <<"&&&"<<endl;
	    II a = MP(x, g[x][i]);
	    II b = MP(g[x][i], x);
	    VII::const_iterator i1 = find(A(node), a);
	    VII::const_iterator i2 = find(A(node), b);
	    int p1 = i1-node.begin();
	    int p2 = i2-node.begin();
	    if (i1 != node.end() && !visited[p1]) {
		cout << p1+1 << " +" << endl;
		visited[p1] = 1;
		x = g[x][i];
		break;
	    }
	    if (i2 != node.end() && !visited[p2]) {
		cout << p2+1 << " -" << endl;
		visited[p2] = 1;
		x = g[x][i];
		break;
	    }
	}
    }
}

int main()
{
    int n;
    cin >> n;
    int m = 7;
    VVI g(m);
    int a, b;
    int k = 0;
    VII node;
    R(i, n) {
	cin >> a >> b;
	g[a].pb(b);
	if (a != b) g[b].pb(a);
	node.pb(MP(a, b));
    }
    II ret = euler_check(g);
    if (ret.X >= 0) print_euler_path(g, node, ret);
    else cout << "No solution" << endl;
}
