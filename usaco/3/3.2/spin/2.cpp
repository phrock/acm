/*
  ID:   aphrodi1
  LANG: C++
  PROG: spin
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

ifstream fin("spin.in");
ofstream fout("spin.out");
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

int speed[5];
vector< pair<int, int> > wedge[5];

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    for (int i = 0; i < 5; ++i) {
        cin >> speed[i];
        int w;
        cin >> w;
        for (int j = 0; j < w; ++j) {
            int start, extend;
            cin >> start >> extend;
            wedge[i].push_back(make_pair(start, extend));
        }
    }

    for (int i = 0; i < 360; ++i) {
        bool ok = false;
        for (int pos = 0; pos < 360; ++pos) {
            bool ok2 = true;
            for (int j = 0; j < 5; ++j) {
                int cur = speed[j] * i % 360;
                bool ok3 = false;
                for (int k = 0; k < (int)(wedge[j]).size(); ++k) {
                    int start = (cur + wedge[j][k].first) % 360;
                    int end = (start + wedge[j][k].second) % 360;
                    if ((start <= end && pos >= start && pos <= end) ||
                        (start > end && (pos >= start || pos <= end))) {
                        ok3 = true;
                        break;
                    }
                }
                if (!ok3) {
                    ok2 = false;
                    break;
                }
            }
            if (ok2) {
                ok = true;
                break;
            }
        }
        if (ok) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "none" << endl;
}
