/*
  ID:   aphrodi1
  LANG: C++
  PROG: butter
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

ifstream fin("butter.in");
ofstream fout("butter.out");
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

int N, P, C;
int has_cow[1000];
vector<pair<int, int> > g[1000];
int visited[1000];

int prim(int x)
{
    memset(visited, 0, sizeof(visited));
    set<pair<int, int> > st;
    st.insert(make_pair(0, x));

    int res = 0, rest = N;
    while (!st.empty()) {
        pair<int, int> tp = *st.begin();
        st.erase(st.begin());
        int node = tp.second, cost = tp.first;
        if (has_cow[node]) {
            res += has_cow[node] * cost;
            rest -= has_cow[node];
        }
        for (int i = 0; i < (int)(g[node]).size(); ++i) {
            int node2 = g[node][i].first, cost2 = cost + g[node][i].second;
            if (node2 == x) continue;
            if (!visited[node2]) {
                st.insert(make_pair(cost2, node2));
                visited[node2] = cost2;
            } else if (cost2 < visited[node2]) {
                st.erase(st.find(make_pair(visited[node2], node2)));
                st.insert(make_pair(cost2, node2));
                visited[node2] = cost2;
            }
        }
    }

    return !rest ? res : INT_MAX;
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    cin >> N >> P >> C;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        ++has_cow[x];
    }
    for (int i = 0; i < C; ++i) {
        int a, b, dist;
        cin >> a >> b >> dist;
        g[a].push_back(make_pair(b, dist));
        g[b].push_back(make_pair(a, dist));
    }

    int res = INT_MAX;
    for (int i = 1; i <= 800; ++i)
        res = min(res, prim(i));

    cout << res << endl;
}
