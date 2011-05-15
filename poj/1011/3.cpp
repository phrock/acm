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

bool check(const vector<int> &a, int k)
{
    int i = 0;
    int j = SZ(a)-1;
    while (a[j] == k) j--;
    while (i < j) {
	int x = a[i]+a[j];
	while (x < k) { i++; if (i == j) return false; x += a[i]; }
	if (x == k) { i++; j--; }
	else return false;
    }
    return true;
}


int main()
{
    int m;
    while (cin >> m) {
	if (!m) break;
	int x;
	vector<int> a;
	int sum = 0;
	int k = 0;
	for (int j = 0; j < m; ++j) {
	    cin >> x;
	    sum += x;
	    k = max(k, x);
	    a.pb(x);
	}
	sort((a).begin(), (a).end());
	for (int j = k; j <= sum; ++j) {
	    if (sum%j == 0 && check(a, j)) { cout << j << endl; break; }
	}
    }
}
