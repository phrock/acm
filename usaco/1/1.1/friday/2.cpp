/*
  ID:   aphrodi1
  LANG: C++
  PROG: friday
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

ifstream fin("friday.in");
ofstream fout("friday.out");
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

int leap_year(int n)
{
    return ((n % 400 == 0) || (n % 4 == 0 && n % 100 != 0)) ? 1 : 0;
}

int month[2][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
                    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    //////////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;
    vector<int> res(7);
    int cur = (1 + 13 - 1) % 7, next = cur;
    for (int i = 0; i < n; ++i) {
        int leap = leap_year(1900 + i);
        for (int j = 0; j < 12; ++j) {
            cur = next;
            ++res[cur];
            next = (cur + month[leap][j]) % 7;
        }
    }
    for (int i = 0; i < 7; ++i) {
        if (i) cout << " ";
        cout << res[(6 + i) % 7];
    }
    cout << endl;
}
