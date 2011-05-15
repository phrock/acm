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
#define pb push_back
////////////////////////////////////////////////////////////////////////////////


void f(const vector<int> &a)
{
    cout << 1;
    stack<int> st;
    for (int i = a[0]; i >= 1; --i) {
	st.push(1);
    }
    st.pop();
    if (!st.empty()) {
    	int x = st.top()+1;
    	st.pop();
    	st.push(x);
    }
    for (int i = 1; i < a.size(); ++i) {
	int k = a[i]-a[i-1];
	for (int j = k; j >= 1; --j) {
	    st.push(1);
	}
	cout << " " << st.top();
	int x = st.top();
	st.pop();
	if (!st.empty()) {
	    x += st.top();
	    st.pop();
	    st.push(x);
	}
    }
    cout << endl;
}
    

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	int m;
	cin >> m;
	vector<int> a(m);
	for (int j = 0; j < m; ++j) {
	    cin >> a[j];
	}
	f(a);
    }
}
