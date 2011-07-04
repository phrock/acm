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
    int n;
    while (cin >> n && n) {
        vector<int> v(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        int idx = 0, cur = 1;
        stack<int> st;
        while (idx != n) {
            if (v[idx] == cur) {
                ++idx;
                ++cur;
                continue;
            }
            if (!st.empty() && st.top() == cur) {
                st.pop();
                ++cur;
                continue;
            }
            st.push(v[idx++]);
        }
        while (!st.empty() && st.top() == cur) {
            st.pop();
            ++cur;
        }
        cout << (st.empty() ? "yes" : "no") << endl;
    }
}
