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

string dec2ter(long long x)
{
    string res;
    while (x) {
        res += '0' + x % 3;
        x /= 3;
    }
    return res;
}

long long ter2dec(string s)
{
    long long base = 1;
    long long res = 0;
    for (int i = 0; i < (int)(s).size(); ++i) {
        res += (s[i] - '0') * base;
        base *= 3;
    }
    return res;
}

int main()
{
    long long a, c;
    cin >> a >> c;
    string a2 = dec2ter(a), c2 = dec2ter(c);
    int m = max((int)(a2).size(), (int)(c2).size());
    for (int i = 0; i < m - (int)(a2).size(); ++i)
        a2 += '0';
    for (int i = 0; i < m - (int)(c2).size(); ++i)
        c2 += '0';
    string b2;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < 3; ++j)
            if ((j + (a2[i] - '0')) % 3 == c2[i] - '0') {
                b2 += '0' + j;
                break;
            }
    cout << ter2dec(b2) << endl;
}
