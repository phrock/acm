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

// long double determinant(vector<vector<long double> > &A)
// {
//     long double res = 1;
//     for (int i = 0; i < (int)(A).size(); ++i)
//         for (int j = i + 1; j < (int)(A).size(); ++j)
//             for (int k = (int)(A).size() - 1; k >= 0; --k)
//                 A[j][k] = A[j][k] - A[i][k] * A[j][i] / A[i][i];
//     for (int i = 0; i < (int)(A).size(); ++i)
//         res *= A[i][i];
//     return res;
// }
long double determinant(vector<vector<long double> > &A)
{
    long double res = 1;
    for (int k = 0; k < (int)(A).size(); ++k) {
        res *= A[k][k];
        for (int i = k + 1; i < (int)(A).size(); ++i)
            if (A[i][k] != 0) {
                long double zoom = -A[k][k] / A[i][k];
                res /= zoom;
                for (int j = k; j < (int)(A).size(); ++j)
                    A[i][j] = A[k][j] + A[i][j] * zoom;
            }
    }
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
        vector< vector<long double> > aux(n - 1, vector<long double>(n - 1));
        for (int i = 0; i < n - 1; ++i)
            for (int j = 0; j < n - 1; ++j)
                aux[i][j] = kirchhoff[i + 1][j + 1];

        cout << abs(round(determinant(aux))) << endl;
    }
}
