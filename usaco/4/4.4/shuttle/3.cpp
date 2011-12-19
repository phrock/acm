/*
  ID:   aphrodi1
  LANG: C++
  PROG: shuttle
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
#include "/Users/Aphrodite/program/acm/lib/debug.cpp"
#endif

ifstream fin("shuttle.in");
ofstream fout("shuttle.out");
streambuf *cin_buf = cin.rdbuf();
streambuf *cout_buf = cout.rdbuf();

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

const int MAX = 1000000;
int v[MAX], pre[MAX];

int power(int x, int n)
{
    int res = 1;
    for (int i = 0; i < n; ++i)
        res *= x;
    return res;
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    /////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;

    int start = 0;
    for (int i = 0; i < n; ++i)
        start += power(3, i);
    start += 2 * power(3, n);

    int dest = 0;
    dest += 2 * power(3, n);
    for (int i = n + 1; i < 2 * n + 1; ++i)
        dest += power(3, i);

    #ifdef DEBUG
    cout << power(3, 1) << endl;
    cout << start << " " << dest << endl;
    #endif
    queue<int> q;
    q.push(start);
    v[start] = -1;

    while (!q.empty()) {
        int ft = q.front();
        q.pop();
        if (ft == dest)
            break;
        int space = v[ft] - 1;
        if (space == -2)
            space = n;

        for (int i = -2; i <= 2; ++i) {
            int idx;
            if ((i == -2 && space > 1) ||
                (i == -1 && space > 0) ||
                (i == 1 && space < 2 * n) ||
                (i == 2 && space < 2 * n - 1)) {
                idx = space + i;
            } else {
                continue;
            }
            int next = ft;
            int x = next / power(3, space) % 3;
            int y = next / power(3, idx) % 3;
            next -= x * power(3, space) + y * power(3, idx);
            next += x * power(3, idx) + y * power(3, space);

            if (v[next] == 0) {
                q.push(next);
                v[next] = idx + 1;
                pre[next] = ft;
            }
        }
    }

    vector<int> res;
    while (v[dest] != -1) {
        res.push_back(v[dest]);
        dest = pre[dest];
    }
    reverse((res).begin(), (res).end());
    #ifdef DEBUG
    print(res);    
    #endif
    for (int i = 0; i < (int)(res).size(); ++i) {
        if (i % 20 == 0) {
            if (i)
                cout << endl;
        } else {
            cout << " ";
        }
        cout << res[i];
    }
    cout << endl;

}
