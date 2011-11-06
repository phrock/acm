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

/*****************************************************************************
 *                                                                           *
 *                To see the world in a grain of sand,                       *
 *                And a heaven in a wild flower;                             *
 *                Hold infinity in the palm of your hand,                    *
 *                And eternity in an hour.                                   *
 *                                                                           *
 ****************************************************************************/


int main()
{
    int n;
    cin >> n;
    int m = 3;
    while (m * (m + 1) / 2 <= n)
        ++m;
    cout << m << endl;
    int cnt = 1;
    vector< vector<int> > res(m);
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            res[i].push_back(cnt);
            res[j].push_back(cnt);
            ++cnt;
        }
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < (int)(res[i]).size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
