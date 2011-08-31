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
    string s = "6789TJQKA";
    char trump;
    cin >> trump;
    string a, b;
    cin >> a >> b;
    if (a[1] == b[1]) {
        if (s.find(a[0]) > s.find(b[0]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    } else {
        if (a[1] == trump)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
