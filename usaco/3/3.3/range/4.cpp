/*
  ID:   aphrodi1
  LANG: C++
  PROG: range
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

ifstream fin("range.in");
ofstream fout("range.out");
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

int dp[255][255];
int dx[255][255];
int dy[255][255];

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
    vector<string> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (v[i][j] == '1') {
                dx[i][j] = 1;
                dy[i][j] = 1;
                if (i > 0) dx[i][j] += dx[i - 1][j];
                if (j > 0) dy[i][j] += dy[i][j - 1];
            }

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (v[i][j] == '1') {
                int dz = i > 0 && j > 0 ? dp[i - 1][j - 1] : 0;
                dp[i][j] = min(dx[i][j] - 1, min(dy[i][j] - 1, dz)) + 1;
            }

    vector<int> res(n + 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int aux = dp[i][j];
            while (aux) {
                ++res[aux];
                --aux;
            }
        }

    #ifdef DEBUG
    print2(dp, 8, 8);    
    #endif
    for (int len = 2; len <= n; ++len)
        if (res[len] > 0)
            cout << len << " " << res[len] << endl;
        else
            break;

}
