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
    for (int ti = 1; ti <= T; ++ti) {
        cout << "Case #" << ti << ":" << endl;
        string s;
        int x, m = 0;
        map<string, int> mp;
        vector<string> v;
        for (int i = 0; i < 10; ++i) {
            cin >> s >> x;
            m = max(m, x);
            if (((mp).find(s) != (mp).end())) {
                mp[s] = max(mp[s], x);
            } else {
                v.push_back(s);
                mp[s] = x;
            }
        }
        for (int i = 0; i < (int)(v).size(); ++i)
            if (mp[v[i]] == m)
                cout << v[i] << endl;
    }
}
