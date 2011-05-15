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
#include "/home/rock/program/topcoder/libs/debug.cpp"
#endif

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/


int main()
{
    int T;
    cin >> T;
    vector<long long> v;
    long long aux = 0;
    while (true) {
        long long tmp = aux * aux;
        if (tmp > 1e12) break;
        else { v.push_back(tmp); ++aux; }
    }
    // set<long long> st((v).begin(), (v).end());
    for (int ti = 0; ti < T; ++ti) {
        long long n;
        cin >> n;
        bool ok = false;
        int k = lower_bound((v).begin(), (v).end(), n / 2) - v.begin();
        for (int i = 0; i <= k; ++i)
            if (binary_search((v).begin(), (v).end(), n - v[i])) { ok = true; break; }
        cout << (ok ? "Yes" : "No") << endl;
    }
}
