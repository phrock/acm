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


double distance(double x, double y, double z, double a, double b, double c)
{
    double res = sqrt((x-a)*(x-a)+(y-b)*(y-b)+(z-c)*(z-c));
    return res;
}

int main()
{
    int a, b, c;
    vector< vector<int> > vv;
    for (int i = 0; i < 16; ++i) {
	vector<int> v(3);
	cin >> v[0] >> v[1] >> v[2];
	vv.pb(v);
    }
    while (cin >> a >> b >> c) {
	if (a == -1) break;
	cout << "(" << a <<","<<b<<","<<c<<")" << " maps to (";
	double m = INT_MAX;
	int p;
	for (int i = 0; i < 16; ++i) {
	    double x = distance(vv[i][0], vv[i][1], vv[i][2], a, b, c);
	    if (x < m) { m = x; p = i; }
	}
	cout << vv[p][0]<<","<<vv[p][1]<<","<<vv[p][2]<<")"<<endl;
    }
}
