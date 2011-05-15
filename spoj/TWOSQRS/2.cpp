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

const int MAX = 1000000;
bitset<MAX> is_prime;
int prime[MAX];
int prime_cnt;

void create_prime()
{
    is_prime.reset();
    is_prime.flip();
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

bool check(long long n)
{
    for (int i = 0; i < prime_cnt; ++i) {
        if (prime[i] * prime[i] > n) break;
        int cnt = 0;
        while (n % prime[i] == 0) {
            n /= prime[i];
            ++cnt;
        }
        if (prime[i] % 4 == 3 && cnt % 2) return false;
    }
    if (n % 4 == 3) return false;
    return true;
}

int main()
{
    create_prime();
    int T;
    cin >> T;

    for (int ti = 0; ti < T; ++ti) {
        long long n;
        cin >> n;
        cout << (check(n) ? "Yes" : "No") << endl;
    }
}
