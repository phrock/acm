/*
  ID:   aphrodi1
  LANG: C++
  PROG: buylow
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

ifstream fin("buylow.in");
ofstream fout("buylow.out");
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
    vector<int> v(n + 1), dp(n + 1), cnt(n + 1);
    v[0] = INT_MAX;
    dp[0] = 0;
    cnt[0] = 1;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i) {
        int m = 0;
        for (int j = 0; j < i; ++j) {
            if (v[j] > v[i])
                m = max(m, dp[j]);
        }
        dp[i] = m + 1;
        set<int> st;
        for (int j = 0; j < i; ++j)
            if (v[j] > v[i] && dp[j] == m && !((st).find(v[j]) != (st).end())) {
                cnt[i] += cnt[j];
                st.insert(v[j]);
            }
    }

    #ifdef DEBUG
    print(dp);
    print(cnt);
    #endif
    int res = *max_element((dp).begin(), (dp).end());
    int res_cnt = 0;
    set<int> st;
    for (int i = 1; i <= n; ++i)
        if (dp[i] == res && !((st).find(v[i]) != (st).end())) {
            res_cnt += cnt[i];
            st.insert(v[i]);
        }
    cout << res << " " << res_cnt << endl;
}
