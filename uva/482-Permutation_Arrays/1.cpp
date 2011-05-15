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
#include "/home/rock/program/topcoder/libs/debug.cpp"
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
    int T;
    string s;
    getline(cin, s);
    T = *({stringstream ss; ss << (s); static int _; ss >> _; &_;});
    for (int ti = 0; ti < T; ++ti) {
        getline(cin, s);
        getline(cin, s);
        vector<int> v = split<int>(s);
        getline(cin, s);
        vector<string> v2 = split<string>(s);
        vector<pair<int, string> > p;
        for (int i = 0; i < (int)(v).size(); ++i)
            p.push_back(make_pair(v[i], v2[i]));
        sort((p).begin(), (p).end());
        if (ti) cout << endl;
        for (int i = 0; i < (int)(p).size(); ++i)
            cout << p[i].second << endl;
    }
}
