/*
  ID:   aphrodi1
  LANG: C++
  PROG: comehome
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

ifstream fin("comehome.in");
ofstream fout("comehome.out");
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

const int MAX = INT_MAX / 2;

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
    vector< vector<int> > g(52, vector<int>(52, MAX));
    for (int i = 0; i < n; ++i) {
        char x, y;
        int dist;
        cin >> x >> y >> dist;
        int a = isupper(x) ? x - 'A' : x - 'a' + 26;
        int b = isupper(y) ? y - 'A' : y - 'a' + 26;
        g[a][b] = g[b][a] = min(g[a][b], dist);
    }

    for (int k = 0; k < 52; ++k)
        for (int i = 0; i < 52; ++i)
            for (int j = 0; j < 52; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

    char res;
    int res_dist = MAX;

    for (int i = 0; i < 25; ++i)
        if (g[i][25] < res_dist) {
            res = 'A' + i;
            res_dist = g[i][25];
        }

    cout << res << " " << res_dist << endl;
}
