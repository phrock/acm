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
    return a.first > b.second;
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

    map<int, vector<string> > mp;
    for (int i = a; i <= b; ++i) {
        map<string, int> tmp;
        for (int j = 0; j + a < (int)(s).size(); ++j)
            ++tmp[s.substr(j, i)];
        for (__typeof((tmp).begin()) j = (tmp).begin(); j != (tmp).end(); ++j)
            mp[j->second].push_back(j->first);
        if ((int)(mp).size() >= 100 * n)
            break;
    }

    vector<pair<int, vector<string> > > v((mp).begin(), (mp).end());
    sort((v).begin(), (v).end(), cmp);

    n = min(n, (int)(v).size());
    for (int i = 0; i < n; ++i) {
        cout << v[i].first << " ";
        sort((v[i].second).begin(), (v[i].second).end());
        if
}
