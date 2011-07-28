/*
  ID:   aphrodi1
  LANG: C++
  PROG: packrec
*/

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

ifstream fin("packrec.in");
ofstream fout("packrec.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

void check(int x, int y, int &min_area, set< pair<int, int> > &res)
{
    if (x > y) swap(x, y);
    int area = x * y;
    if (area < min_area) {
        min_area = area;
        res.clear();
        res.insert(make_pair(x, y));
    } else if (area == min_area) {
        res.insert(make_pair(x, y));
    }
}

void func(const vector< pair<int, int> > &v, int &min_area,
          set< pair<int, int> > &res)
{
    int x = 0, y = 0;
    for (int i = 0; i < (int)(v).size(); ++i) {
        x += v[i].first;
        y = max(y, v[i].second);
    }
    check(x, y, min_area, res);

    x = max(v[0].first, v[1].first + v[2].first + v[3].first);
    y = v[0].second + max(v[1].second, max(v[2].second, v[3].second));
    check(x, y, min_area, res);

    x = max(v[0].first + v[1].first, v[1].first + v[2].first + v[3].first);
    y = max(v[0].second + max(v[2].second, v[3].second), v[1].second);
    check(x, y, min_area, res);

    x = v[0].first + max(v[1].first, v[2].first) + v[3].first;
    y = max(v[0].second, max(v[1].second + v[2].second, v[3].second));
    check(x, y, min_area, res);

    x = max(v[0].first + v[1].first, v[2].first + v[3].first);
    y = max(v[0].second + v[2].second, v[1].second + v[3].second);
    if (v[0].second > v[1].second) x = max(x, v[0].first + v[3].first);
    if (v[1].second > v[0].second) x = max(x, v[1].first + v[2].first);
    check(x, y, min_area, res);

}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    //////////////////////////////////////////////////////////////////////////////

    int min_area = INT_MAX;
    set< pair<int, int> > res;
    vector< pair<int, int> > v(4);
    for (int i = 0; i < 4; ++i)
        cin >> v[i].first >> v[i].second;
    for (int p = 0; p < (1 << 4); ++p) {
        vector< pair<int, int> > v2 = v;
        for (int q = 0; q < 4; ++q) {
            if (p & (1 << q))
                swap(v2[q].first, v2[q].second);
        }
        int a[4] = {0, 1, 2, 3};
        do {
            vector< pair<int, int> > aux(4);
            for (int i = 0; i < 4; ++i)
                aux[i] = v2[a[i]];
            func(aux, min_area, res);
        } while (next_permutation(a, a + 4));
    }

    cout << min_area << endl;
    for (__typeof((res).begin()) i = (res).begin(); i != (res).end(); ++i)
        cout << i->first << " " << i->second << endl;
}
