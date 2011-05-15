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


int a[500];

int main()
{
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        int n;
        cin >> n;
        a[0] = 1;
        int p = 1, aux = 0;
        for (int j = 2; j <= n; ++j) {
            for (int k = 0; k < p; ++k) aux += a[k] * j, a[k] = aux % 10, aux /= 10;
            while (aux) a[p++] = aux % 10, aux /= 10;
        }
        for (int j = p-1; j >= 0; --j) cout << a[j];
        cout << endl;
    }
}
