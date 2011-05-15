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

int hash(const string &s)
{
    int res = 0;
    for (int i = 0; i < (int)(s).size(); ++i)
        res += int(s[i]) * (i + 1);
    return (19 * res) % 101;
}

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n;
        cin >> n;
        map<string, int> si;
        map<int, string> is;
        for (int i = 0; i < n; ++i) {
            string s, op, key;
            cin >> s;
            op = s.substr(0, 3);
            key = s.substr(4);
            if (op == "ADD") {
                if (((si).find(key) != (si).end())) continue;
                for (int j = 0; j < 20; ++j) {
                    int value = (j * j + 23 * j + hash(key)) % 101;
                    if (!((is).find(value) != (is).end())) {
                        si[key] = value;
                        is[value] = key;
                        break;
                    }
                }
            } else {
                if (!((si).find(key) != (si).end())) continue;
                int value = si[key];
                si.erase(key);
                is.erase(value);
            }
        }
        cout << (int)(is).size() << endl;
        for (__typeof((is).begin()) i = (is).begin(); i != (is).end(); ++i)
            cout << i->first << ":" << i->second << endl;
    }
}
