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
    cout << setiosflags(ios::fixed) << setprecision(9);
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> x(n);
        for (int i = 0; i < n; ++i)
            cin >> x[i];
        vector<double> p(n);
        for (int i = 0; i < n; ++i)
            p[i] = 1.0 / 2 / x[i];
        map<int, double> mp;
        for (int i = -x[0]; i < x[0]; ++i)
            mp[i] = p[0];

        for (int i = 1; i < n; ++i) {
            map<int, double> aux;
            for (__typeof((mp).begin()) j = (mp).begin(); j != (mp).end(); ++j)
                for (int k = -x[i]; k < x[i]; ++k) {
                    aux[j->first + k] += j->second * p[i] / 2;
                    aux[j->first + k + 1] += j->second * p[i] / 2;
                }
            mp = aux;
        }
        double res = 0;
        for (int i = a; i < b; ++i)
            if (((mp).find(i) != (mp).end()))
                res += mp[i];
        cout << res << endl;
        #ifdef DEBUG
        printp(mp);        
        #endif
    }
}
