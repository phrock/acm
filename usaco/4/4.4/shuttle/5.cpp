/*
  ID:   aphrodi1
  LANG: C++
  PROG: shuttle
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
#include "/Users/Aphrodite/program/acm/lib/debug.cpp"
#endif

ifstream fin("shuttle.in");
ofstream fout("shuttle.out");
streambuf *cin_buf = cin.rdbuf();
streambuf *cout_buf = cout.rdbuf();

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/

void func(string &s, int &space, int k, vector<int> &res)
{
    int idx;
    if (k == 1) {
        idx = (s[space - 1] == '1') ? (space - 1) : (space - 2);
    } else {
        idx = s[space + 1] == '2' ? (space + 1) : (space + 2);
    }        
    res.push_back(idx + 1);
    swap(s[space], s[idx]);
    space = idx;
}

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    /////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; ++i)
        s += "1";
    s += "*";
    for (int i = 0; i < n; ++i)
        s += "2";

    vector<int> res;
    int space = n;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
        func(s, space, i % 2, res);
    for (int j = 0; j < n; ++j)
        func(s, space, (n + 1) % 2, res);
    for (int i = n; i >= 1; --i)
        for (int j = 0; j < i; ++j)
        func(s, space, i % 2, res);
    

    for (int i = 0; i < (int)(res).size(); ++i) {
        if (i % 20 == 0) {
            if (i)
                cout << endl;
        } else {
            cout << " ";
        }
        cout << res[i];
    }
    cout << endl;
}
