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

#define eps 1e-11
#define sz(x) (int)(x).size()
#define mp(a, b) make_pair(a, b)
#define X first
#define Y second
#define pb push_back
////////////////////////////////////////////////////////////////////////////////


int a[105][105];

int main()
{
    int n;
    cin >> n;
    int x;
    for (int i = 1; i <= n; ++i) {
	for (int j = 1; j <= n; ++j) {
	    cin >> x;
	    a[i][j] = a[i][j-1]+x;
	}
    }
    int res = a[1][1];
    for (int i = 1; i <= n; ++i) {
	for (int j = i; j <= n; ++j) {
	    int sum = 0;
	    for (int p = 1; p <= n; ++p) {
		sum += a[p][j]-a[p][i-1];
		res = max(res, sum);
		sum = max(sum, 0);
	    }
	}
    }
    cout << res << endl;
}
