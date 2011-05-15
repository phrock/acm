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
#include <ext/hash_set>

using namespace __gnu_cxx;

namespace __gnu_cxx
{
    template<> struct hash<const string>
    {
        size_t operator()(const string& s) const
        { return hash<const char*>()( s.c_str() ); } //__stl_hash_string
    };
    template<> struct hash<string>
    {
        size_t operator()(const string& s) const
        { return hash<const char*>()( s.c_str() ); }
    };
}

void inc(string &s, int k)
{
    char c = 'a' + k - 1;
    int idx = (int)(s).size() - 1;
    while (s[idx] == c) {
        s[idx] = 'a';
        --idx;
    }
    ++s[idx];
}

void dec(string &s, int k)
{
    int idx = (int)(s).size() - 1;
    while (s[idx] == 'a') {
        s[idx] = 'a' + k - 1;
        --idx;
    }
    --s[idx];
}

int main()
{
    int T;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        int n, m, k;
        string s, res;
        cin >> n >> m >> k >> s;
        hash<string> hh;
        set<int> st;
        for (int i = 0; i + m < (int)(s).size() + 1; ++i)
            st.insert(hh(s.substr(i, m)));
        string aux(m, 'a');
        if (!((st).find(hh(aux)) != (st).end())) {
            cout << aux << endl;
            continue;
        }
        aux = string(m, char('a' + k - 1));
        if (!((st).find(hh(aux)) != (st).end())) {
            cout << aux << endl;
            continue;
        }
        while (true) {
            dec(aux, k);
            if (!((st).find(hh(aux)) != (st).end())) {
                cout << aux << endl;
                break;
            }
        }
    }
}       
