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

bool all_lower(const string &s)
{
    for (int i = 0; i < (int)(s).size(); ++i)
        if (isupper(s[i])) return false;
    return true;
}

string cpp(const vector<string> &v)
{
    string s = v[0];
    string res, tmp;
    int i = 0;
    while (i < (int)(s).size() && islower(s[i]))
        res += s[i++];

    for (; i < (int)(s).size(); ++i) {
        if (isupper(s[i])) {
            if (!tmp.empty()) res += "_" + tmp;
            tmp = string() + (char)tolower(s[i]);
        } else {
            tmp += s[i];
        }
    }
    if (!tmp.empty()) res += "_" + tmp;
    return res;
}

string java(const vector<string> &v)
{
    string res = v[0];
    for (int i = 1; i < (int)(v).size(); ++i) {
        string aux = v[i];
        aux[0] = toupper(aux[0]);
        res += aux;
    }
    return res;
}

int main()
{
    string s;
    while (cin >> s) {
        if (isupper(s[0]) ||s[0] == '_' || s[(int)(s).size() - 1] == '_' ||
            s.find("__") != string::npos) {
            cout << "Error!" << endl;
            continue;
        }

        vector<string> v = split<string>(s, "_");
        if ((int)(v).size() == 1) {
            if (all_lower(v[0])) cout << java(v) << endl;
            else cout << cpp(v) << endl;
        } else {
            bool ok = true;
            for (int i = 0; i < (int)(v).size(); ++i)
                if (!all_lower(v[i])) {
                    ok = false;
                    break;
                }
            if (!ok) cout << "Error!" << endl;
            else cout << java(v) << endl;
        }
    }
}
