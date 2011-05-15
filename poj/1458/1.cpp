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


int lcs(const string& a, const string& b)
{
    vector< vector<int> > d(SZ(a), vector<int> (SZ(b)));
    int x = 0;
    for (int i = 0; i < d[0].size(); ++i) {
	if (a[0] == b[i]) x = 1;
	d[0][i] = x;
    }
    x = 0;
    for (int i = 0; i < d.size(); ++i) {
	if (b[0] == a[i]) x = 1;
	d[i][0] = x;
    }
    for (int i = 1; i < d.size(); ++i) {
	for (int j = 1; j < d[i].size(); ++j) {
	    if (a[i] == b[j]) d[i][j] = d[i-1][j-1]+1;
	    else d[i][j] = max(d[i-1][j], d[i][j-1]);
	}
    }
    return d[SZ(a)-1][SZ(b)-1];
}

int main()
{
    string a, b;
    while (cin >> a >> b) {
	int res = lcs(a, b);
	cout << res << endl;
    }
}
