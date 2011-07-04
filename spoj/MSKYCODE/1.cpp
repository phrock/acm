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

const int MAX = 10000;
bitset<MAX> is_prime;
int prime[MAX];
int prime_cnt;

void create_prime()
{
    is_prime.set();
    is_prime[0] = is_prime[1] = 0;
    for (long long i = 2; i * i < MAX; ++i)
        if (is_prime[i])
            for (long long j = i * i; j < MAX; j += i)
                is_prime[j] = 0;
    prime_cnt = 0;
    for (int i = 0; i < MAX; ++i)
        if (is_prime[i])
            prime[prime_cnt++] = i;
}

long long nc4[10005];

void create_nc4()
{
    for (int i = 0; i < 4; ++i)
        nc4[i] = 0;
    nc4[4] = 1;
    for (int i = 5; i <= 10000; ++i)
        nc4[i] = nc4[i - 1] * i / (i - 4);
}

int a[100005], m;

long long func(int prod, int idx)
{
    int cnt = 0;
    for (int i = prod; i <= m; i += prod)
        cnt += a[i];
    long long res = nc4[cnt];
    if (cnt >= 4) {
        for (int i = idx; i < prime_cnt; ++i) {
            if (prime[i] * prod * 4 > m) break;
            res -= func(prime[i] * prod, i + 1);
        }
    }
    return res;
}

int main()
{
    create_prime();
    create_nc4();
    int n;
    while (cin >> n) {
        memset(a, 0, sizeof(a));
        m = 0;
        int x;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &x);
            ++a[x];
            m = max(m, x);
        }
        long long res = func(1, 0);
        cout << res << endl;
    }
}
