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
    --k1;
    ++res;

    vector< pair<int, int> > v(3);
    v[0] = make_pair(p1, k1);
    v[1] = make_pair(p2, k2);
    v[2] = make_pair(p3, n);

    // 001, 101, 011, 111 => 100, 101, 110, 111
    vector<int> candidate;
    candidate.push_back(4);
    candidate.push_back(5);
    candidate.push_back(6);
    candidate.push_back(7);

    int orig_n = n;
    for (int j = 0; j < (int)(candidate).size(); ++j) {
        int tmp = 1, n = orig_n;
        for (int i = 0; i < (int)(v).size(); ++i) {
            if (((1 << i) & candidate[j]) == 0)
                continue;
            int aux = n / v[i].first;
            aux = min(aux, v[i].second);
            tmp += aux;
            n -= aux * v[i].first;
        }
        res = max(res, tmp);
    }

    cout << res << endl;
}
