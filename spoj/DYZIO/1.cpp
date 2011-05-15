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

int n, deepest, cur, res;
string s;

void dfs(int depth)
{
    if (depth < deepest && s[++cur] == '1') ++res, dfs(depth + 1), dfs(depth + 1);
}

int main()
{
    for (int ti = 0; ti < 10; ++ti) {
        cin >> n >> s;
        cur = -1;
        res = 0;
        deepest = 0;
        while (n != 1) ++deepest, n >>= 1;
        dfs(0);
        cout << res << endl;
   }
}
