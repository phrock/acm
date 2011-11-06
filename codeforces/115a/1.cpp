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
    vector<int> v(n + 5);
    for (int i = 1; i <= n; ++i) {
        cin >> v[i];
    }
    int res = 1;
    vector<int> p(n + 5);
    for (int i = 1; i <= n; ++i) {
        if (p[i]) continue;
        p[i] = 1;
        int aux = 1, x = i;
        while (v[x] != -1) {
            ++aux;
            p[x] = 1;
            x = v[x];
        }
        res = max(res, aux);
    }
    cout << res << endl;
}
