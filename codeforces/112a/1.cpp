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


int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < (int)(s1).size(); ++i)
        s1[i] = tolower(s1[i]);
    for (int i = 0; i < (int)(s2).size(); ++i)
        s2[i] = tolower(s2[i]);
    if (s1 < s2) cout << -1 << endl;
    else if (s1 > s2) cout << 1 << endl;
    else cout << 0 << endl;
}
