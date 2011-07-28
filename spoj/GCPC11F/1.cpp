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
    int ts;
    cin >> ts;
    string s;
    getline(cin, s);
    for (int ti = 0; ti < ts; ++ti) {
        getline(cin, s);
        map<char, int> mp;
        char c;
        int m = 0, cnt = 0;
        for (int i = 0; i < (int)(s).size(); ++i) {
            if (!isupper(s[i])) continue;
            ++mp[s[i]];
            if (mp[s[i]] > m) {
                m = mp[s[i]];
                c = s[i];
                cnt = 1;
            } else if (mp[s[i]] == m) {
                ++cnt;
            }
        }
        if (cnt > 1) {
            cout << "NOT POSSIBLE" << endl;
            continue;
        }
        // cout << c << " ** " << cnt << endl;
        int d = ((c - 'A') + 26 - ('E' - 'A')) % 26;
        // cout << min(d, 26 - d) << " ";
        string res;
        for (int i = 0; i < (int)(s).size(); ++i)
            if (isupper(s[i])) 
                res += (s[i] - 'A' + 26 - d) % 26 + 'A';
            else
                res += s[i];
        cout << d << " " << res << endl;
    }
}
