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
#include "/Users/Aphrodite/program/acm/lib/debug.cpp"
#endif

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

const int MAX = 100000;
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

bool isPrime(int x)
{
    if (x < MAX)
        return is_prime[x];
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0)
            return false;
    return true;
}

bool check(int x)
{
    for (int i = 0; i < prime_cnt; ++i) {
        // cout << prime[i] << " " << x / prime[i] <<  endl;
        if (x % prime[i] == 0 && isPrime(x / prime[i]))
            return true;
    }
    return false;
}

int main()
{
    create_prime();
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        cout << (check(x) ? "Yes" : "No") << endl;
    }
}
