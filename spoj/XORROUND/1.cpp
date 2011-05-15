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

int a[2][505];

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n, k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) cin >> a[0][i];
        vector<vector<int> > vv;
        vv.push_back(vector<int>(a[0], a[0] + n));
        int circle = 0, start = INT_MAX;
        for (int i = 0; i < k; ++i) {
            int p = i % 2, q = 1 - p;
            for (int j = 0; j < n; ++j) {
                int j1 = (j + n - 1) % n, j2 = (j + 1) % n;
                a[q][j] = a[p][j] ^ a[p][j1] ^ a[p][j2];
            }
            vector<int> v(a[q], a[q] + n);
            int idx = find((vv).begin(), (vv).end(), v) - vv.begin();
            if (idx == (int)(vv).size()) {
                vv.push_back(v);
            } else {
                start = idx;
                circle = (int)(vv).size() - start;
                break;
            }
        }
        #ifdef DEBUG
        cout << start << " " << circle << endl;
        print2(vv);        
        #endif
        for (int i = 0; i < n; ++i) {
            if (i) cout << " ";
            if (k < start) cout << vv[k][i];
            else cout << vv[(k - start) % circle][i];
        }
        cout << endl;
    }
}
