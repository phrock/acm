/*
  ID:   aphrodi1
  LANG: C++
  PROG: fence6
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

ifstream fin("fence6.in");
ofstream fout("fence6.out");
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

int min_circle(const vector< vector<int> > &g)
{
    vector< vector<int> > dist = g;
    int res = INT_MAX;
    int n = (int)(g).size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < k; ++i)
            for (int j = 0; j < i; ++j)
                if (dist[i][j] != INT_MAX && g[i][k] != INT_MAX && g[k][j] != INT_MAX)
                    res = min(res, dist[i][j] + g[i][k] + g[k][j]);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    }
    return res;
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

    int n;
    int a[105][2];
    cin >> n;
    memset(a, -1, sizeof(a));
    vector< vector<pair<int, int> > > g; // pair<node, length>
    vector< pair<int, int> > fence;
    for (int i = 0; i < n; ++i) {
        int x, len, n1, n2;
        cin >> x >> len >> n1 >> n2;
        vector<int> tmp1(n1), tmp2(n2);
        for (int j = 0; j < n1; ++j)
            cin >> tmp1[j];
        for (int j = 0; j < n2; ++j)
            cin >> tmp2[j];
        if (a[x][0] == -1) {
            int node1 = (int)(g).size(), node2 = node1 + 1;
            a[x][0] = node1;
            a[x][1] = node2;
            fence.push_back(make_pair(min(node1, node2), max(node1, node2)));
            vector< pair<int, int> > v;
            v.push_back(make_pair(node2, len));
            g.push_back(v);
            v.clear();
            v.push_back(make_pair(node1, len));
            g.push_back(v);
            for (int j = 0; j < n1; ++j)
                if (a[tmp1[j]][0] == -1)
                    a[tmp1[j]][0] = node1;
                else if (a[tmp1[j]][1] == -1)
                    a[tmp1[j]][1] = node1;
            for (int j = 0; j < n2; ++j)
                if (a[tmp2[j]][0] == -1)
                    a[tmp2[j]][0] = node2;
                else if (a[tmp2[j]][1] == -1)
                    a[tmp2[j]][1] = node2;
        } else if (a[x][1] == -1) {
            int node1 = (int)(g).size(), node2 = a[x][0];
            fence.push_back(make_pair(min(node1, node2), max(node1, node2)));
            a[x][1] = node1;
            g[node2].push_back(make_pair(node1, len));
            vector< pair<int, int> > v;
            v.push_back(make_pair(node2, len));
            g.push_back(v);
            for (int j = 0; j < n1; ++j)
                if (a[tmp1[j]][0] == -1)
                    a[tmp1[j]][0] = node1;
                else if (a[tmp1[j]][1] == -1 && a[tmp1[j]][0] != node2)
                    a[tmp1[j]][1] = node1;
            for (int j = 0; j < n2; ++j)
                if (a[tmp2[j]][0] == -1)
                    a[tmp2[j]][0] = node1;
                else if (a[tmp2[j]][1] == -1 && a[tmp2[j]][0] != node2)
                    a[tmp2[j]][1] = node1;
        } else {
            int node1 = a[x][0], node2 = a[x][1];
            fence.push_back(make_pair(min(node1, node2), max(node1, node2)));
            g[node1].push_back(make_pair(node2, len));
            g[node2].push_back(make_pair(node1, len));
        }
    }
    sort((fence).begin(), (fence).end()), (fence).erase(unique((fence).begin(), (fence).end()), (fence).end());

    #ifdef DEBUG
    cout << (int)(fence).size() << endl;
    printp(fence);
    cout << (int)(g).size() << endl;
    for (int i = 0; i < (int)(g).size(); ++i) {
        cout << i << endl;
        printp(g[i]);
    }
    #endif

    int nodes = (int)(g).size();
    vector< vector<int> > g2(nodes, vector<int>(nodes, INT_MAX));
    for (int i = 0; i < (int)(g).size(); ++i)
        for (int j = 0; j < (int)(g[i]).size(); ++j)
            g2[i][g[i][j].first] = g[i][j].second;

    #ifdef DEBUG
    print2(g2);
    #endif

    cout << min_circle(g2) << endl;
}
