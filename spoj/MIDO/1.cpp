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
    int n;
    cin >> n;
    int idx = 0, score1 = 0, score2 = 0, lead1 = 0, lead2 = 0, time = 0;
    for (int i = 0; i < n; ++i) {
        int team;
        cin >> team;
        string s;
        cin >> s;
        vector<int> v = split<int>(s, ":");
        int newtime = v[0] * 60 + v[1];
        #ifdef DEBUG
        print(v);        
        #endif
        if (idx == 1) lead1 += newtime - time;
        else if (idx == 2) lead2 += newtime - time;
        time = newtime;
        if (team == 1) ++score1;
        else ++score2;
        if (score1 == score2) idx = 0;
        else if (score1 > score2) idx = 1;
        else idx = 2;
    }
    if (idx == 1) lead1 += 48 * 60 - time;
    else if (idx == 2) lead2 += 48 * 60 - time;

    string s = *({stringstream ss; ss << (lead1 / 60); static string _; ss >> _; &_;});
    if ((int)(s).size() == 1) s = "0" + s;
    cout << s << ":";
    s = *({stringstream ss; ss << (lead1 % 60); static string _; ss >> _; &_;});
    if ((int)(s).size() == 1) s = "0" + s;
    cout << s << endl;

    s = *({stringstream ss; ss << (lead2 / 60); static string _; ss >> _; &_;});
    if ((int)(s).size() == 1) s = "0" + s;
    cout << s << ":";
    s = *({stringstream ss; ss << (lead2 % 60); static string _; ss >> _; &_;});
    if ((int)(s).size() == 1) s = "0" + s;
    cout << s << endl;
}
