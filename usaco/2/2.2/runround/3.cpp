/*
  ID:   aphrodi1
  LANG: C++
  PROG: runround
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

ifstream fin("runround.in");
ofstream fout("runround.out");
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

int hold[10];
long long n;
long long res;
bool ok;

bool check(long long x)
{
    if (!x) return false;
    vector<int> v;
    while (x) {
        v.push_back(x % 10);
        x /= 10;
    }
    reverse((v).begin(), (v).end());

    vector<int> aux(10);
    for (int i = 0, idx = 0; i < (int)(v).size(); ++i) {
        idx = (idx + v[idx]) % (int)(v).size();
        int val = v[idx];
        if (aux[val]) return false;
        aux[val] = 1;
    }
    return true;
}

void dfs(long long x, long long y)
{
    // cout << x << endl;
    if (ok || x > y) return;
    if (x > n && check(x)) {
        res = x;
        ok = true;
        return;
    }
    for (int i = 1; i <= 9; ++i)
        if (!hold[i]) {
            long long next = x * 10 + i;
            hold[i] = 1;
            dfs(next, y);
            hold[i] = 0;
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

    cin >> n;
    res = LLONG_MAX;
    ok = false;
    long long x = 10, start = 0;
    while (!ok) {
        // hold[1] = 1;
        dfs(start, x);
        // hold[1] = 0;
        x *= 10;
        // start 
    }
    cout << res << endl;
}
