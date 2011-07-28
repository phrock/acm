/*
  ID:   aphrodi1
  LANG: C++
  PROG: crypt1
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

ifstream fin("crypt1.in");
ofstream fout("crypt1.out");
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

vector<int> tab(10);

bool check(int n)
{
    while (n) {
        if (!tab[n % 10])
            return false;
        n /= 10;
    }
    return true;
}

void dfs(vector<int> &aux, int cur, const vector<int> &v, int &res)
{
    if (cur == 5) {
        ++res;
        #ifdef DEBUG
        print(aux);        
        #endif
        return;
    }
    switch (cur) {
    case 0:
        for (int i = 0; i < (int)(v).size(); ++i) {
            int orig = aux[0];
            aux[0] = v[i];
            dfs(aux, cur + 1, v, res);
            aux[0] = orig;
        }
        break;
    case 1:
        for (int i = 0; i < (int)(v).size(); ++i) {
            int orig = aux[1];
            aux[1] = v[i];
            if (tab[aux[0] * aux[1] % 10])
                dfs(aux, cur + 1, v, res);
            aux[1] = orig;
        }
        break;
    case 2:
        for (int i = 0; i < (int)(v).size(); ++i) {
            int orig = aux[2];
            aux[2] = v[i];
            if (tab[(aux[1] * aux[2] + aux[0] * aux[1] / 10) % 10])
                dfs(aux, cur + 1, v, res);
            aux[2] = orig;
        }
        break;
    case 3:
        for (int i = 0; i < (int)(v).size(); ++i) {
            int orig = aux[3];
            aux[3] = v[i];
            if (tab[aux[0] * aux[3] % 10] &&
                tab[(aux[2] * aux[3] + aux[0] * aux[3] / 10) % 10] &&
                tab[(aux[0] * aux[3] + aux[1] * aux[2] + aux[0] * aux[1] / 10) % 10])
                dfs(aux, cur + 1, v, res);
            aux[3] = orig;
        }
        break;
    case 4:
        for (int i = 0; i < (int)(v).size(); ++i) {
            int orig = aux[4];
            aux[4] = v[i];
            int a = aux[4] * 100 + aux[2] * 10 + aux[0];
            int b = aux[3] * 10 + aux[1];
            if (a * aux[1] < 1000 && a * aux[3] < 1000 && a * b < 10000 &&
                check(a * aux[1]) && check(a * aux[3]) && check(a * b))
                dfs(aux, cur + 1, v, res);
            aux[4] = orig;
        }
        break;
    }
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

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    sort((v).begin(), (v).end()), (v).erase(unique((v).begin(), (v).end()), (v).end());
    for (int i = 0; i < (int)(v).size(); ++i)
        tab[v[i]] = 1;

    int res = 0;
    vector<int> aux(5);
    dfs(aux, 0, v, res);
    cout << res << endl;
}
