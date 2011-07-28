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
    string s;
    cin >> s;
    int idx = 0, cnt = 0;
    for (int i = 0; i < (int)(s).size(); ++i) {
        if (s[i] == '1') {
            idx = i;
            ++cnt;
        }
    }
    if (cnt == 1) {
        cout << (int)(s).size() - 1 << endl;
    } else {
        cout << idx - cnt + (int)(s).size() + 2 << endl;
    }
}
