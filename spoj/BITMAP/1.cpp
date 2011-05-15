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
#include "/home/rock/program/topcoder/libs/debug.cpp"
#endif

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

int g[200][200];
int dist[200][200];
int n, m;

int p1[] = {-1, 1, 0, 0};
int p2[] = {0, 0, -1, 1};

void func()
{
    queue<int> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (g[i][j]) dist[i][j] = 0, q.push(i * m + j);
            else dist[i][j] = INT_MAX / 2;
    while (!q.empty()) {
        int x = q.front() / m, y = q.front() % m, d = dist[x][y];
        q.pop();
        int next_x, next_y;
        for (int i = 0; i < 4; ++i) {
            next_x = x + p1[i];
            next_y = y + p2[i];
            if (next_x >= 0 && next_y >=0 && next_x < n && next_y < m) {
                if (d + 1 < dist[next_x][next_y]) {
                    dist[next_x][next_y] = d + 1;
                    q.push(next_x * m + next_y);
                }
            }
        }
    }
}

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        cin >> n >> m;
        string s;
        for (int i = 0; i < n; ++i) {
            cin >> s;
            for (int j = 0; j < m; ++j)
                g[i][j] = s[j] == '1' ? 1 : 0;
        }
        func();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (j) cout << " ";
                cout << dist[i][j];
            }
            cout << endl;
        }
    }
}
