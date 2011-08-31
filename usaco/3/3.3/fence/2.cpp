/*
  ID:   aphrodi1
  LANG: C++
  PROG: fence
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

ifstream fin("fence.in");
ofstream fout("fence.out");
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

void find_path(int node, vector< vector<int> > &g, vector<int> &path)
{
    for (int i = 0; i < (int)(g[node]).size(); ++i)
        if (g[node][i]) {
            --g[node][i];
            --g[i][node];
            find_path(i, g, path);
        }
    path.push_back(node);
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

    int F;
    cin >> F;
    vector<int> v(501);
    vector< vector<int> > g(501, vector<int>(501));
    for (int i = 0; i < F; ++i) {
        int a, b;
        cin >> a >> b;
        ++v[a];
        ++v[b];
        ++g[a][b];
        ++g[b][a];
    }
    int start = 1;
    for (int i = 1; i < (int)(v).size(); ++i)
        if (v[i] % 2 == 1) {
            start = i;
            break;
        }

    vector<int> path;
    find_path(start, g, path);
    #ifdef DEBUG
    print(path);    
    #endif
    reverse((path).begin(), (path).end());
    for (int i = 0; i < (int)(path).size(); ++i)
        cout << path[i] << endl;
}
