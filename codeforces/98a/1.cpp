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

// all the permutations are the same cube
vector< vector<int> > cube_same_permutation()
{
    int a[6][6] = {{0, 1, 2, 3, 4, 5}, {1, 0, 4, 5, 2, 3}, {2, 0, 1, 5, 3, 4},
                   {3, 0, 2, 5, 4, 1}, {4, 0, 3, 5, 1, 2}, {5, 1, 4, 3, 2, 0}};
    vector< vector<int> > res;
    for (int i = 0; i < 6; ++i) {
        vector<int> aux(a[i], a[i] + 6);
        for (int j = 0; j < 4; ++j) {
            rotate(aux.begin() + 1, aux.begin() + 2, aux.begin() + 5);
            res.push_back(aux);
        }
    }
    return res;
}

int main()
{
    vector< vector<int> > p = cube_same_permutation();
    string s;
    cin >> s;
    set<string> st;
    sort((s).begin(), (s).end());
    do {
        bool ok = true;
        for (int i = 0; i < (int)(p).size(); ++i) {
            string aux = s;
            for (int j = 0; j < 6; ++j)
                aux[j] = s[p[i][j]];
            if (((st).find(aux) != (st).end())) {
                ok = false;
                break;
            }
        }
        if (ok) st.insert(s);
    } while (next_permutation((s).begin(), (s).end()));
    cout << (int)(st).size() << endl;
}
