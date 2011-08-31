/*
  ID:   aphrodi1
  LANG: C++
  PROG: rect1
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

ifstream fin("rect1.in");
ofstream fout("rect1.out");
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


struct node
{
    int x1;
    int y1;
    int x2;
    int y2;
    int color;
};

int A, B, n;
vector<node> point;
map<int, int> res;

void dfs(int x1, int y1, int x2, int y2, int above, int color)
{
    while (((x1 >= point[above].x2) || (y1 >= point[above].y2) ||
            (x2 <= point[above].x1) || (y2 <= point[above].y1)) &&
           (above <= n))
        ++above;

    if (above > n) {
        res[color] += (x2 - x1) * (y2 - y1);
        return;
    }

    if (x1 < point[above].x1) {
        dfs(x1, y1, point[above].x1, y2, above + 1, color);
        x1 = point[above].x1;
    }
    if (x2 > point[above].x2) {
        dfs(point[above].x2, y1, x2, y2, above + 1, color);
        x2 = point[above].x2;
    }
    if (y1 < point[above].y1) {
        dfs(x1, y1, x2, point[above].y1, above + 1, color);
        y1 = point[above].y1;
    }
    if (y2 > point[above].y2) {
        dfs(x1, point[above].y2, x2, y2, above + 1, color);
        y2 = point[above].y2;
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

    cin >> A >> B >> n;
    point.resize(n + 1);
    point[0].x1 = point[0].y1 = 0;
    point[0].x2 = A; point[0].y2 = B;
    point[0].color = 1;
    for (int i = 1; i <= n; ++i)
        cin >> point[i].x1 >> point[i].y1 >> point[i].x2 >> point[i].y2 >> point[i].color;
    for (int i = n; i >= 0; --i)
        dfs(point[i].x1, point[i].y1, point[i].x2, point[i].y2, i + 1, point[i].color);
    for (__typeof((res).begin()) i = (res).begin(); i != (res).end(); ++i)
        cout << i->first << " " << i->second << endl;
}
