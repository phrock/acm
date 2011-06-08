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

#ifdef DEBUG
#include "/home/rock/program/acm/topcoder/libs/debug.cpp"
#endif

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

vector<int> all_phi(int n)
{
    vector<int> phi(n+1);
    phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
	if (!phi[i]) {          // phi[i] is prime
	    for (int j = i; j <= n; j += i) {
		if (!phi[j]) phi[j] = j;
		phi[j] = phi[j] / i * (i - 1);
	    }
	}
    }
    return phi;
}

int main()
{
    vector<int> v = all_phi(1000005);
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int x;
        cin >> x;
        cout << v[x] << endl;
    }
}
