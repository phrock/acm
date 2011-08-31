/*
  ID:   aphrodi1
  LANG: C++
  PROG: cowtour
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

ifstream fin("cowtour.in");
ofstream fout("cowtour.out");
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

const int MAX = INT_MAX / 2;
double x[150], y[150];

double euclidean_distance(int i, int j)
{
    return hypot(x[i] - x[j], y[i] - y[j]);
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
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];

    vector<string> g(n);
    for (int i = 0; i < n; ++i)
        cin >> g[i];
    
    vector<vector<double> > dist(n, vector<double>(n, MAX));
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (g[i][j] == '1')
                dist[i][j] = dist[j][i] = euclidean_distance(i, j);

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    double aux = 0;
    vector<double> diameter(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            if (i != j && dist[i][j] < MAX)
                diameter[i] = max(diameter[i], dist[i][j]);
        aux = max(aux, diameter[i]);
    }

    double res = MAX;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (i != j && dist[i][j] == MAX)
                res = max(min(res, euclidean_distance(i, j) + diameter[i] + diameter[j]), aux);

    cout << setiosflags(ios::fixed) << setprecision(6);
    cout << res << endl;
}
