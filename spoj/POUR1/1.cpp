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


int main()
{
    int T, a, b, c;
    cin >> T;
    for (int ti = 0; ti < T; ++ti) {
        cin >> a >> b >> c;
        if (c > max(a, b) || c % __gcd(a, b)) { cout << -1 << endl; continue; }
        map<pair<int, int>, int> mm;
        mm[make_pair(0, 0)] = 0;
        queue<pair<int, int> > q;
        q.push(make_pair(0, 0));
        int res = -1;
        while (!q.empty()) {
            pair<int, int> x = q.front();
            int dist = mm[x];
            q.pop();
            if (x.first == c || x.second == c) {
                res = dist;
                break;
            }
            vector<pair<int, int> > v;
            pair<int, int> next;
            next = x; next.first = 0; v.push_back(next);
            next = x; next.second = 0; v.push_back(next);
            next = x; next.first = a; v.push_back(next);
            next = x; next.second = b; v.push_back(next);
            int pour = min(x.first, b - x.second);
            next = x; next.first -= pour; next.second += pour; v.push_back(next);
            pour = min(a - x.first, x.second);
            next = x; next.first += pour; next.second -= pour; v.push_back(next);
            #ifdef DEBUG
            cout << x.first << " " << x.second << endl;
            printp(v);            
            #endif
            for (int i = 0; i < (int)(v).size(); ++i) {
                if (!((mm).find(v[i]) != (mm).end())) {
                    mm[v[i]] = dist + 1;
                    q.push(v[i]);
                }
            }
        }
        cout << res << endl;
    }
}
