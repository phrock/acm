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

int n, cnt, res, cur, cut;
string s;

void dfs(int aux)
{
    // cout << cur << " " << aux << endl;
    if (cur >= n || s[cur++] == '0') return;
    ++cut;
    if (aux + 1 > cnt) {
        cnt = aux + 1;
        res = cut;
    }
    dfs(aux + 1);
    dfs(aux + 1);
}

int main()
{
    for (int ti = 0; ti < 10; ++ti) {
        cin >> n >> s;
        cnt = res = cur = cut = 0;
        dfs(0);
        cout << res << endl;
   }
}
