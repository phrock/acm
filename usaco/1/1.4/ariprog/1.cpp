/*
  ID:   aphrodi1
  LANG: C++
  PROG: ariprog
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

ifstream fin("ariprog.in");
ofstream fout("ariprog.out");
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

int square[255 * 255 * 2];

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    //////////////////////////////////////////////////////////////////////////////

    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= m; ++i)
        for (int j = i; j <= m; ++j)
            square[i * i + j * j] = 1;
    #ifdef DEBUG
    print(square, m * m + 1);    
    #endif
    int upper = m * m * 2;
    vector< pair<int, int> > res;
    for (int b = 1; b <= upper; ++b)
        for (int a = 0; a < upper; ++a) {
            if (a + b * (n - 1) > upper)
                break;
            bool ok = true;
            for (int i = 0; i < n; ++i)
                if (!square[a + i * b]) {
                    ok = false;
                    break;
                }
            if (ok)
                res.push_back(make_pair(a, b));
        }
    if (res.empty()) {
        cout << "NONE" << endl;
    } else {
        for (int i = 0; i < (int)(res).size(); ++i)
            cout << res[i].first << " " << res[i].second << endl;
    }
}
