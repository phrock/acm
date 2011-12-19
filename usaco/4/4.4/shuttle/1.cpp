/*
  ID:   aphrodi1
  LANG: C++
  PROG: shuttle
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
#include "/Users/Aphrodite/program/acm/lib/debug.cpp"
#endif

ifstream fin("shuttle.in");
ofstream fout("shuttle.out");
streambuf *cin_buf = cin.rdbuf();
streambuf *cout_buf = cout.rdbuf();

/****************************************************************************
 *                                                                          *
 *                To see the world in a grain of sand,                      *
 *                And a heaven in a wild flower;                            *
 *                Hold infinity in the palm of your hand,                   *
 *                And eternity in an hour.                                  *
 *                                                                          *
 ***************************************************************************/


int main()
{
    cin.rdbuf(fin.rdbuf());
    cout.rdbuf(fout.rdbuf());
    #ifdef DEBUG
    cin.rdbuf(cin_buf);
    cout.rdbuf(cout_buf);
    #endif
    /////////////////////////////////////////////////////////////////////////

    int n;
    cin >> n;
    map<string, int> mp;
    map<string, string> pre;
    
    string s;
    for (int i = 0; i < n; ++i)
        s += "1";
    s += "*";
    for (int i = 0; i < n; ++i)
        s += "2";
    string dest = s;
    reverse((dest).begin(), (dest).end());
    mp[s] = -1;
    queue<string> q;
    q.push(s);

    while (!q.empty()) {
        string ft = q.front();
        q.pop();
        if (ft == dest)
            break;
        int space = 0;
        for (int i = 0; i < (int)(ft).size(); ++i)
            if (ft[i] == '*') {
                space = i;
                break;
            }
        string next;
        if (space > 1) {
            next = ft;
            int idx = space - 2;
            swap(next[space], next[idx]);
            if (!((mp).find(next) != (mp).end())) {
                q.push(next);
                mp[next] = idx + 1;
                pre[next] = ft;
            }
        }
        if (space > 0) {
            next = ft;
            int idx = space - 1;
            swap(next[space], next[idx]);
            if (!((mp).find(next) != (mp).end())) {
                q.push(next);
                mp[next] = idx + 1;
                pre[next] = ft;
            }
        }
        if (space < 2 * n) {
            next = ft;
            int idx = space + 1;
            swap(next[space], next[idx]);
            if (!((mp).find(next) != (mp).end())) {
                q.push(next);
                mp[next] = idx + 1;
                pre[next] = ft;
            }
        }
        if (space < 2 * n - 1) {
            next = ft;
            int idx = space + 2;
            swap(next[space], next[idx]);
            if (!((mp).find(next) != (mp).end())) {
                q.push(next);
                mp[next] = idx + 1;
                pre[next] = ft;
            }
        }
    }
    vector<int> res;
    while (mp[dest] != -1) {
        res.push_back(mp[dest]);
        dest = pre[dest];
    }
    reverse((res).begin(), (res).end());
    #ifdef DEBUG
    print(res);
    #endif
    for (int i = 0; i < (int)(res).size(); ++i) {
        if (i % 20 == 0) {
            if (i)
                cout << endl;
        } else {
            cout << " ";
        }
        cout << res[i];
    }
    cout << endl;
}
