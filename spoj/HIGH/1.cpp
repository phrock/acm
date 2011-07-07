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

int inversion_pair(const vector<int> &v)
{
    int res = 0;
    for (int i = 0; i < (int)(v).size(); ++i)
        for (int j = i + 1; j < (int)(v).size(); ++j)
            if (v[i] > v[j])
                ++res;
    return res;
}

int determinant(const vector< vector<int> > &A)
{
    vector<int> v((int)(A).size());
    for (int i = 0; i < (int)(A).size(); ++i)
        v[i] = i;
    int res = 0;
    do {
        int aux = 1;
        for (int i = 0; i < (int)(A).size(); ++i)
            aux *= A[i][v[i]];
        res += (inversion_pair(v) % 2 == 0 ? 1 : -1) * aux;
    } while (next_permutation((v).begin(), (v).end()));
    return res;
}

int main()
{
    int ts;
    cin >> ts;
    for (int ti = 0; ti < ts; ++ti) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > g(n, vector<int>(n)), degree(n, vector<int>(n));
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            if (g[a][b]) continue;
            g[a][b] = g[b][a] = 1;
            ++degree[a][a], ++degree[b][b];
        }
        vector< vector<int> > kirchhoff(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                kirchhoff[i][j] = degree[i][j] - g[i][j];
        vector< vector<int> > aux(n - 1, vector<int>(n - 1));
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < n - 1; ++j)
                aux[i][j] = kirchhoff[i + 1][j + 1];
        cout << abs(determinant(aux)) << endl;
    }
}
