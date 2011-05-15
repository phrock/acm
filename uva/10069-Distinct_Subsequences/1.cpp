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

string addString(string a, string b)
{
    string result;

    int ai = a.length() - 1;
    int bi = b.length() - 1;

    int carry = 0;
    while ((ai >= 0) || (bi >= 0)) {
	int x = 0;
	int y = 0;
	int z = 0;

	if (ai >= 0) {
	    x = a[ai] - '0';
	}
	if (bi >= 0) {
	    y = b[bi] - '0';
	}
	z = x + y + carry;

	carry = z / 10;
	int m = z % 10;

	result = (char)(m+'0') + result;

	if (ai >= 0) ai--;
	if (bi >= 0) bi--;
    }

    if (carry > 0) {
	result = (char)(carry+'0') + result;
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    string a, b;
    for (int i = 0; i < n; ++i) {
	cin >> a >> b;
	a = " "+a;
	b = " "+b;
	vector< vector<string> > d(SZ(a), vector<string> (SZ(b)));
	for (int i = 0; i < d.size(); ++i) {
	    d[i][0] = "1";
	}
	for (int j = 1; j < d.size(); ++j) {
	    for (int k = 1; k < d[0].size(); ++k) {
		if (a[j] == b[k]) d[j][k] = addString(d[j-1][k-1], d[j-1][k]);
		else d[j][k] = d[j-1][k];
	    }
	}
	cout << d[SZ(d)-1][SZ(d[0])-1] << endl;
    }
}
