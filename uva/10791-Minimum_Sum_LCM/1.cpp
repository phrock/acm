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
    long long n;
    int m = 0;
    while (cin >> n) {
	if (!n) break;
	long long orig = n;
	long long res = 0;
	long long sq = sqrt(n);
	long long k = 2;
	long long p = 0;
	while (k <= sq) {
	    long long tmp = 1;
	    while (n%k == 0) { if (tmp == 1) ++p; tmp *= k; n /= k; }
	    ++k;
	    if (tmp > 1) res += tmp; 
	}
	if (!res) res = n+1;
	else if (n != 1) res += n;
	else if (p == 1) res = orig+1;

	cout << "Case " << ++m << ": " << res << endl;
    }
}
