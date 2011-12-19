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


int main()
{
    int n, k1, k2, p1, p2, p3;
    cin >> n >> k1 >> k2 >> p1 >> p2 >> p3;
    int res = 0;
    if (n < p1) {
        cout << 0 << endl;
        return 0;
    }
    n -= p1;
    res += k1;

    vector< pair<int, int> > v(2);
    v[0] = make_pair(p2, k2);
    v[1] = make_pair(p3, 10000000);

    for (int i = 0; i < (int)(v).size(); ++i) {
        int aux = n / v[i].first;
        if (n % v[i].first)
            ++aux;
        aux = min(aux, v[i].second);
        res += aux;
        n -= aux * v[i].first;
        if (n <= 0)
            break;
    }

    cout << res << endl;
}
