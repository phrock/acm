/*
  ID:   aphrodi1
  LANG: C++
  PROG: nocows
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

ifstream fin("nocows.in");
ofstream fout("nocows.out");
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

const int MOD = 9901;
int dp[200][100];

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)
        dp[1][i] = 1;
    for (int i = 3; i <= n; i += 2)
        for (int j = 1; j <= k; ++j)
            for (int left = 1; left <= i - 2; left += 2)
                dp[i][j] = (dp[i][j] + dp[left][j - 1] * dp[i - 1 - left][j - 1]) % MOD;
    cout << (dp[n][k] - dp[n][k - 1] + MOD) % MOD << endl;
}
