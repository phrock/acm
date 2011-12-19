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
#include "/Users/Aphrodite/program/acm/lib/debug.cpp"
#endif

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

int hit[10];
int score[10];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        hit[i] = 100;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        if (hit[x] > 0) {
            if (hit[y] > 0) {
                score[x] += 3;
            }
            hit[y] -= 8;
        }
    }
    for (int i = 1; i <= n; ++i)
        if (hit[i] > 0)
            score[i] += hit[i] / 2;
    for (int i = 1; i <= n; ++i)
        cout << hit[i] << " " << score[i] << endl;
}
