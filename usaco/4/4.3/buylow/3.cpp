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

string addString(string a, string b)
{
    string result;
    int ai = a.length() - 1;
    int bi = b.length() - 1;
    int carry = 0;
    while ((ai >= 0) || (bi >= 0)) {
	int x = 0;
	int y = 0;
	int z = 0;
	if (ai >= 0) x = a[ai] - '0';
	if (bi >= 0) y = b[bi] - '0';
	z = x + y + carry;
	carry = z / 10;
	int m = z % 10;
	result = (char)(m+'0') + result;
	if (ai >= 0) ai--;
	if (bi >= 0) bi--;
    }
    if (carry > 0) result = (char)(carry+'0') + result;

    return result;
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
    vector<int> v(n + 2), dp(n + 2);
    vector<string> cnt(n + 2);
    v[0] = INT_MAX;
    dp[0] = 0;
    cnt[0] = "1";
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    v[n + 1] = -1;
    for (int i = 1; i <= n + 1; ++i) {
        int m = 0, start = 0;
        for (int j = i - 1; j >= 0; --j)
            if (v[i] == v[j]) {
                start = j;
                break;
            }
        for (int j = start; j < i; ++j) {
            if (v[j] > v[i])
                m = max(m, dp[j]);
        }
        dp[i] = m + 1;
        for (int j = start; j < i; ++j)
            if (v[j] > v[i] && dp[j] == m)
                cnt[i] = addString(cnt[i], cnt[j]);
    }

    #ifdef DEBUG
    print(dp);
    print(cnt);
    #endif
    cout << dp[n + 1] - 1 << " " << cnt[n + 1] << endl;
}
