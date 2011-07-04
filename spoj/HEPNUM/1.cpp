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
    string a, b;
    while (cin >> a >> b && a != "*") {
        while (a[0] == '0' && (int)(a).size() > 1) a = a.substr(1);
        while (b[0] == '0' && (int)(b).size() > 1) b = b.substr(1);
        if ((int)(a).size() > (int)(b).size()) {
            cout << ">" << endl;
        } else if ((int)(a).size() < (int)(b).size()) {
            cout << "<" << endl;
        } else {
            bool eq = true;
            for (int i = 0; i < (int)(a).size(); ++i)
                if (a[i] != b[i]) {
                    eq = false;
                    cout << (a[i] > b[i] ? ">" : "<") << endl;
                    break;
                }
            if (eq) cout << "=" << endl;
        }
    }
}
