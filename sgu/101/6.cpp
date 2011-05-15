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
	if (!visited[a]) {
	    visited[a] = 1;
	    R(i, SZ(g)) if (g[a][i] > 0) q.push(i);
	    R(i, SZ(g)) if (g[i][a] > 0) q.push(i);
	}
    }
    RSZ(i, g) {
	int n = 0;
	RSZ(j, g[i]) n += g[i][j];
	RSZ(j, g[i]) n += g[j][i];
	if (n && !visited[i]) return false;
    }
    return true;
}

II euler_check(const VVI& g)
{
    int x = 0;
    II error(-1, -1);
    RSZ(i, g) RSZ(j, g[i]) if (g[i][j]) { x = i; goto out; }
 out:
    // RSZ(i, g) print(g[i]);
    // cout <<"xxx: "<<x<<endl;
    if (!connect(g, x)) return error;
    VI odd;
    RSZ(i, g) {
	int n = 0;
	RSZ(j, g[i]) n += g[i][j];
	R(j, SZ(g)) n += g[j][i];
	if (n%2 == 1) odd.pb(i);
    }
    if (SZ(odd) == 0) return MP(x, -1);
    if (SZ(odd)== 2) return MP(odd[0], odd[1]);
    return error;
}

void print_euler_path(VVI& g, II a, set<VI>& st)
{
    int n = SZ(g);
    bool flag = true;

    int x = a.X;
    int y = a.Y;
    while (flag) {
	// cout <<" &&& "<<x<< " "<<y<<endl;
	flag = false;
	if (g[x][x] > 0) {
	    VI c;
	    RA(i, st) if ((*i)[1] == x && (*i)[2] == x) c.pb((*i)[0]);
	    VI t(3); t[1] = x; t[2] = x;
	    RSZ(i, c) {
		t[0] = c[i];
		cout << c[i] << " +" << endl;
		st.erase(st.find(t));
	    }
	    g[x][x] = 0;
	    flag = true;
	    continue;
	}
	R(i, n) if (i != y && g[x][i]) {
	    int m;
	    RA(j, st) if ((*j)[1] == x && (*j)[2] == i) { m = (*j)[0]; break; }
	    cout << m << " +" << endl;
	    VI t(3); t[0] = m; t[1] = x; t[2] = i;
	    st.erase(st.find(t));
	    g[x][i]--;
	    x = i;
	    flag = true;
	    break;
	}
	if (flag) continue;
	R(i, n) if (i != y && g[i][x]) {
	    int m;
	    RA(j, st) if ((*j)[1] == i && (*j)[2] == x) { m = (*j)[0]; break; }
	    cout << m << " -" << endl;
	    VI t(3); t[0] = m; t[1] = i; t[2] = x;
	    st.erase(st.find(t));
	    g[i][x]--;
	    x = i;
	    flag = true;
	    break;
	}
	if (flag) continue;
	if (y != -1) {
	    // RA(i, st) print(*i);
	    if (g[x][y] > 0) {
		int m;
		RA(j, st) if ((*j)[1] == x && (*j)[2] == y) { m = (*j)[0]; break; }
		cout << m << " +" << endl;
		VI t(3); t[0] = m; t[1] = x; t[2] = y;
		st.erase(st.find(t));
		g[x][y]--;
		x = y;
		flag = true;
	    }
	    if (flag) continue;
	    if (g[y][x] > 0) {
		int m;
		RA(j, st) if ((*j)[1] == y && (*j)[2] == x) { m = (*j)[0]; break; }
		cout << m << " -" << endl;
		VI t(3); t[0] = m; t[1] = y; t[2] = x;
		st.erase(st.find(t));
		g[y][x]--;
		x = y;
		flag = true;
	    }
	}
    }	    
}

int main()
{
    int n;
    cin >> n;
    int m = 7;
    VVI g(m, VI(m));
    set<VI> st;
    int a, b;
    int k = 0;
    R(i, n) {
	cin >> a >> b;
	g[a][b]++;
	VI v(3);
	v[0] = ++k;
	v[1] = a;
	v[2] = b;
	st.insert(v);
    }
    II ret = euler_check(g);
     // cout << ret.X<<" "<<ret.Y<<endl;
    if (ret.X >= 0) print_euler_path(g, ret, st);
    else cout << "No solution" << endl;
}
