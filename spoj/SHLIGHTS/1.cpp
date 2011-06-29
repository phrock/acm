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

char s[100005];

int main()
{
    int T;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ++ti) {
        scanf("%s", s);
        int n = strlen(s);
        int blue = 0, res = 0, block = 0;
        int tringger = false;
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'B') {
                ++blue;
                if (tringger)
                    res = max(res, i - blue + block);
                // cout << i << " : " << res << " " << blue << " " << block<<endl;
                ++block;
            } else {
                tringger = true;
                block = max(block - 1, 0);
            }
        }
        
        cout << res << endl;
    }
}
