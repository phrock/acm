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


int fun(const string& s)
{
    int n = SZ(s);
    for (int i = 1; i <= n/2; ++i) {
	if (n%i == 0) {
	    int k = 0;
	    bool flag = true;
	    string t = s.substr(0, i);
	    while (k != n) {
		if (t == s.substr(k, i)) k += i;
		else { flag = false; break; }
	    }
	    if (flag) return n/i;
	}
    }
    return 1;
}

int main()
{
    string s;
    char c[1000005];
    while (scanf("%s", c)) {
	s = c;
	if (s == "") { cout << 0 << endl; continue; }
	if (s[0] == '.') break;
	int res = fun(s);
	cout << res << endl;
    }
}
