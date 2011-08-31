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

struct node {
    int idx, speed, ram, hdd, cost;
    bool operator<(const node &comp) const { return cost < comp.cost; }
};

int main()
{
    int n;
    cin >> n;
    vector<node> v(n);
    for (int i = 0; i < n; ++i) {
        v[i].idx = i + 1;
        cin >> v[i].speed >> v[i].ram >> v[i].hdd >> v[i].cost;
    }
    sort((v).begin(), (v).end());
    for (int i = 0; i < n; ++i) {
        bool ok = true;
        for (int j = i + 1; j < n; ++j)
            if (v[i].speed < v[j].speed && v[i].ram < v[j].ram &&
                v[i].hdd < v[j].hdd) {
                ok = false;
                break;
            }
        if (ok) {
            cout << v[i].idx << endl;
            break;
        }
    }
}
