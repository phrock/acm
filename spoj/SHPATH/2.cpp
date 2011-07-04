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

vector< pair<int, int> > g[10005];
string city[10005];
map<string, int> mp;
int dist[10005];
char tmp[20];

int main()
{
    int T;
    scanf("%d", &T);
    for (int ti = 0; ti < T; ++ti) {
        int n;
        scanf("%d", &n);
        mp.clear();
        for (int i = 1; i <= n; ++i)
            g[i].clear();
        for (int i = 1; i <= n; ++i) {
            string name;
            scanf("%s", tmp);
            name = tmp;
            city[i] = name;
            mp[name] = i;
            int p;
            scanf("%d", &p);
            for (int j = 0; j < p; ++j) {
                int nr, cost;
                // cin >> nr >> cost;
                scanf("%d%d", &nr, &cost);
                g[i].push_back(make_pair(cost, nr));
            }
        }
        map<pair<int, int>, int> cache;
        int r;
        scanf("%d", &r);
        for (int i = 0; i < r; ++i) {
            string name1, name2;
            scanf("%s", tmp);
            name1 = tmp;
            scanf("%s", tmp);
            name2 = tmp;
            int idx1 = mp[name1], idx2 = mp[name2];
            if (idx1 == idx2) { cout << 0 << endl; continue; }
            if (idx1 > idx2) swap(idx1, idx2);
            if (((cache).find(make_pair(idx1, idx2)) != (cache).end())) {
                cout << cache[make_pair(idx1, idx2)] << endl;
                continue;
            }
            // for (int j = 1; j <= n; ++j)
            //     dist[j] = -1;
            map<int, long long> dist;
            dist[idx1] = 0;
            set<pair<long long, int> > st;
            for (int j = 0; j < (int)(g[idx1]).size(); ++j)
                st.insert(g[idx1][j]);
            while (!st.empty()) {
                pair<int, int> head = *st.begin();
                st.erase(st.begin());
                int node = head.second, cost = head.first;
                dist[node] = cost;
                cache[make_pair(min(idx1, node), max(idx1, node))] = cost;
                if (node == idx2) break;
                for (int j = 0; j < (int)(g[node]).size(); ++j) {
                    int node2 = g[node][j].second, cost2 = g[node][j].first;
                    if (((dist).find(node2) != (dist).end()) &&
                        dist[node] + cost2 < dist[node2])
                        st.erase(make_pair(dist[node2], node2));
                    st.insert(make_pair(dist[node] + cost2, node2));
                    dist[node2] = dist[node] + cost2;
                }
            }
            cout << dist[idx2] << endl;
        }
    }
}
