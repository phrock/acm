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
#include "/Users/Aphrodite/program/acm/lib/debug.cpp"
#endif

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/


int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> cnt(n + 1);
    vector< vector<int> > v(m);
    for (int i = 0; i < m; ++i) {
        int k;
        cin >> k;
        vector<int> aux(k);
        for (int j = 0; j < k; ++j) {
            cin >> aux[j];
            ++cnt[aux[j]];
        }
        v[i] = aux;
    }

    #ifdef DEBUG
    print(cnt);
    print2(v);
    #endif

    vector< vector<int> > x(1);
    for (int i = 1; i <= n; ++i)
        x[0].push_back(i);

    for (int i = 0; i < m; ++i) {
        vector< vector<int> > next;
        for (int j = 0; j < (int)(x).size(); ++j) {
            vector<int> intersection;
            set_intersection((x[j]).begin(), (x[j]).end(),
                             (v[i]).begin(), (v[i]).end(),
                             back_inserter(intersection));
            vector<int> diff1;
            set_difference((x[j]).begin(), (x[j]).end(),
                           (intersection).begin(), (intersection).end(),
                           back_inserter(diff1));
            if (!intersection.empty())
                next.push_back(intersection);
            if (!diff1.empty())
                next.push_back(diff1);
            vector<int> diff2;
            set_difference((v[i]).begin(), (v[i]).end(),
                           (intersection).begin(), (intersection).end(),
                           back_inserter(diff2));
            v[i] = diff2;
        }
        x = next;
    }

    int res = 0;
    for (int i = 0; i < (int)(x).size(); ++i) {
        bool ok = false;
        for (int j = 0; j < (int)(x[i]).size(); ++j)
            if (cnt[x[i][j]] > 0) {
                ok = true;
                break;
            }
        if (ok)
            ++res;
    }
    cout << res << endl;
}
