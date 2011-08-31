/*
  ID:   aphrodi1
  LANG: C++
  PROG: contact
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

ifstream fin("contact.in");
ofstream fout("contact.out");
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

bool cmp(const pair<int, vector<string> >&a, const pair<int, vector<string> > &b)
{
    return a.first > b.first;
}

bool cmp2(const string &a, const string &b)
{
    if ((int)(a).size() != (int)(b).size())
        return (int)(a).size() < (int)(b).size();
    else
        return a < b;
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

    int a, b, n;
    cin >> a >> b >> n;
    string s, tmp;
    while (cin >> tmp)
        s += tmp;

    map<string, int> mp;
    for (int i = a; i <= b; ++i) {
        for (int j = 0; j + i <= (int)(s).size(); ++j)
            ++mp[s.substr(j, i)];
    }

    map<int, vector<string> > mp2;
    for (__typeof((mp).begin()) i = (mp).begin(); i != (mp).end(); ++i)
        mp2[i->second].push_back(i->first);

    #ifdef DEBUG
    for (__typeof((mp2).begin()) i = (mp2).begin(); i != (mp2).end(); ++i)
        cout << i->first << endl;
    #endif

    vector<pair<int, vector<string> > > v;
    for (__typeof((mp2).begin()) i = (mp2).begin(); i != (mp2).end(); ++i)
        v.push_back(make_pair(i->first, i->second));
    sort((v).begin(), (v).end(), cmp);

    n = min(n, (int)(v).size());
    for (int i = 0; i < n; ++i) {
        cout << v[i].first << endl;
        sort((v[i].second).begin(), (v[i].second).end(), cmp2);
        for (int j = 0; j < (int)(v[i].second).size(); ++j) {
            if (j) {
                if (j % 6 == 0)
                    cout << endl;
                else
                    cout << " ";
            }
            cout << v[i].second[j];
        }
        cout << endl;
    }
}
