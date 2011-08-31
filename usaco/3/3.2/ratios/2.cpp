/*
  ID:   aphrodi1
  LANG: C++
  PROG: ratios
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

ifstream fin("ratios.in");
ofstream fout("ratios.out");
streambuf *cin_buf = cin.rdbuf();
streambuf *cout_buf = cout.rdbuf();

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

    vector<int> goal(3);
    vector< vector<int> > a(3, vector<int>(3));
    for (int i = 0; i < 3; ++i)
        cin >> goal[i];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> a[i][j];

    int sum = INT_MAX, a0, a1, a2, g;
    for (int i = 0; i < 100; ++i)
        for (int j = 0; j < 100; ++j)
            for (int k = 0; k < 100; ++k) {
                vector<int> b(3);
                for (int p = 0; p < 3; ++p)
                    b[p] = i * a[0][p] + j * a[1][p] + k * a[2][p];
                bool ok = true;
                int z = -1;
                for (int p = 0; p < 3; ++p)
                    if (!goal[p]) {
                        if (b[p]) ok = false;
                    } else {
                        if (b[p] < goal[p] || b[p] % goal[p]) ok = false;
                        if (z == -1) {
                            z = b[p] / goal[p];
                        } else if (z != b[p] / goal[p]) {
                            ok = false;
                        }
                    }
                

                if (i + j + k < sum && ok) {
                    sum = i + j + k;
                    a0 = i;
                    a1 = j;
                    a2 = k;
                    g = b[0] / goal[0];
                }
            }
    if (sum == INT_MAX) {
        cout << "NONE" << endl;
    } else {
        cout << a0 << " " << a1 << " " << a2 << " " << g << endl;
    }
}
