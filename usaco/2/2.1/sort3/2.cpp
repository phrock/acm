/*
  ID:   aphrodi1
  LANG: C++
  PROG: sort3
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

ifstream fin("sort3.in");
ofstream fout("sort3.out");
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
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        --v[i];
    }
    vector<int> cnt(3);
    for (int i = 0; i < n; ++i)
        ++cnt[v[i]];
    vector< vector<int> > place(3, vector<int>(3));
    for (int i = 0; i < n; ++i)
        if (i < cnt[0])
            ++place[0][v[i]];
        else if (i < cnt[0] + cnt[1])
            ++place[1][v[i]];
        else
            ++place[2][v[i]];

    int res = 0;
    int aux = min(place[0][1], place[1][0]);
    res += aux;
    place[0][1] -= aux;
    aux = min(place[0][2], place[2][0]);
    res += aux;
    place[0][2] -= aux;
    aux = min(place[1][2], place[2][1]);
    res += aux;

    aux = max(place[0][1], place[0][2]);
    res += 2 * aux;

    cout << res << endl;
}
