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
    string s;
    while (cin >> s && s != "*") {
        s = ' ' + s;
        bool ok = true;
        vector<int> v((int)(s).size());
        for (int i = 1; i < (int)(s).size(); ++i) {
            if (s[i] == 'Y') {
                v[i] = 1;
                for (int j = 1; j < i; ++j)
                    if (i % j == 0) {
                        if (s[j] == 'N') {
                            ok = false;
                            break;
                        } else {
                            v[j] = 0;
                        }
                    }
            } else {
                for (int j = 1; j < i; ++j)
                    for (int k = j; k < i; ++k)
                        if (j * k == i && s[j] == 'Y' && s[k] == 'Y')
                            ok = false;
            }
        }
        if (!ok) { cout << -1 << endl; continue; }
        long long res = 1;
        for (int i = 1; i < (int)(v).size(); ++i)
            if (v[i]) res *= i;
        cout << res << endl;
    }
}
