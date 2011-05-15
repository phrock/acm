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


int flip(int a, int x, int y)
{
    int res = a;
    res ^= 1<<(4*x+y);
    if (x > 0) res ^= 1<<(4*(x-1)+y);
    if (x < 3) res ^= 1<<(4*(x+1)+y);
    if (y > 0) res ^= 1<<(4*x+y-1);
    if (y < 3) res ^= 1<<(4*x+y+1);
    return res;
}

int bfs(int start)
{
    int x1 = 0;
    int x2 = 65535;

    set<int> st;
    st.insert(start);
    queue<pair<int, int> > q;
    q.push(make_pair(start, 0));

    while (!q.empty()) {
	pair<int, int> x = q.front();
	q.pop();
	// cout<<x.first<<endl;
	// cout<<x.second<<endl;
	if (x.first == x1 || x.first == x2) return x.second;
	for (int i = 0; i < 4; ++i) {
	    for (int j = 0; j < 4; ++j) {
		int next = flip(x.first, i, j);
		if (!((st).find(next) != (st).end())) { q.push(make_pair(next, x.second+1)); st.insert(next); }
	    }
	}
    }
    return -1;
}

int main()
{
    int start = 0;
    for (int i = 0; i < 4; ++i) {
	string s;
	cin >> s;
	for (int j = 0; j < 4; ++j) {
	    if (s[j] == 'b') start |= 1<<(i*4+j);
	}
    }
    int res = bfs(start);
    if (res == -1) cout << "Impossible" << endl;
    else cout << res << endl;
}
