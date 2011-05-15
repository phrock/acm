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


int main()
{
    int n;
    while (cin >> n) {
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
	    cin >> a[i];
	}
	vector<int> d1(n), d2(n);
	for (int i = 0; i < n; ++i) {
	    for (int j = 0; j < i; ++j) {
		if (a[i] > a[j]) d1[i] = max(d1[i], d1[j]);
	    }
	    d1[i]++;
	}
	for (int i = n-1; i >= 0; --i) {
	    for (int j = n-1; j > i; --j) {
		if (a[i] > a[j]) d2[i] = max(d2[i], d2[j]);
	    }
	    d2[i]++;
	}
	int m = 0;
	for (int i = 0; i < n; ++i) {
	    m = max(m, min(d1[i],d2[i])*2-1);
	}
	cout << m << endl;
    }
}
