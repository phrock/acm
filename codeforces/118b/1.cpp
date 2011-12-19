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

void func(int x, int n)
{
    for (int i = 0; i < n - x; ++i)
        cout << "  ";
    for (int i = 0; i < x; ++i)
        cout << i << " ";
    cout << x;
    for (int i = x - 1; i >= 0; --i)
        cout << " " << i;
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i <= n; ++i)
        func(i, n);
    for (int i = n - 1; i >= 0; --i)
        func(i, n);
}
