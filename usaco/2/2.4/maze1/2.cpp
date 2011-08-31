/*
  ID:   aphrodi1
  LANG: C++
  PROG: maze1
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

ifstream fin("maze1.in");
ofstream fout("maze1.out");
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

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int w, h;
    cin >> w >> h;
    int n = 2 * h + 1, m = 2 * w + 1;
    string s;
    getline(cin, s);
    vector<string> g(n);
    for (int i = 0; i < (int)(g).size(); ++i)
        getline(cin, g[i]);
    vector< vector<int> > dist(n, vector<int>(m, INT_MAX));
    vector<int> start;
    for (int i = 0; i < m; ++i) {
        if (g[0][i] == ' ')
            start.push_back(m + i);
        if (g[n - 1][i] == ' ')
            start.push_back(m * (n - 2) + i);
    }
    for (int i = 0; i < n; ++i) {
        if (g[i][0] == ' ')
            start.push_back(i * m + 1);
        if (g[i][m - 1] == ' ')
            start.push_back(i * m + m - 2);
    }

    queue<int> q;
    for (int i = 0; i < (int)(start).size(); ++i) {
        int x = start[i] / m, y = start[i] % m;
        dist[x][y] = 1;
        q.push(start[i]);
    }

    while (!q.empty()) {
        int ft = q.front();
        q.pop();
        int x = ft / m, y = ft % m;
        for (int i = 0; i < 4; ++i) {
            int next_x = x + dir_x[i] * 2, next_y = y + dir_y[i] * 2;
            if (next_x >= 0 && next_y >= 0 && next_x < n && next_y < m &&
                g[x + dir_x[i]][y + dir_y[i]] == ' ' &&
                dist[x][y] + 1 < dist[next_x][next_y]) {
                dist[next_x][next_y] = dist[x][y] + 1;
                q.push(next_x * m + next_y);
            }
        }
    }

    int res = 0;
    for (int i = 0; i < (int)(dist).size(); ++i)
        for (int j = 0; j < (int)(dist[0]).size(); ++j)
            if (dist[i][j] != INT_MAX && res < dist[i][j])
                res = dist[i][j];

    #ifdef DEBUG
    print(start);
    for (int i = 0; i < (int)(dist).size(); ++i)
        for (int j = 0; j < (int)(dist[0]).size(); ++j)
            dist[i][j] = dist[i][j] == INT_MAX ? 0 : dist[i][j];
    print2(dist);    
    #endif
    cout << res << endl;
}
