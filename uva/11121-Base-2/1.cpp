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
    int base = -2;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
	int a;
	cin >> a;
	if (!a) { cout << "Case #" << i+1 << ": " << 0 << endl; continue; }
	string res;
	while (a) {
	    int r = a%base;
	    a /= base;
	    cout << r <<" "<<a<<endl;
	    if (r < 0) { r = 1; ++a; }
	    cout << r <<" "<<a<<endl;
	    char c = '0'+r;
	    res = c+res;
	}
	cout << "Case #" << i+1 << ": " << res << endl;
    }
}
