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
        int n, k;
        cin >> n >> k;
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        int big = INT_MAX, big_num = 0, pre = 0;
        vector<int> aux(n);
        for (int i = 0; i < n; ++i) {
            if (i) aux[i] = aux[i - 1];
            if (v[i] > v[k]) {
                ++big_num;
                if (v[i] <= big) {
                    big = v[i];
                    pre = i;
                }
            } else if (v[i] == v[k]) {
                ++aux[i];
            }
        }
        int res = big == INT_MAX ? aux[k] : (k > pre ? big_num + aux[k] - aux[pre] : big_num + aux[k] + aux[n - 1] - aux[pre]);
        cout << res << endl;
    }
}
