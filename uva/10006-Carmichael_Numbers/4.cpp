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

long long mod(long long a, long long n, long long b)
{
    if (n == 1) return a%b;
    long long k = mod(a, n/2, b);
    k = k*k%b;
    if (n%2 == 0) return k;
    else return k*a%b;
}

int main()
{
    long long n;
    while (cin >> n) {
	if (!n) break;
	bool f2 = true;
	for (long long i = 2; i*i <= n; ++i) {
	    if (n%i == 0) { f2 = false; break; }
	}
	if (!f2) {
	    bool f = true;
	    for (long long i = 2; i <= n-1; ++i) {
		if (mod(i, n, n) != i) { f = false; break; }
		if (!f) break;
	    }
	    if (f) { cout << "The number " << n << " is a Carmichael number." << endl; continue; }
	}
	cout << n << " is normal." << endl;
    }
}
