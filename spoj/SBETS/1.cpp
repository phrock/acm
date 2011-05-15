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
        set<string> team, lose;
        int a, b;
        string s1, s2;
        for (int i = 0; i < 16; ++i) {
            cin >> s1 >> s2 >> a >> b;
            team.insert(s1);
            team.insert(s2);
            if (a > b) lose.insert(s2);
            else lose.insert(s1);
        }
        for (__typeof((team).begin()) i = (team).begin(); i != (team).end(); ++i)
            if (!((lose).find(*i) != (lose).end())) {
                cout << *i << endl;
                break;
            }
    }
}
