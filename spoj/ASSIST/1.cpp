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

const int MAX = 100000;
int a[MAX], b[MAX];
int res[MAX];

int main()
{
    int n = MAX, start = 2;
    for (int i = 0; i < n; ++i)
        a[i] = start++;
 
    for (int i = 1; i <= 3005; ++i) {
        res[i] = a[0];
        for (int j = 0; j < n; j += res[i])
            a[j] = 0;
        int idx = 0;
        for (int j = 0; j < n; ++j)
            if (a[j]) a[idx++] = a[j];
        n = idx;
        #ifdef DEBUG
        cout << i<<": "<<res[i]<<endl;
        print(a, 50);        
        #endif
    }

    int ask;
    while (cin >> ask && ask)
        cout << res[ask] << endl;
}
