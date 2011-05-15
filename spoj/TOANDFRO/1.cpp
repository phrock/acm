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
#include "/home/rock/program/topcoder/libs/debug.cpp"
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
    int n;
    while (cin >> n && n) {
        string s;
        cin >> s;
        vector<string> v;
        for (int i = 0; i < (int)(s).size() / n; ++i) {
            string aux = s.substr(i * n, n);
            if (i % 2) reverse((aux).begin(), (aux).end());
            v.push_back(aux);
        }
        #ifdef DEBUG
        print(v);        
        #endif
        string res;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < (int)(s).size() / n; ++j)
                res += v[j][i];
        cout << res << endl;
    }
}
