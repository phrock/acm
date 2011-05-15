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
int b[105][105][105];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	for (int j = 0; j < n; ++j) {
	    cin >> a[i][j];
	    b[i][j][1] = a[i][j];
	}
	for (int j = 2; j <= n; ++j) {
	    for (int k = 0; k < n-j+1; ++k) {
		b[i][k][j] = b[i][k][j-1]+a[i][k+j-1];
	    }
	}
    }
    int m = INT_MIN;
    for (int j = 0; j < n; ++j) {
	for (int k = 1; k <= n; ++k) {
	    for (int i = 0; i < n; ++i) {
		int t = 0;
		for (int p = i; p < n; ++p) {
		    t += b[p][j][k];
		    m = max(m, t);
		}
	    }
	}
    }
    cout<<m<<endl;
}
