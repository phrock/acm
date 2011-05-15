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

char s[1024];

int main()
{
    int T;
    gets(s);
    T = *({stringstream ss; ss << (s); static int _; ss >> _; &_;});
    for (int ti = 0; ti < T; ++ti) {
        if (ti) cout << endl, gets(s);
        int n;
        gets(s);
        n = *({stringstream ss; ss << (s); static int _; ss >> _; &_;});
        map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            gets(s);
            ++mp[string(s)];
        }
        for (__typeof((mp).begin()) i = (mp).begin(); i != (mp).end(); ++i) {
            cout << i->first << i->second << endl;
        }
    }
}
