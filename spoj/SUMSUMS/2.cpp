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

int power(int b, int e)
{
    if (e == 0) return 1;
    long long res = 0;
    if (e % 2) {
        res = b;
        res = res * power(b, e - 1) % MOD;
        return res;
    } else {
        res = power(b, e / 2);
        res = res * res % MOD;
        return res;
    }
    return (int)res;
}

int main()
{
    int n, t;
    cin >> n >> t;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum = (sum + a[i]) % MOD;
    }
    long long x = power(n - 1, t);
    x = (x + MOD + (t % 2 == 0 ? -1 : 1)) % MOD;
    while (x % n) x += MOD;
    x = x / n % MOD;
    x = (x * sum) % MOD;
    int k = t % 2 == 0 ? 1 : -1;
    for (int i = 0; i < n; ++i)
        cout << (x + k * a[i] + MOD) % MOD << endl;
}
