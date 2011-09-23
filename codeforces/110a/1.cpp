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

bool is_lucky(int n)
{
    if (!n) return false;
    while (n) {
        if (n % 10 != 4 && n % 10 != 7)
            return false;
        n /= 10;
    }
    return true;
}

int main()
{
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < (int)(s).size(); ++i)
        if (s[i] == '4' || s[i] == '7')
            ++cnt;
    #ifdef DEBUG
    cout << cnt << endl;    
    #endif
    cout << (is_lucky(cnt) ? "YES" : "NO") << endl;
}
