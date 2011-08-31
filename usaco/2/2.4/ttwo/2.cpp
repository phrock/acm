/*
  ID:   aphrodi1
  LANG: C++
  PROG: ttwo
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

ifstream fin("ttwo.in");
ofstream fout("ttwo.out");
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

int dir_x[] = {-1, 0, 1, 0};
int dir_y[] = {0, 1, 0, -1};

int visited[10][10][4][10][10][4];

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    vector<string> g(10);
    for (int i = 0; i < 10; ++i)
        cin >> g[i];
    int fx, fy, cx, cy;
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j)
            if (g[i][j] == 'F') {
                fx = i;
                fy = j;
            } else if (g[i][j] == 'C') {
                cx = i;
                cy = j;
            }
    int dir_f = 0, dir_c = 0;
    visited[fx][fy][dir_f][cx][cy][dir_c] = 1;
    int res = 0;
    while ((fx != cx) || (fy != cy)) {
        int next_fx = fx + dir_x[dir_f], next_fy = fy + dir_y[dir_f];
        if (next_fx >= 0 && next_fy >=0 && next_fx < 10 && next_fy < 10 &&
            g[next_fx][next_fy] != '*') {
            fx = next_fx;
            fy = next_fy;
        } else {
            dir_f = (dir_f + 1) % 4;
        }

        int next_cx = cx + dir_x[dir_c], next_cy = cy + dir_y[dir_c];
        if (next_cx >= 0 && next_cy >=0 && next_cx < 10 && next_cy < 10 &&
            g[next_cx][next_cy] != '*') {
            cx = next_cx;
            cy = next_cy;
        } else {
            dir_c = (dir_c + 1) % 4;
        }

        if (visited[fx][fy][dir_f][cx][cy][dir_c]) {
            res = 0;
            break;
        } else {
            visited[fx][fy][dir_f][cx][cy][dir_c] = 1;
            ++res;
        }
    }

    cout << res << endl;
}
