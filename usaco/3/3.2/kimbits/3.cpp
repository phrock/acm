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

void dfs(long long ones, long long pos, string &res)
{
    if (pos == 0) return;

    long long idx = 0;
    while (true) {
        long long cnt = 0;
        for (int i = 0; i <= ones; ++i)
            cnt += ncr[idx][i];
        if (cnt >= pos)
            break;
        ++idx;
    }

    long long cnt = 0;
    if (idx) {
        for (int i = 0; i <= ones; ++i)
            cnt += ncr[idx - 1][i];
        res[idx - 1] = '1';
    } else {
        cnt = 1;
    }
    dfs(ones - 1, pos - cnt, res);
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
        for (int j = 0; j <= i; ++j)
            ncr[i][j] = !j ? 1 : ncr[i-1][j-1] + ncr[i-1][j];

    long long N, L, I;
    cin >> N >> L >> I;
    string res;
    for (int i = 0; i < N; ++i)
        res += "0";
    dfs(L, I, res);
    reverse((res).begin(), (res).end());
    cout << res << endl;
}
