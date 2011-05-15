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

int M = 64*50+1;

void dfs(const vector<int> &a, int k, int sum, bool &flag)
{
    if (flag) return;
    bool tmp = true;;
    for (int i = 1; i < k; ++i) {
	if (a[i]) { tmp = false; break; }
    }
    if (tmp) { flag = true; return; }
    for (int i = 1; i < k; ++i) {
	if (!a[i]) continue;
	int t = i;
	if (a[i] == 1) t++;
	for (int j = t; j < k; ++j) {
	    if (!a[j]) continue;
	    if (i+j <= k) {
		vector<int> next = a;
		next[i]--; next[j]--;
		next[i+j]++;
		dfs(next, k, sum, flag);
	    }
	}
    }
}

bool check(const vector<int> &a, int k, int sum)
{
    bool flag = false;
    dfs(a, k, sum, flag);
    return flag;
}


int main()
{
    int m;
    while (cin >> m) {
	if (!m) break;
	int x;
	vector<int> a(M);
	int sum = 0;
	int k = 0;
	for (int j = 0; j < m; ++j) {
	    cin >> x;
	    sum += x;
	    k = max(k, x);
	    a[x]++;
	}
	vector<int> b(a.begin(), a.begin()+sum+1);
	for (int j = k; j <= sum; ++j) {
	    if (sum%j == 0 && check(b, j, sum)) { cout << j << endl; break; }
	}
    }
}
