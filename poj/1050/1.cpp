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
int d[105][105][105][105];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	for (int j = 0; j < n; ++j) {
	    cin >> a[i][j];
	    d[i][j][1][1] = a[i][j];
	}
    }
    int m = d[0][0][1][1];
    for (int k = 1; k <= n; ++k) {
	for (int l = 1; l <= n; ++l) {
	    for (int i = 0; i < n-k+1; ++i) {
		for (int j = 0; j < n-l+1; ++j) {
		    for (int p = i; p < i+k; ++p) {
			for (int q = j; q < j+l; ++q) {
			    d[i][j][k][l] = d[i][j][p-i][q-j]+d[p][j][i+k-p][q-j]+d[i][q][p-i][j+l-q]+d[p][q][i+k-p][j+l-q];
			}
		    }
		    m = max(m, d[i][j][k][l]);
		    // cout<<d[i][j][k][l]<<" *************** "<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
		}
	    }
	}
    }
    cout <<m<<endl;
}
