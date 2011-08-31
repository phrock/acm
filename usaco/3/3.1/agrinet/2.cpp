/*
  ID:   aphrodi1
  LANG: C++
  PROG: agrinet
*/

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

ifstream fin("agrinet.in");
ofstream fout("agrinet.out");
streambuf *cin_buf = cin.rdbuf();
streambuf *cout_buf = cout.rdbuf();

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

const int MAX = INT_MAX;

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;
    vector< vector<int> > g(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> g[i][j];
    set<pair<int, int> > st;
    vector<int> cost(n, MAX);
    cost[0] = 0;
    vector<int> visited(n);
    st.insert(make_pair(0, 0));

    int res = 0;
    while (!st.empty()) {
        pair<int, int> tp = *st.begin();
        st.erase(st.begin());
        int weight = tp.first, node = tp.second;
        res += weight;
        visited[node] = 1;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) continue;
            if ((cost[i] == MAX) || (g[node][i] < cost[i])) {
                if (cost[i] != MAX)
                    st.erase((st).find(make_pair(cost[i], i)));
                cost[i] = g[node][i];
                st.insert(make_pair(g[node][i], i));
            }
        }
    }

    cout << res << endl;
}
