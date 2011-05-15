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

long long a[505][505];                // leftmost, rightmost
long long dp[505][505];               // leftmost sectors, scribers
int trace[505][505];

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            cin >> a[i][i];
        for (int i = 1; i < n; ++i) {
            a[0][i] = a[0][i - 1] + a[i][i];
            for (int j = 1; j < i; ++j)
                a[j][i] = a[0][i] - a[0][j - 1];
        }
        for (int i = 0; i < n; ++i)
            dp[i][1] = a[0][i];

        for (int i = 1; i < n; ++i)
            for (int j = 2; j <= min(m, i + 1); ++j) {
                long long aux = LLONG_MAX;
                for (int k = 1; k <= i; ++k) {
                    long long tmp = max(dp[i - k][j - 1], a[i - k + 1][i]);
                    if (tmp <= aux) {
                        aux = tmp;
                        trace[i][j] = k;
                    }
                }
                dp[i][j] = aux;
            }
        #ifdef DEBUG
        cout << dp[n - 1][m] << endl;
        #endif
        int remain = n - 1, idx = m;
        vector<int> res;
        while (idx != 1) {
            res.push_back(trace[remain][idx]);
            remain -= trace[remain][idx];
            --idx;
        }
        res.push_back(remain + 1);
        reverse((res).begin(), (res).end());
        #ifdef DEBUG
        print(res);        
        #endif
        int cnt = 0;
        for (int i = 0; i < (int)(res).size(); ++i) {
            if (i) cout << " / ";
            for (int j = 0; j < res[i]; ++j) {
                if (j) cout << " ";
                cout << a[cnt + j][cnt + j];
            }
            cnt += res[i];
        }
        cout << endl;
    }
}
