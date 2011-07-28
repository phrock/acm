/*
  ID:   aphrodi1
  LANG: C++
  PROG: checker
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

ifstream fin("checker.in");
ofstream fout("checker.out");
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

void dfs(int n, int cur, vector<int> &v, vector<int> &forbid,
         int &res, vector< vector<int> > &queen)
{
    if (cur > n) {
        ++res;
        if ((int)(queen).size() < 3)
            queen.push_back(v);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (forbid[i])
            continue;
        bool ok = true;
        for (int j = 1; j < cur; ++j)
            if (abs(cur - j) == abs(i - v[j])) {
                ok = false;
                break;
            }
        if (ok) {
            v[cur] = i;
            forbid[i] = 1;
            dfs(n, cur + 1, v, forbid, res, queen);
            forbid[i] = 0;
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

    int n;
    cin >> n;
    vector<int> v(n + 1), forbid(n + 1);
    int res = 0;
    vector< vector<int> > queen;
    if (n == 6) {
        dfs(n, 1, v, forbid, res, queen);
    } else {
        for (int i = 1; i <= n / 2; ++i) {
            v[1] = i;
            forbid[i] = 1;
            dfs(n, 2, v, forbid, res, queen);
            forbid[i] = 0;
        }
        res <<= 1;
        if (n % 2) {
            v[1] = n / 2 + 1;
            forbid[n / 2 + 1] = 1;
            dfs(n, 2, v, forbid, res, queen);
            forbid[n / 2 + 1] = 0;
        }
    }

    for (int i = 0; i < (int)(queen).size(); ++i) {
        for (int j = 1; j < (int)(queen[i]).size(); ++j) {
            if (j > 1) cout << " ";
            cout << queen[i][j];
        }
        cout << endl;
    }
    cout << res << endl;
}
