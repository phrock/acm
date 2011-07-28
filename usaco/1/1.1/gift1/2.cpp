/*
  ID:   aphrodi1
  LANG: C++
  PROG: gift1
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

ifstream fin("gift1.in");
ofstream fout("gift1.out");
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
    vector<string> name(n);
    map<string, int> res;
    for (int i = 0; i < n; ++i)
        cin >> name[i];
    for (int i = 0; i < n; ++i) {
        string s;
        int initial, k;
        cin >> s >> initial >> k;
        for (int j = 0; j < k; ++j) {
            string tmp;
            cin >> tmp;
            res[tmp] += initial / k;
            res[s] -= initial / k;
        }
    }
    for (int i = 0; i < n; ++i)
        cout << name[i] << " " << res[name[i]] << endl;
}
