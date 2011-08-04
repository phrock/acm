/*
  ID:   aphrodi1
  LANG: C++
  PROG: preface
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

ifstream fin("preface.in");
ofstream fout("preface.out");
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

int decimal[13] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
string roman[13] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

string decimal_to_roman(int n)
{
    string res;
    while (n) {
        int idx = upper_bound(decimal, decimal + 13, n) - decimal - 1;
        int k = n / decimal[idx];
        for (int i = 0; i < k; ++i)
            res += roman[idx];
        n -= k * decimal[idx];
    }
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
    ////////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;
    map<char, int> mp;
    for (int i = 1; i <= n; ++i) {
        string s = decimal_to_roman(i);
        for (int j = 0; j < (int)(s).size(); ++j)
            ++mp[s[j]];
    }
    char aux[7] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
    for (int i = 0; i < 7; ++i)
        if (!((mp).find(aux[i]) != (mp).end()))
            break;
        else
            cout << aux[i] << " " << mp[aux[i]] << endl;
}
