/*
  ID:   aphrodi1
  LANG: C++
  PROG: barn1
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

ifstream fin("barn1.in");
ofstream fout("barn1.out");
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

int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    //////////////////////////////////////////////////////////////////////////////

    int m, k, c;
    cin >> m >> k >> c;
    string s(k, '0');
    for (int i = 0; i < c; ++i) {
        int x;
        cin >> x;
        s[x - 1] = '1';
    }
    while (s[0] == '0')
        s = s.substr(1);
    while (s[(int)(s).size() - 1] == '0')
        s = s.substr(0, (int)(s).size() - 1);
    int res = (int)(s).size();
    vector<string> v = split<string>(s, "1");
    sort((v).begin(), (v).end(), greater<string>());
    #ifdef DEBUG
    cout << s << endl;
    cout << res << endl;
    print(v);
    #endif
    for (int i = 0; i < min((int)(v).size(), m - 1); ++i)
        res -= (int)(v[i]).size();
    cout << res << endl;
}
