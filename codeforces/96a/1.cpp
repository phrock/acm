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
    string s;
    cin >> s;
    bool ok = false;
    for (int i = 0; i < 2; ++i) {
        string c = i ? "1" : "0";
        vector<string> v = split<string>(s, c);
        for (int i = 0; i < (int)(v).size(); ++i)
            if ((int)(v[i]).size() >= 7)
                ok = true;
    }
    cout << (ok ? "YES" : "NO") << endl;
}
