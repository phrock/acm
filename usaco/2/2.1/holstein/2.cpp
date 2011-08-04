/*
  ID:   aphrodi1
  LANG: C++
  PROG: holstein
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

ifstream fin("holstein.in");
ofstream fout("holstein.out");
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


int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    int m;
    cin >> m;
    vector<vector<int> > food(m, vector<int>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> food[i][j];
    int res = INT_MAX;
    vector<int> res_aux;
    for (int i = 0; i < (1 << m); ++i) {
        int tmp = __builtin_popcount(i);
        if (tmp >= res) continue;
        vector<int> eat(n);
        for (int j = 0; j < m; ++j)
            if (i & (1 << j)) {
                for (int k = 0; k < n; ++k)
                    eat[k] += food[j][k];
            }
        bool ok = true;
        for (int j = 0; j < n; ++j)
            if (eat[j] < v[j]) {
                ok = false;
                break;
            }
        if (ok) {
            res = tmp;
            res_aux.clear();
            for (int j = 0; j < m; ++j)
                if (i & (1 << j))
                    res_aux.push_back(j + 1);
        }
    }
    cout << res;
    for (int i = 0; i < (int)(res_aux).size(); ++i)
        cout << " " << res_aux[i];
    cout << endl;
}
