/*
  ID:   aphrodi1
  LANG: C++
  PROG: namenum
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

ifstream fin("namenum.in");
ofstream fout("namenum.out");
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


int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    //////////////////////////////////////////////////////////////////////////////

    map<char, char> mp;
    for (char c = 'A'; c <= 'P'; ++c)
        mp[c] = '2' + (c - 'A') / 3;
    for (char c = 'Q'; c <= 'Y'; ++c)
        mp[c] = '7' + (c - 'Q') / 3;
    
    string num;
    cin >> num;
    ifstream dict("dict.txt");
    string s;
    bool ok = false;
    while (dict >> s) {
        string aux;
        for (int i = 0; i < (int)(s).size(); ++i) {
            if (s[i] == 'Q' || s[i] == 'Z') {
                aux.clear();
                break;
            }
            aux += mp[s[i]];
        }
        if (aux == num) {
            cout << s << endl;
            ok = true;
        }
    }
    if (!ok) cout << "NONE" << endl;
}
