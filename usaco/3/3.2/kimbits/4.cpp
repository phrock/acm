/*
  ID:   aphrodi1
  LANG: C++
  PROG: kimbits
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

ifstream fin("kimbits.in");
ofstream fout("kimbits.out");
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

const int MAX=50;
long long ncr[MAX][MAX];

void dfs(long long N, long long L, long long I, string &res)
{
    if (!N) return;
    if (ncr[N - 1][L] < I) {
        res += "1";
        dfs(N - 1, L - 1, I - ncr[N - 1][L], res);
    } else {
        res += "0";
        dfs(N - 1, L, I, res);
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

    memset(ncr, 0, sizeof(ncr));
    for (int i = 0; i < MAX; ++i)
        ncr[0][i] = ncr[i][0] = 1;
    for (int i = 1; i < MAX; ++i)
        for (int j = 1; j < MAX; ++j)
            ncr[i][j] = ncr[i-1][j-1] + ncr[i-1][j];

    long long N, L, I;
    cin >> N >> L >> I;
    string res;
    dfs(N, L, I, res);
    cout << res << endl;
}
