/*
  ID:   aphrodi1
  LANG: C++
  PROG: camelot
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

ifstream fin("camelot.in");
ofstream fout("camelot.out");
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

int knight_dirx[] = {-1, -1, 1, 1};
int knight_diry[] = {-1, 1, -1, 1};

int dist[32][32][32][32];

const int MAX = INT_MAX / 2;

int king_move(int kingx, int kingy, int x, int y)
{
    int diffx = abs(kingx - x), diffy = abs(kingy - y);
    int min_diff = min(diffx, diffy);
    return min_diff + (diffx - min_diff) + (diffy - min_diff);
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int R, C;
    cin >> R >> C;

    for (int ix = 0; ix < R; ++ix)
        for (int iy = 0; iy < C; ++iy)
            for (int jx = 0; jx < R; ++jx)
                for (int jy = 0; jy < C; ++jy)
                    dist[ix][iy][jx][jy] = INT_MAX / 2;
    for (int ix = 0; ix < R; ++ix)
        for (int iy = 0; iy < C; ++iy) {
            pair<int, int> start = make_pair(ix, iy);
            queue<pair<int, int> > q;
            q.push(start);
            dist[ix][iy][ix][iy] = 0;
            while (!q.empty()) {
                pair<int, int> ft = q.front();
                q.pop();
                int x = ft.first, y = ft.second;
                for (int i = 0; i < 4; ++i)
                    for (int j = 0; j < 2; ++j) {
                        int dirx = knight_dirx[i], diry = knight_diry[i];
                        if (j) dirx *= 2;
                        else diry *= 2;
                        int nextx = x + dirx, nexty = y + diry;
                        if ((nextx >= 0 && nextx < R) &&
                            (nexty >= 0 && nexty < C) &&
                            dist[ix][iy][nextx][nexty] == MAX) {
                            dist[ix][iy][nextx][nexty] = dist[ix][iy][x][y] + 1;
                            q.push(make_pair(nextx, nexty));
                        }
                    }
            }
        }

    char tmpy;
    int tmpx;
    cin >> tmpy >> tmpx;
    int kingx = tmpx - 1, kingy = tmpy - 'A';
    vector<pair<int, int> > knight;
    while (cin >> tmpy >> tmpx) {
        int knightx = tmpx - 1, knighty = tmpy - 'A';
        knight.push_back(make_pair(knightx, knighty));
    }

    int res = MAX;
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j) {
            int aux = 0;
            bool ok = true;
            for (int k = 0; k < (int)(knight).size(); ++k)
                if (dist[i][j][knight[k].first][knight[k].second] == MAX) {
                    ok = false;
                    break;
                } else {
                    aux += dist[i][j][knight[k].first][knight[k].second];
                }
            if (!ok) continue;

            int sum = aux + king_move(kingx, kingy, i, j);

            for (int p = -4; p <= 4; ++p)
                for (int q = -4; q <= 4; ++q) {
                    int kx = kingx + p, ky = kingy + q;
                    if ((kx >= 0 && kx < R) && (ky >= 0 && ky < C)) {
                        int tmp = aux + king_move(kingx, kingy, kx, ky);
                        for (int k = 0; k < (int)(knight).size(); ++k) {
                            if (dist[kx][ky][knight[k].first][knight[k].second] != MAX) {
                                int tmp2 = tmp - dist[i][j][knight[k].first][knight[k].second] + dist[kx][ky][knight[k].first][knight[k].second] + dist[kx][ky][i][j];
                                sum = min(sum, tmp2);
                            }
                        }
                    }
                }
            res = min(res, sum);
        }
    cout << res << endl;
}
