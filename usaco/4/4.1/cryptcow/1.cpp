/*
  ID:   aphrodi1
  LANG: C++
  PROG: cryptcow
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

ifstream fin("cryptcow.in");
ofstream fout("cryptcow.out");
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

pair<int, int> check_help(const string &s, const string &dest)
{
    // int c_cnt = 0, o_cnt = 0, w_cnt = 0;
    // for (int i = 0; i < (int)(s).size(); ++i)
    //     switch(s[i]) {
    //     case 'C': ++c_cnt; break;
    //     case 'O': ++o_cnt; break;
    //     case 'W': ++w_cnt; break;
    //     }
    // if (c_cnt != o_cnt || o_cnt != w_cnt) {
    //     return false;
    // }
    int c_idx, w_idx;
    for (int i = 0; i < (int)(s).size(); ++i)
        if (s[i] == 'C') {
            c_idx = i;
            break;
        } else if (s[i] == 'O' || s[i] == 'W') {
            return make_pair(-1, -1);
        }
    for (int i = (int)(s).size() - 1; i >= 0; --i)
        if (s[i] == 'W') {
            w_idx = i;
            break;
        } else if (s[i] == 'C' || s[i] == 'O') {
            return make_pair(-1, -1);
        }
    cout << "kao"<<endl;
    cout << c_idx<<" " << w_idx<<endl;
    int tail = (int)(s).size() - w_idx - 1;
    cout << dest.substr(0, c_idx)<<"*"<<s.substr(0, c_idx)<<endl;
    // cout << dest.substr(n - tail)<<"*"<<s.substr(w_idx + 1)<<endl;
    if (dest.substr(0, c_idx) != s.substr(0, c_idx) ||
        dest.substr((int)(dest).size() - tail) != s.substr(w_idx + 1))
        return make_pair(-1, -1);
    return make_pair(c_idx, w_idx);
}

bool check(const string &s, const string &dest, int cnt)
{
    cout << s << " *** " << cnt << endl;
    if (!cnt) return s == dest;
    pair<int, int> x = check_help(s, dest);
    cout << x.first << " " << x.second << endl;
    if (x.first == -1)
        return false;
    for (int i = x.first + 1; i < x.second; ++i)
        if (s[i] == 'O') {
            string next = s.substr(0, x.first) + s.substr(i + 1, x.second - i - 1) + s.substr(x.first + 1, i - x.first - 1) + s.substr(x.second + 1);
            if (check(next, dest, cnt - 1))
                return true;
        }
    int c_cnt = 0, o_cnt = 0, w_cnt = 0;
    for (int i = 0; i < (int)(s).size(); ++i)
        switch(s[i]) {
        case 'C': ++c_cnt; break;
        case 'O': ++o_cnt; break;
        case 'W': ++w_cnt;
            if (c_cnt == o_cnt && o_cnt == w_cnt && c_cnt != cnt) {
                int len = i - 3 * c_cnt + 1;
                if (check(s.substr(0, i + 1), dest.substr(len), c_cnt) &&
                    check(s.substr(i +1), dest.substr(len), cnt - c_cnt))
                    return true;
            }
            break;
        }

    return false;
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

    string dest = "Begin the Escape execution at the Break of Dawn";

    string s;
    getline(cin, s);
    cout << s << endl;
    int c_cnt = 0, o_cnt = 0, w_cnt = 0;
    for (int i = 0; i < (int)(s).size(); ++i)
        switch(s[i]) {
        case 'C': ++c_cnt; break;
        case 'O': ++o_cnt; break;
        case 'W': ++w_cnt; break;
        }
    if (c_cnt != o_cnt || o_cnt != w_cnt) {
        cout << "0 0" << endl;
        return 0;
    }
    if (check(s, dest, c_cnt))
        cout << "1 " << c_cnt << endl;
    else
        cout << "0 0" << endl;
}
