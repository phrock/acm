/*
  ID:   aphrodi1
  LANG: C++
  PROG: fracdec
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

ifstream fin("fracdec.in");
ofstream fout("fracdec.out");
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


int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    ////////////////////////////////////////////////////////////////////////////

    int n, d;
    cin >> n >> d;
    if (n % d == 0) {
        cout << n / d << ".0" << endl;
        return 0;
    }
    stringstream is;
    is << n / d << ".";
    n %= d;
    vector<int> v;
    map<int, int> mp;
    int cycle = -1;
    while (true) {
        mp[n] = (int)(v).size();
        n *= 10;
        v.push_back(n / d);
        n %= d;
        if (!n) break;
        if (((mp).find(n) != (mp).end())) {
            cycle = mp[n];
            break;
        }
    }
    if (cycle == -1) {
        for (int i = 0; i < (int)(v).size(); ++i)
            is << v[i];
    } else {
        for (int i = 0; i < (int)(v).size(); ++i) {
            if (i == cycle) is << "(";
            is << v[i];
        }
        is << ")";
    }

    string res;
    is >> res;
    for (int i = 0; i < (int)(res).size(); ++i) {
        if (i && (i % 76 == 0)) cout << endl;
        cout << res[i];
    }
    cout << endl;
}
