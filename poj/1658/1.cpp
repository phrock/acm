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


int main()
{
    int n;
    cin >> n;
    int a, b, c, d;
    for (int i = 0; i < n; ++i) {
	cin >> a >> b >> c >> d;
	cout << a<<" "<<b<<" "<<c<<" "<<d<<" ";
	if (a-b == b-c && b-c == c-d) cout << d-a+b << endl;
	else {
	    cout << d*b/a << endl;
	}
    }
}
