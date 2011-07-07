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
    map<string, string> mp;
    mp["8"] = "ate";
    mp["w8"] = "wait";
    mp["gr8"] = "great";
    mp["4"] = "for";
    mp["b4"] = "before";
    int ts;
    cin >> ts;
    string s;
    getline(cin, s);
    for (int ti = 0; ti < ts; ++ti) {
        getline(cin, s);
        string res, aux;
        for (int i = 0; i < (int)(s).size(); ++i) {
            if (s[i] == ' ') {
                if (((mp).find(aux) != (mp).end()))
                    res += mp[aux];
                else
                    res += aux;
                aux.clear();
                res += s[i];
            } else {
                aux += s[i];
            }
        }
        if (((mp).find(aux) != (mp).end()))
            res += mp[aux];
        else
            res += aux;
        cout << res << endl;
    }
}
