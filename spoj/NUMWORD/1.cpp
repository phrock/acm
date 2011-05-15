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


int main()
{
    map<string, int> mm;
    mm["zero"] = 0;
    mm["one"] = 1;
    mm["two"] = 2;
    mm["three"] = 3;
    mm["four"] = 4;
    mm["five"] = 5;
    mm["six"] = 6;
    mm["seven"] = 7;
    mm["eight"] = 8;
    mm["nine"] = 9;
    mm["ten"] = 10;
    mm["eleven"] = 11;
    mm["twelve"] = 12;
    mm["thirteen"] = 13;
    mm["fourteen"] = 14;
    mm["fifteen"] = 15;
    mm["sixteen"] = 16;
    mm["seventeen"] = 17;
    mm["eighteen"] = 18;
    mm["nineteen"] = 19;
    mm["twenty"] = 20;
    mm["thirty"] = 30;
    mm["forty"] = 40;
    mm["fifty"] = 50;
    mm["sixty"] = 60;
    mm["seventy"] = 70;
    mm["eighty"] = 80;
    mm["ninety"] = 90;

    int res = 0, aux = 0;
    string s;
    while (cin >> s) {
        if (s == "and") continue;
        if (s == "hundred") { res += aux * 100; aux = 0; continue; }
        if (s == "thousand") { res += aux * 1000; aux = 0; continue; }
        aux += mm[s];
    }
    res += aux;
    cout << res << endl;
}
