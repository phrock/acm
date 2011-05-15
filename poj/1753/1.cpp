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
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

////////////////////////////////////////////////////////////////////////////////

template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i = (A).begin(); i != (A).end(); ++i) { cout<<" { "; for (__typeof((*i).begin()) j = (*i).begin(); j != (*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl; } cout<<"}"<<endl; }
vector< vector<int> > flip(const vector< vector<int> > &a, int x, int y)
{
    int n = a.size();
    vector< vector<int> > res = a;
    res[x][y] ^= 1;
    if (x > 0) res[x-1][y] ^= 1;
    if (x < n-1) res[x+1][y] ^= 1;
    if (y > 0) res[x][y-1] ^= 1;
    if (y < n-1) res[x][y+1] ^= 1;
    return res;
}

int bfs(const vector< vector<int> > &a)
{
    vector< vector<int> > x1(4, vector<int> (4));
    vector< vector<int> > x2(4, vector<int> (4, 1));

    set<vector< vector<int> > > st;
    queue<pair<vector< vector<int> > , int> > q;
    q.push(make_pair(a, 0));

    while (!q.empty()) {
	pair<vector< vector<int> > , int> x = q.front();
	q.pop();
	// print2(x.first);
	// cout<<x.second<<endl;
	if (x.first == x1 || x.first == x2) return x.second;
	st.insert(x.first);
	for (int i = 0; i < a.size(); ++i) {
	    for (int j = 0; j < a[i].size(); ++j) {
		vector< vector<int> > next = flip(x.first, i, j);
		if (!((st).find(next) != (st).end())) { q.push(make_pair(next, x.second+1)); st.insert(next); }
	    }
	}
    }
    return -1;
}

int main()
{
    vector< vector<int> > a(4, vector<int> (4));
    for (int i = 0; i < 4; ++i) {
	string s;
	cin >> s;
	for (int j = 0; j < 4; ++j) {
	    if (s[j] == 'b') a[i][j] = 1;
	    else a[i][j] = 0;
	}
    }
    int res = bfs(a);
    if (res == -1) cout << "Impossible" << endl;
    else cout << res << endl;
}
