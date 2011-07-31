/*
  ID:   aphrodi1
  LANG: C++
  PROG: castle
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

ifstream fin("castle.in");
ofstream fout("castle.out");
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

int m, n;
int g[55][55];
int visited[55][55];
int space[55][55];

int dir_x[] = {0, -1, 0, 1};
int dir_y[] = {-1, 0, 1, 0};
char dir[] = {'W', 'N', 'E', 'S'};

void dfs(int x, int y, int &cnt, int action, int room)
{
    visited[x][y] = room;
    if (action == 0) 
        ++cnt;
    else
        space[x][y] = cnt;
    for (int i = 0; i < 4; ++i) {
        int next_x = x + dir_x[i], next_y = y + dir_y[i];
        if ((!action ? !visited[next_x][next_y] : !space[next_x][next_y]) &&
            (next_x >= 0 && next_x < n) &&
            (next_y >= 0 && next_y < m) &&
            !(g[x][y] & (1 << i)))
            dfs(next_x, next_y, cnt, action, room);
    }
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
    
    cin >> m >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];
    int room = 0, max_space = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (!visited[i][j]) {
                ++room;
                int cnt = 0;
                dfs(i, j, cnt, 0, room);
                dfs(i, j, cnt, 1, room);
                max_space = max(max_space, cnt);
            }
    #ifdef DEBUG
    print2(visited, n, m);
    print2(space, n, m);    
    #endif
    cout << room << endl << max_space << endl;

    int max_join = 0, break_x, break_y;
    char break_dir;
    for (int j = 0; j < m; ++j)
        for (int i = n - 1; i >= 0; --i)
            for (int k = 0; k < 4; ++k) {
                int next_x = i + dir_x[k], next_y = j + dir_y[k];
                if ((next_x >= 0 && next_x < n) &&
                    (next_y >= 0 && next_y < m) &&
                    (g[i][j] & (1 << k)) &&
                    visited[i][j] != visited[next_x][next_y] &&
                    space[i][j] + space[next_x][next_y] > max_join) {
                    max_join = space[i][j] + space[next_x][next_y];
                    break_x = i + 1;
                    break_y = j + 1;
                    break_dir = dir[k];
                }
            }
    cout << max_join << endl;
    cout << break_x << " " << break_y << " " << break_dir << endl;
}
