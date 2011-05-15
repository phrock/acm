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

#define EPS 1e-11
#define SZ(x) (int)(x).size()
#define MP(a, b) make_pair(a, b)
#define X first
#define Y second


struct node {
    int x;
    int y;
    vector<string> path;
};

void jugs(int a, int b, int n)
{
    set<pair<int, int> > st;
    queue<node> q;
    node t;
    t.x = 0; t.y = 0;
    q.push(t);
    st.insert(MP(0, 0));

    while (!q.empty()) {
	node p = q.front();
	q.pop();
	if (p.x == n || p.y == n) {
	    for (int i = 0; i < p.path.size(); ++i) {
		cout << p.path[i] << endl;		
	    }
	    cout << "success" << endl;
	    return;
	}
	// cout <<p.x<<" "<<p.y<<endl;
	if (p.x < a && !((st).find(MP(a, p.y)) != (st).end()))
	    { node next = p; next.x = a; next.path.push_back("fill A"); q.push(next); st.insert(MP(next.x, next.y)); }
	if (p.y < b && !((st).find(MP(p.x, b)) != (st).end()))
	    { node next = p; next.y = b; next.path.push_back("fill B"); q.push(next); st.insert(MP(next.x, next.y)); }
	if (p.x > 0) {
	    if (!((st).find(MP(0, p.y)) != (st).end()))
		{ node next = p; next.x = 0; next.path.push_back("empty A"); q.push(next); st.insert(MP(next.x, next.y)); }
	    int k = b-p.y;
	    if (p.x >= k && !((st).find(MP(p.x-k, b)) != (st).end()))
		{ node next = p; next.x = p.x-k; next.y = b; next.path.push_back("pour A B"); q.push(next); st.insert(MP(next.x, next.y)); }
	    if (p.x <= k && !((st).find(MP(0, p.y+p.x)) != (st).end()))
		{ node next = p; next.x = 0; next.y = p.y+p.x; next.path.push_back("pour A B"); q.push(next); st.insert(MP(next.x, next.y)); }
	}
	if (p.y > 0) {
	    if (!((st).find(MP(p.x, 0)) != (st).end()))
		{ node next = p; next.y = 0; next.path.push_back("empty B"); q.push(next); st.insert(MP(next.x, next.y)); }
	    int k = a-p.x;
	    if (p.y >= k && !((st).find(MP(a, p.y-k)) != (st).end()))
		{ node next = p; next.x = a; next.y = p.y-k; next.path.push_back("pour B A"); q.push(next); st.insert(MP(next.x, next.y)); }
	    if (p.y <= k && !((st).find(MP(p.x+p.y, 0)) != (st).end()))
		{ node next = p; next.x = p.x+p.y; next.y = 0; next.path.push_back("pour B A"); q.push(next); st.insert(MP(next.x, next.y)); }
	}
    }
}

int main()
{
    int a, b, n;
    while (cin >> a >> b >> n) {
	jugs(a, b, n);
    }
}
