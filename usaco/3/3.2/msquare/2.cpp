/*
  ID:   aphrodi1
  LANG: C++
  PROG: msquare
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

ifstream fin("msquare.in");
ofstream fout("msquare.out");
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

vector<int> func_A(const vector<int> &v)
{
    int a[] = {8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> res(8);
    for (int i = 0; i < 8; ++i)
        res[i] = v[a[i] - 1];
    return res;
}

vector<int> func_B(const vector<int> &v)
{
    int a[] = {4, 1, 2, 3, 6, 7, 8, 5};
    vector<int> res(8);
    for (int i = 0; i < 8; ++i)
        res[i] = v[a[i] - 1];
    return res;
}

vector<int> func_C(const vector<int> &v)
{
    int a[] = {1, 7, 2, 4, 5, 3, 6, 8};
    vector<int> res(8);
    for (int i = 0; i < 8; ++i)
        res[i] = v[a[i] - 1];
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
    ////////////////////////////////////////////////////////////////////////////

    int aux[] = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> init(aux, aux + 8);
    vector<int> dest(8);
    for (int i = 0; i < 8; ++i)
        cin >> dest[i];

    map<vector<int>, pair<char, vector<int> > > mp;
    queue<vector<int> > q;
    q.push(init);
    mp[init].first = 'Z';

    while (!q.empty()) {
        vector<int> ft = q.front();
        #ifdef DEBUG
        print(ft);        
        #endif
        if (ft == dest) {
            break;
        }
        q.pop();
        vector<int> aux = func_A(ft);
        if (!((mp).find(aux) != (mp).end())) {
            q.push(aux);
            mp[aux].first = 'A';
            mp[aux].second = ft;
        }
        aux = func_B(ft);
        if (!((mp).find(aux) != (mp).end())) {
            q.push(aux);
            mp[aux].first = 'B';
            mp[aux].second = ft;
        }
        aux = func_C(ft);
        if (!((mp).find(aux) != (mp).end())) {
            q.push(aux);
            mp[aux].first = 'C';
            mp[aux].second = ft;
        }
    }

    string path;
    while (dest != init) {
        path = mp[dest].first + path;
        dest = mp[dest].second;
    }

    cout << (int)(path).size() << endl;
    for (int i = 0; i < (int)(path).size(); ++i) {
        if (i && i % 60 == 0)
            cout << endl;
        cout << path[i];
    }
    cout << endl;
}
