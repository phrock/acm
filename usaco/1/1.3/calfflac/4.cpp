/*
  ID:   aphrodi1
  LANG: C++
  PROG: calfflac
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

ifstream fin("calfflac.in");
ofstream fout("calfflac.out");
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

bool is_palindrome(const string &s, int start, int stop)
{
    while (start < stop) {
        if (s[start] != s[stop])
            return false;
        ++start;
        --stop;
    }
    return true;
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

    string orig;
    getline(cin, orig, (char)EOF);
    string s;
    vector<int> v;
    for (int i = 0; i < (int)(orig).size(); ++i)
        if (isalpha(orig[i])) {
            s += tolower(orig[i]);
            v.push_back(i);
        }
    int max_length = 0, start;
    string res;
    for (int i = 0; i < (int)(s).size(); ++i)
        for (int j = 0; j < 2; ++j) {
            int a, b;
            if (j) {
                int aux = (max_length + 1) / 2;
                a = i - aux;
                b = i + aux;
            } else {
                int aux = (max_length + 2) / 2;
                a = i - aux + 1;
                b = i + aux;
            }
            while (a >= 0 && b < (int)(s).size()) {
                int length = b - a + 1;
                if (is_palindrome(s, a, b)) {
                    if ((length > max_length) ||
                        ((length == max_length) && a < start)) {
                        max_length = length;
                        start = a;
                        res = orig.substr(v[a], v[b] - v[a] + 1);
                    }
                } else {
                    break;
                }
                --a;
                ++b;
            }
        }
    cout << max_length << endl << res << endl;
}
