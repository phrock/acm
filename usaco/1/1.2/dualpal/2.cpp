/*
  ID:   aphrodi1
  LANG: C++
  PROG: dualpal
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

ifstream fin("dualpal.in");
ofstream fout("dualpal.out");
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

string func(int n, int base)
{
    string res;
    while (n) {
        int x = n % base;
        n /= base;
        if (x < 10)
            res = char('0' + x) + res;
        else
            res = char('A' + x - 10) + res;
    }
    return res;
}

bool check(int n, int base)
{
    string s = func(n, base), s2 = s;
    reverse((s2).begin(), (s2).end());
    return s == s2;
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    //////////////////////////////////////////////////////////////////////////////

    int n, s;
    cin >> n >> s;
    while (n) {
        ++s;
        int cnt = 0;
        for (int i = 2; i <= 10; ++i)
            if (check(s, i)) {
                ++cnt;
                if (cnt == 2) break;
            }
        if (cnt == 2) {
            --n;
            cout << s << endl;
        }
    }
}
