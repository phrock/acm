/*
  ID:   aphrodi1
  LANG: C++
  PROG: zerosum
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

ifstream fin("zerosum.in");
ofstream fout("zerosum.out");
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

int n;
string s;

template<class T> vector<T> split(const string& s, const string& delim = " ") {
    vector<string> aux;
    string t;
    for (int i = 0; i != (int)(s).size(); ++i)
        if (delim.find(s[i]) != string::npos) { if (!t.empty()) { aux.push_back(t); t = ""; } }
        else t += s[i];
    if (!t.empty()) aux.push_back(t);
    vector<T> res;
    for (int i = 0; i < (int)(aux).size(); ++i)
        res.push_back(*({stringstream ss; ss << (aux[i]); static T _; ss >> _; &_;}));
    return res;
}

bool check(string s)
{
    vector<string> v = split<string>(s, " ");
    s = "+";
    for (int i = 0; i < (int)(v).size(); ++i)
        s += v[i];
    s += ' ';
    int res = 0, aux = 0;
    char c;
    for (int i = 0; i < (int)(s).size(); ++i) {
        if (!isdigit(s[i])) {
            if (c == '+')
                res += aux;
            else
                res -= aux;
            aux = 0;
            c = s[i];
        } else {
            aux = aux * 10 + (s[i] - '0');
        }
        // cout << s[i] << " " << aux << " " << c << " " << res << endl;
    }
    // cout << s << endl;
    // cout << res << endl;
    return res == 0;
}

void dfs(int cur)
{
    // cout << cur << " ** " << s << endl;
    if (cur >= (int)(s).size()) {
        if (check(s))
            cout << s << endl;
        return;
    }
    char orig;
    for (int i = 0; i < 3; ++i) {
        switch (i) {
        case 0:
            dfs(cur + 2);
            break;
        case 1:
            orig = s[cur];
            s[cur] = '+';
            dfs(cur + 2);
            s[cur] = orig;
            break;
        case 2:
            orig = s[cur];
            s[cur] = '-';
            dfs(cur + 2);
            s[cur] = orig;
            break;
        }
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
    ////////////////////////////////////////////////////////////////////////////

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (i > 1) s += ' ';
        s += '0' + i;
    }
    // cout << s << endl;
    dfs(1);
    // string s = "1+2-3+4-5-6+7";
    // cout << check(s) << endl;
}
