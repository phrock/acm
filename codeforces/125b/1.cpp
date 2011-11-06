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
#include "/Users/Aphrodite/program/acm/lib/debug.cpp"
#endif

/*****************************************************************************
 *                                                                           *
 *                To see the world in a grain of sand,                       *
 *                And a heaven in a wild flower;                             *
 *                Hold infinity in the palm of your hand,                    *
 *                And eternity in an hour.                                   *
 *                                                                           *
 ****************************************************************************/

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
    s = s.substr(1, (int)(s).size() - 2);
    vector<string> v = split<string>(s, "><");
    string spaces = "";
    for (int i = 0; i < (int)(v).size(); ++i) {
        if (v[i][0] != '/') {
            cout << spaces + "<" << v[i] << ">" << endl;
            spaces = spaces + "  ";
        } else {
            spaces = spaces.substr(2);
            cout << spaces + "<" << v[i] << ">" << endl;
        }            
    }
}
