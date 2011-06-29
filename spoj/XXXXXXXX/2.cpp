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

const int MAX = 50005;
int a[MAX], c[MAX];
set<int> st[MAX];

int lowbit(int x)
{
    // return x & (x ^ (x - 1));
    return 1 << __builtin_ctz(x);
}

// update value of a[idx] to val, total number is n, base idx = 1;
void update(int idx, int val, int n)
{
    int orig_idx = idx, orig = a[idx];
    bool found_orig = false;
    idx -= lowbit(idx);
    while (idx) {
        if (a[idx]
        
    while (idx <= n) {
        c[idx] = c[idx] - a[idx] + val;
        idx += lowbit(idx);
    }
    a[orig_idx] = val;
}

// the sum of a[1...k]
long long query_sum(int k)
{
    long long res = 0;
    while (k) {
        res += c[k];
        k -= lowbit(k);
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int tmp;
        scanf("%d", &tmp);
        update(i, tmp, n);
    }
    // for (int i = 1; i <= n; ++i)
    //     update(i, a[i], n);
    #ifdef DEBUG
    print(a, n + 1);    
    print(c, n + 1);    
    #endif
    int Q;
    scanf("%d", &Q);
    char op[2];
    int a, b;
    for (int qi = 0; qi < Q; ++qi) {
        scanf("%s%d%d", op, &a, &b);
        if (op[0] == 'Q') {
            if (a > b) swap(a, b);
            printf("%lld\n", query_sum(b) - query_sum(a - 1));
        } else {
            update(a, b, n);
        }
    }
}
