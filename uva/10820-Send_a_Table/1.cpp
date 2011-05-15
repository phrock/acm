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


vector<int> all_phi(int n)
{
    vector<int> phi(n+1);
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
	if (!phi[i]) { // phi[i] is prime
	    for (int j = i; j <= n; j += i) {
		if (!phi[j]) phi[j] = j;
		phi[j] = phi[j] / i * (i-1);
	    }
	}
    }
    return phi;
}

int main()
{
    int m = 50000;
    vector<int> a = all_phi(m);
    for (int i = 2; i < a.size(); ++i) {
	a[i] = a[i-1]+ a[i]*2;
    }

    int n;
    while (cin >> n) {
	if (!n) break;
	cout << a[n] <<endl;
    }
}
