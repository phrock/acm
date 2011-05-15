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
    for (int ti = 0; ti < T; ++ti) {
        if (ti) cout << endl;
        int n;
        cin >> n;
        map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            string s, aux;
            for (int j = 0; j < 6; ++j) {
                cin >> aux;
                s += aux;
            }
            ++mp[s];
        }
        for (__typeof((mp).begin()) i = (mp).begin(); i != (mp).end(); ++i) {
            cout << i->first.substr(0, 2) << " "
                 << i->first.substr(2, 8) << " "
                 << i->first.substr(10, 4) << " "
                 << i->first.substr(14, 4) << " "
                 << i->first.substr(18, 4) << " "
                 << i->first.substr(22, 4) << " "
                 << i->second << endl;
        }
    }
}
