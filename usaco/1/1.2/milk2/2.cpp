/*
  ID:   aphrodi1
  LANG: C++
  PROG: milk2
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

ifstream fin("milk2.in");
ofstream fout("milk2.out");
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
    //////////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;
    vector< pair<int, int> > v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i].first >> v[i].second;
    sort((v).begin(), (v).end());
    int start = v[0].first, end = v[0].second;
    int continuous_time = 0, idle_time = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i].first <= end) {
            end = max(end, v[i].second);
            continuous_time = max(continuous_time, end - start);
        } else {
            idle_time = max(idle_time, v[i].first - end);
            start = v[i].first;
            end = v[i].second;
            continuous_time = max(continuous_time, end - start);
        }
    }
    cout << continuous_time << " " << idle_time << endl;
}
