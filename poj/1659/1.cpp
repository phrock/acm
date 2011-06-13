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
#include "/home/Aphrodite/program/acm/topcoder/libs/debug.cpp"
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
    for (int ti = 0; ti < T; ++ti) {
        if (ti) cout << endl;
        int n;
        cin >> n;
        vector<int> a(n);
        vector< vector<int> > g(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        vector< pair<int, int> > vp(n);
        for (int i = 0; i < n; ++i)
            vp[i].first = a[i], vp[i].second = i;
        sort((vp).begin(), (vp).end(), greater<pair<int, int> >());
        bool ok = true;
        while (vp[0].first) {
            #ifdef DEBUG
            printp(vp);            
            #endif
            int aux = vp[0].first;
            for (int j = 0; j < aux; ++j)
                if (j + 1 < n && vp[j + 1].first) {
                    --vp[0].first;
                    --vp[j + 1].first;
                    g[vp[0].second][vp[j + 1].second] = g[vp[j + 1].second][vp[0].second] = 1;
                }
                else {
                    ok = false;
                    break;
                }
            if (!ok) break;
            sort((vp).begin(), (vp).end(), greater<pair<int, int> >());
        }
        if (ok) {
            cout << "YES" << endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (j) cout << " ";
                    cout << g[i][j];
                }
                cout << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }       
}
