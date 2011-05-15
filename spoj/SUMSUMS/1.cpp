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

int a[50005];
const int MOD = 98765431;

int main()
{
    int n, t;
    cin >> n >> t;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    for (int ti = 0; ti < t; ++ti) {
        int aux = 0;
        for (int i = 0; i < n; ++i) {
            a[i] = (sum - a[i] + MOD) % MOD;
            aux = (aux + a[i]) % MOD;
        }
        sum = aux;
        #ifdef DEBUG
        cout << sum << endl;
        print(a, n);        
        #endif
    }
    for (int i = 0; i < n; ++i)
        cout << a[i] << endl;
}
