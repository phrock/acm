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

const int MAX = 505;
// int prefer_man[MAX][MAX];
int prefer_woman[MAX][MAX];
int idx_man[MAX];
int order_man[MAX][MAX];
int match_man[MAX];
int match_woman[MAX];

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i)
            idx_man[i] = 1;
        memset(match_man, 0, sizeof(match_man));
        memset(match_woman, 0, sizeof(match_woman));
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x;
            for (int j = 1; j <= n; ++j) {
                cin >> y;
                prefer_woman[x][y] = n - j;
            }
        }
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x;
            for (int i = 1; i <= n; ++i) {
                cin >> y;
                order_man[x][i] = y;
            }
        }
        #ifdef DEBUG
        print2(prefer_woman, n + 1, n + 1);
        print2(order_man, n + 1, n + 1);
        #endif
        
        while (true) {
            bool ok = true;
            for (int i = 1; i <= n; ++i) {
                if (!match_man[i]) {
                    ok = false;
                    for (int j = idx_man[i]; j <= n; ++j) {
                        int woman = order_man[i][j];
                        if (!match_woman[woman]) {
                            match_man[i] = woman;
                            match_woman[woman] = i;
                            idx_man[i] = j + 1;
                            break;
                        } else if (prefer_woman[woman][i] > prefer_woman[woman][match_woman[woman]]) {
                            match_man[match_woman[woman]] = 0;
                            match_man[i] = woman;
                            match_woman[woman] = i;
                            idx_man[i] = j + 1;
                            break;
                        }
                    }
                }
            }
            if (ok) break;
        }

        for (int i = 1; i <= n; ++i)
            cout << i << " " << match_man[i] << endl;
    }
}
