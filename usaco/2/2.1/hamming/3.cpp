/*
  ID:   aphrodi1
  LANG: C++
  PROG: hamming
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

ifstream fin("hamming.in");
ofstream fout("hamming.out");
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

int dist[1024][1024];
int N, B, D;
int MAX;
bool ok;
int res[100];

void dfs(int cur, int start)
{
    if (ok) return;
    if (cur == N) {
        ok = true;
        return;
    }
    if (start > MAX) return;

    for (int k = start; k <= MAX; ++k) {
        bool check = true;
        for (int i = 0; i < cur; ++i)
            if (dist[res[i]][k] < D) {
                check = false;
                break;
            }
        if (check) {
            int orig = res[cur];
            res[cur] = k;
            if (!ok) dfs(cur + 1,  k + 1);
            if (ok) return;
            res[cur] = orig;
        }
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

    cin >> N >> B >> D;
    MAX = (1 << B) - 1;
    for (int i = 0; i <= MAX; ++i)
        for (int j = i + 1; j <= MAX; ++j)
            dist[i][j] = dist[j][i] = __builtin_popcount(i ^ j);
    ok = false;
    dfs(0, 0);
    if (!ok) return 0;
    for (int i = 0; i < N; ++i) {
        if (i % 10) cout << " ";
        cout << res[i];
        if (((i + 1) % 10 == 0) || (i + 1 == N)) cout << endl;
    }
}
