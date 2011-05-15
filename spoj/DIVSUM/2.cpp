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
////////////////////////////////////////////////////////////////////////////////

const int MAX = 500005;
int a[MAX];
int main()
{
    memset(a, 0, sizeof(a));
    for (int i=1; i<MAX; ++i) {
        int j = i + i;
        while (j < MAX) a[j] += i, j += i;
    }
    int n, x;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        scanf("%d", &x);
        printf("%d\n", a[x]);
    }
}
