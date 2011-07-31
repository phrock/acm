/*
  ID:   aphrodi1
  LANG: C++
  PROG: frac1
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

ifstream fin("frac1.in");
ofstream fout("frac1.out");
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

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.first * b.second < a.second * b.first;
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
    set<pair<int, int> > st;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= i; ++j) {
            int g = __gcd(i, j);
            st.insert(make_pair(j / g, i / g));
        }
    vector< pair<int, int> > res((st).begin(), (st).end());
    sort((res).begin(), (res).end(), cmp);
    for (int i = 0; i < (int)(res).size(); ++i)
        cout << res[i].first << "/" << res[i].second << endl;
}
