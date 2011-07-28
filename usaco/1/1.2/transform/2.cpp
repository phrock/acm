/*
  ID:   aphrodi1
  LANG: C++
  PROG: transform
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

ifstream fin("transform.in");
ofstream fout("transform.out");
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

vector<string> rotate_clockwise(const vector<string> &v)
{
    int n = (int)(v).size();
    vector<string> res;
    for (int i = 0; i < n; ++i) {
        string s;
        for (int j = n - 1; j >= 0; --j)
            s += v[j][i];
        res.push_back(s);
    }
    return res;
}

vector<string> reflect(const vector<string> &v)
{
    vector<string> res = v;
    int n = (int)(v).size();
    for (int i = 0; i < n; ++i)
        reverse((res[i]).begin(), (res[i]).end());
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
    //////////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;
    vector<string> orig(n), dest(n);
    for (int i = 0; i < n; ++i)
        cin >> orig[i];
    for (int i = 0; i < n; ++i)
        cin >> dest[i];
    vector<string> aux = orig;
    for (int i = 1; i <= 3; ++i) {
        aux = rotate_clockwise(aux);
        if (aux == dest) {
            cout << i << endl;
            return 0;
        }
    }
    aux = reflect(orig);
    if (aux == dest) {
        cout << 4 << endl;
        return 0;
    }
    for (int i = 1; i <= 3; ++i) {
        aux = rotate_clockwise(aux);
        if (aux == dest) {
            cout << 5 << endl;
            return 0;
        }
    }
    cout << (orig == dest ? 6 : 7) << endl;
}
