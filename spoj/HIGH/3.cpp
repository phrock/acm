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

const int MAX = 12;
int found[1 << MAX];
long long determinant[1 << MAX];

long long find_determinant(const vector< vector<long long> > &A, int bitmap)
{
    if (found[bitmap])
        return determinant[bitmap];
    if (!bitmap) {
        found[bitmap] = 1;
        return determinant[bitmap] = 1;
    }

    int col = (int)(A).size(), aux = bitmap;
    while (aux) {
        col -= aux % 2;
        aux >>= 1;
    }
    long long res = 0, sign = 1;
    for (int row = 0, b = 1; row < (int)(A).size(); ++row, b <<= 1)
        if (bitmap & b) {
            res += sign * A[row][col] * find_determinant(A, bitmap ^ b);
            sign = -sign;
        }
    found[bitmap] = 1;
    return determinant[bitmap] = res;
}

int main()
{
    int ts;
    cin >> ts;
    for (int ti = 0; ti < ts; ++ti) {
        memset(found, 0, sizeof(found));
        memset(determinant, 0, sizeof(determinant));
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
        vector< vector<long long> > aux(n - 1, vector<long long>(n - 1));
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < n - 1; ++j)
                aux[i][j] = kirchhoff[i + 1][j + 1];
#ifdef DEBUG
        print2(aux);
#endif
        cout << abs(find_determinant(aux, (1 << (int)(aux).size()) - 1)) << endl;
    }
}
