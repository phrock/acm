/*
  ID:   aphrodi1
  LANG: C++
  PROG: clocks
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

ifstream fin("clocks.in");
ofstream fout("clocks.out");
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

int back[1 << 20];
int path[1 << 20];
int found[1 << 20];

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    //////////////////////////////////////////////////////////////////////////////

    int x = 0;
    for (int i = 0; i < 9; ++i) {
        int aux;
        cin >> aux;
        aux = aux / 3 % 4;
        x |= aux << (i * 2);
    }
    found[x] = 1;
    string s[10] = {"", "ABDE", "ABC", "BCEF", "ADG", "BDEFH", "CFI", "DEGH", "GHI", "EFHI"};
    vector<int> v(10);
    for (int i = 1; i <= 9; ++i)
        for (int j = 0; j < (int)(s[i]).size(); ++j)
            v[i] += 1 << ((s[i][j] - 'A') * 2);
    queue<int> q;
    q.push(x);
    while (!q.empty()) {
        int ft = q.front();
        q.pop();
        if (!ft)
            break;
        for (int i = 1; i <= 9; ++i) {
            int y = ft;
            for (int j = 0; j < 10; ++j) {
                y = (((y & (3 << (j * 2))) + v[i]) & (3 << (j * 2))) |
                    (y & ~(3 << (j * 2)));
            }
            if (!found[y]) {
                q.push(y);
                found[y] = 1;
                back[y] = ft;
                path[y] = i;
            }
        }
    }
    int aux = 0;
    vector<int> res;
    while (aux != x) {
        res.push_back(path[aux]);
        aux = back[aux];
    }
    #ifdef DEBUG
    print(res);    
    #endif
    reverse((res).begin(), (res).end());
    for (int i = 0; i < (int)(res).size(); ++i) {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << endl;
}
        
