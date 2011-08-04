/*
  ID:   aphrodi1
  LANG: C++
  PROG: concom
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

ifstream fin("concom.in");
ofstream fout("concom.out");
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

const int MAX = 100;
int control[MAX + 5][MAX + 5];
int own[MAX + 5][MAX + 5];
int sum[MAX + 5][MAX + 5];

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
    for (int i = 0; i < n; ++i) {
        int x, y, k;
        cin >> x >> y >> k;
        own[x][y] = k;
    }
    queue<pair<int, int> > q;
    for (int i = 1; i <= MAX; ++i)
        q.push(make_pair(i, i));
    while (!q.empty()) {
        pair<int, int> ft = q.front();
        q.pop();
        int x = ft.first, y = ft.second;
        if (control[x][y]) continue;
        control[x][y] = 1;
        for (int i = 1; i <= MAX; ++i)
            if (!control[x][i]) {
                sum[x][i] += own[y][i];
                if (sum[x][i] > 50)
                    q.push(make_pair(x, i));
            }
    }
    for (int i = 1; i <= MAX; ++i)
        for (int j = 1; j <= MAX; ++j)
            if (i != j && control[i][j])
                cout << i << " " << j << endl;
}
