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
#include "/home/rock/program/acm/topcoder/libs/debug.cpp"
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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string res;
    for (int i = 0; i < n; ++i) {
        int tab[] = {1, 1, 1, 1};
        tab[s[2 * i] - 'A'] = tab[s[2 * i + 1] - 'A'] = 0;
        string aux;
        for (int j = 0; j < 4; ++j)
            if (tab[j]) aux += 'A' + j;
        if (i && aux[0] == res[(int)(res).size() - 1])
            swap(aux[0], aux[1]);
        res += aux;
    }
    cout << res << endl;
}
