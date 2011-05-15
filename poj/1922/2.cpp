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


int main()
{
    int n;
    while (cin >> n) {
	if (!n) break;
	double res = INT_MAX;
	for (int i = 0; i < n; ++i) {
	    int x, y;
	    cin >> x >> y;
	    if (y >= 0) {
		double r = 4.5/(double)x*(double)3600+(double)y;
		res = min(res, r);
	    }
	}
	cout << ceil(res) << endl;
    }
}
