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

int n, m, k;
string s, aux, res;
set<string> st;

void dfs(int cur)
{
    cout << cur << " " << aux << endl;
    if (!res.empty()) return;
    if (((st).find(aux) == (st).end())) {
        res = aux;
        return;
    }
    if (aux[cur] - 'a' + 1 < k) {
        ++aux[cur];
        dfs(cur);
        --aux[cur];
    }
    if (cur + 1 < m) {
        // ++aux[cur + 1];
        dfs(cur + 1);
        // --aux[cur + 1];
    }
}

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        cin >> n >> m >> k >> s;
        st.clear();
        for (int i = 0; i + m <= (int)(s).size(); ++i) {
            st.insert(s.substr(i, m));
        }
        res = "";
        aux = string(m, 'a');
        dfs(0);
        cout << res << endl;
    }
}
