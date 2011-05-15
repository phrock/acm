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
template<class T> void print(T A[], int n) { cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<"}"<<endl; }
template<class T> void print(vector<T> A, int n=-1) { if (n==-1) n=A.size(); cout<<"{"; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", "; } cout<<"}"<<endl; }
template<class T> void print(T A) { cout<<"{"; RA(i, A) { cout<<*i<<", "; } cout<<"}"<<endl; }
template<class T> inline T gcd(T a, T b) { while (b != 0) { T r=a%b; a=b; b=r; } return a; }


VVII construct_graph(VII& p, int m)
{
    VVII ret(m);
    RSZ(i, p) {
	int a = p[i].X; int b = p[i].Y;
	II t = MP(1, a);
	ret[b].pb(t);
	t = MP(1, b);
	ret[a].pb(t);
    }

    return ret;
}

bool is_connected(VVII& g)
{
    int n = SZ(g);
    VI used(n);
    int start = 0;
    queue<int> q;
    q.push(start);
    used[start] = 1;
    
    while (!q.empty()) {
	int x = q.front();
	q.pop();
	RA(i, g[x]) if (!used[(*i).Y]) {
	    q.push((*i).Y);
	    used[(*i).Y] = 1;
	}
    }

    if (PO(used, 0)) return false;
    else return true;
}

bool euler_is_connected(VVII& g)
{
    int n = SZ(g);
    VI used(n);
    int start = 0;
    RSZ(i, g) if (SZ(g[i])) start = i; else used[i] = 1;
    queue<int> q;
    q.push(start);
    used[start] = 1;
    
    while (!q.empty()) {
	int x = q.front();
	q.pop();
	RA(i, g[x]) if (!used[(*i).Y]) {
	    q.push((*i).Y);
	    used[(*i).Y] = 1;
	}
    }
    // print(used);
    if (PO(used, 0)) return false;
    else return true;
}

bool check_graph(VVII& g, int& a, int&b)
{
    if (!euler_is_connected(g)) return false;

    int x = 0;
    a = -1;
    b = -1;
    RSZ(i, g) if (SZ(g[i])%2 == 1) {
	x++;
	if (a == -1) a = i;
	else if (b == -1) b = i;
    }
    if (!x) RSZ(i, g) if (SZ(g[i])) { a=b=i; break; }

    if (!x || x==2) return true;
    else return false;
}

VII euler_loop(VVII& g, int x)
{
    list<int> path;
    path.pb(x);

    VVII tmp = g;
    while (true) {
	bool flag = false;
	RSZ(i, tmp) if (SZ(tmp[i])) { flag = true; break; }
	if (!flag) break;

	int node, node2, tmp_node;
	RA(i, path) if (SZ(tmp[*i])) { node = *i; break; }
	list<int> tmp_path;
	tmp_path.pb(node);
	tmp_node = node;
	while (true) {
	    node2 = tmp[tmp_node][0].Y;
	    tmp[tmp_node].erase(find(A(tmp[tmp_node]), MP(1, node2)));
	    tmp[node2].erase(find(A(tmp[node2]), MP(1, tmp_node)));

	    if (node != node2) {
		tmp_path.pb(node2);
		tmp_node = node2;
	    } else {
		break;
	    }
	}

	path.insert(find(A(path), node), A(tmp_path));
    }

    VII ret;
    int node;
    RA(i, path) {
	if (i != path.begin()) ret.pb(MP(node, *i));
	node = *i;
    }
    return ret;
}

VII euler_access(VVII& g, int a, int b)
{
    VVII aux_g = g;
    aux_g[a].pb(MP(1, b));
    aux_g[b].pb(MP(1, a));

    VII loop = euler_loop(aux_g, a);
    int i = 0;
    II p = MP(a, b);
    II p2 = MP(b, a);
    RSZ(j, loop) if (loop[j] == p || loop[j] == p2) { i = j; break; }

    VII ret;
    FSZ(j, i+1, loop) ret.pb(loop[j]);
    R(j, i) ret.pb(loop[j]);
    
    return ret;
}

void output(VII& p, VII& path)
{
    set<int> used;
    RSZ(i, path) {
	II x = path[i];
	II y = x;
	// cout <<x.X<<" *** "<<x.Y<<endl;
	swap(y.X, y.Y);
	VII::const_iterator it = p.begin();
	while (it != p.end()) {
	    if (PO(p, x)) {
		while (it != p.end() && *it != x) it++;
		int t = it - p.begin();
		if (!P(used, t)) { cout << t+1 << " +" << endl; used.insert(t); break; }
		else it++;
	    } else if (PO(p, y)) {
		while (it != p.end() && *it != y) it++;
		int t = it - p.begin();
		if (!P(used, t)) { cout << t+1 << " -" << endl; used.insert(t); break; }
		else it++;
	    }
	}
    }
}

int main()
{
    int m = 7;
    int n, a, b;
    cin >> n;
    VII p(n);
    R(i, n) { cin >> p[i].first >> p[i].second; }

    VVII g = construct_graph(p, m);

    VII path;
    if (!check_graph(g, a, b)) cout << "No solution"<<endl;
    else path = euler_access(g, a, b);

    // RSZ(i, path) cout << path[i].X << " "<< path[i].Y << endl;
    output(p, path);
}
