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
    int n;
    cin >> n;
    int m = (n / 7) * 7;
    string res;
    for (int i = m; i >= 0; i -= 7)
        if ((n - i) % 4 == 0) {
            res = string((n - i) / 4, '4') + string (i / 7, '7');
            break;
        }
    if (res.empty())
        cout << -1 << endl;
    else
        cout << res << endl;
}
