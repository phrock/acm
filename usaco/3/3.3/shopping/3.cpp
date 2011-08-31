/*
  ID:   aphrodi1
  LANG: C++
  PROG: shopping
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

ifstream fin("shopping.in");
ofstream fout("shopping.out");
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


int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int s;
    cin >> s;
    vector<vector< pair<int, int> > > v(s);
    vector<int> vp(s);
    for (int i = 0; i < s; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int code, k;
            cin >> code >> k;
            v[i].push_back(make_pair(code, k));
        }
        cin >> vp[i];
    }
    int n;
    cin >> n;
    map<int, int> mp;
    vector<int> need_code(5), need_quantity(5), unique_price(5);
    for (int i = 0; i < n; ++i) {
        cin >> need_code[i] >> need_quantity[i] >> unique_price[i];
        mp[need_code[i]] = i;
    }

    int sum[6][6][6][6][6];
    memset(sum, 0, sizeof(sum));
    for (int i1 = 0; i1 <= need_quantity[0]; ++i1)
        for (int i2 = 0; i2 <= need_quantity[1]; ++i2)
            for (int i3 = 0; i3 <= need_quantity[2]; ++i3)
                for (int i4 = 0; i4 <= need_quantity[3]; ++i4)
                    for (int i5 = 0; i5 <= need_quantity[4]; ++i5) {
                        sum[i1][i2][i3][i4][i5] = i1 * unique_price[0] + i2 * unique_price[1] + i3 * unique_price[2] + i4 * unique_price[3] + i5 * unique_price[4];
                        for (int j = 0; j < (int)(v).size(); ++j) {
                            vector<int> q(5);
                            q[0] = i1;
                            q[1] = i2;
                            q[2] = i3;
                            q[3] = i4;
                            q[4] = i5;
                            bool ok = true;
                            for (int k = 0; k < (int)(v[j]).size(); ++k) {
                                int vc = v[j][k].first, vk = v[j][k].second;
                                if (!((mp).find(vc) != (mp).end()) ||
                                    vk > q[mp[vc]]) {
                                    ok = false;
                                    break;
                                } else {
                                    q[mp[vc]] -= vk;
                                }
                            }
                            if (ok) {
                                sum[i1][i2][i3][i4][i5] = min(sum[i1][i2][i3][i4][i5], sum[q[0]][q[1]][q[2]][q[3]][q[4]] + vp[j]);
                            }
                        }
                    }
    cout << sum[need_quantity[0]][need_quantity[1]][need_quantity[2]][need_quantity[3]][need_quantity[4]] << endl;
                        
}
