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

int func(int x)
{
    if (x % 2 == 0) return x * 2;
    else return x * 2 - 1;
}

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int x, y;
        cin >> x >> y;
        if (x == y) cout << func(x) << endl;
        else if (x - y == 2) {
            int aux = func(x - 1);
            if (x % 2 == 0) ++aux;
            else --aux;
            cout << aux << endl;
        } else {
            cout << "No Number" << endl;
        }
    }
}
