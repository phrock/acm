/*
  ID:   aphrodi1
  LANG: C++
  PROG: fence8
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

ifstream fin("fence8.in");
ofstream fout("fence8.out");
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

int n, m;
int board[52];
int rails[1024], total[1024];
int res;
bool ok;

void dfsid(int deep, int cur, int max_waste, int waste)
{
    // cout << deep << " " << cur << " " << max_waste << " " << waste << endl;
    if (ok) return;
    if (deep < 0) {
        ok = true;
        return;
    }
    for (int i = cur; i < n; ++i) {
        if (board[i] >= rails[deep]) {
            board[i] -= rails[deep];
            if (board[i] < rails[0] && waste + board[i] > max_waste) {
                board[i] += rails[deep];
                continue;
            }
            int next_waste = board[i] < rails[0] ? waste + board[i] : waste;
            if (deep > 0 && rails[deep - 1] == rails[deep])
                dfsid(deep - 1, i, max_waste, next_waste);
            else
                dfsid(deep - 1, 0, max_waste, next_waste);
            board[i] += rails[deep];
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

    int sum = 0;
    res = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
        sum += board[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
        cin >> rails[i];
    sort(board, board + n);
    sort(rails, rails + m);

    for (int i = 0; i < m; ++i) {
        total[i] = i == 0 ? rails[i] : total[i - 1] + rails[i];
        if (total[i] > sum) {
            m = i;
            break;
        }
    }

    ok = false;
    for (int deep = m - 1; deep >= 0; --deep) {
        dfsid(deep, 0, sum - total[deep], 0);
        if (ok) {
            res = deep + 1;
            break;
        }
    }

    cout << res << endl;
}
