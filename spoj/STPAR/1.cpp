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
        int x, cur = 1;
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            if (x == cur) {
                ++cur;
            } else if (!st.empty() && st.top() == cur) {
                while (!st.empty() && st.top() == cur) {
                    st.pop();
                    ++cur;
                }
            } else {
                st.push(x);
            }
        }
        while (!st.empty()) {
            if (st.top() == cur) {
                st.pop();
                ++cur;
            } else {
                break;
            }
        }
        cout << (st.empty() ? "yes" : "no") << endl;
    }
}
