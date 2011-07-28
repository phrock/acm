/*
  ID:   aphrodi1
  LANG: C++
  PROG: milk3
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

ifstream fin("milk3.in");
ofstream fout("milk3.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();

/*******************************************************************************
 *                                                                             *
 *                  To see the world in a grain of sand,                       *
 *                  And a heaven in a wild flower;                             *
 *                  Hold infinity in the palm of your hand,                    *
 *                  And eternity in an hour.                                   *
 *                                                                             *
 ******************************************************************************/

int mem[25][25][25];
int a, b, c;

void dfs(int x, int y, int z, set<int> &st)
{
    mem[x][y][z] = 1;
    if (!x)
        st.insert(z);
    int next_x, next_y, next_z;
    next_x = x - min(x, b - y);
    next_y = y + min(x, b - y);
    next_z = z;
    if (!mem[next_x][next_y][next_z])
        dfs(next_x, next_y, next_z, st);

    next_x = x - min(x, c - z);
    next_y = y;
    next_z = z + min(x, c - z);
    if (!mem[next_x][next_y][next_z])
        dfs(next_x, next_y, next_z, st);

    next_x = x + min(a - x, y);
    next_y = y - min(a - x, y);
    next_z = z;
    if (!mem[next_x][next_y][next_z])
        dfs(next_x, next_y, next_z, st);

    next_x = x;
    next_y = y - min(c - z, y);
    next_z = z + min(c - z, y);
    if (!mem[next_x][next_y][next_z])
        dfs(next_x, next_y, next_z, st);
    
    next_x = x + min(a - x, z);
    next_y = y;
    next_z = z - min(a - x, z);
    if (!mem[next_x][next_y][next_z])
        dfs(next_x, next_y, next_z, st);
        
    next_x = x;
    next_y = y + min(b - y, z);
    next_z = z - min(b - y, z);
    if (!mem[next_x][next_y][next_z])
        dfs(next_x, next_y, next_z, st);
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    //////////////////////////////////////////////////////////////////////////////

    cin >> a >> b >> c;
    set<int> st;
    dfs(0, 0, c, st);
    vector<int> res((st).begin(), (st).end());
    for (int i = 0; i < (int)(res).size(); ++i) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << endl;
}
