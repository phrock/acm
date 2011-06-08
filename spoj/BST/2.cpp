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
#include "/home/rock/program/acm/topcoder/libs/debug.cpp"
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
    int n, x, res = 0;
    map<pair<int, int>, int> mp;
    scanf("%d", &n);
    mp[make_pair(0, n + 1)] = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        for (__typeof((mp).begin()) j = (mp).begin(); j != (mp).end(); ++j)
            if (x > j->first.first && x < j->first.second) {
                res += j->second;
                if (x > j->first.first + 1)
                    mp[make_pair(j->first.first, x)] = j->second + 1;
                if (x + 1 < j->first.second)
                    mp[make_pair(x, j->first.second)] = j->second + 1;
                // cout << x <<": "<<j->first.first << " " << j->first.second << " " << j->second<<endl;
                #ifdef DEBUG
                cout<<"**********"<<endl;
                for (__typeof((mp).begin()) k = (mp).begin(); k != (mp).end(); ++k) {
                    cout<<k->first.first<<" "<<k->first.second<<" "<<k->second<<endl;
                }
                cout<<"**********"<<endl;
                #endif

                mp.erase(j);
                #ifdef DEBUG
                cout<<"////////////"<<endl;
                for (__typeof((mp).begin()) k = (mp).begin(); k != (mp).end(); ++k) {
                    cout<<k->first.first<<" "<<k->first.second<<" "<<k->second<<endl;
                }
                cout<<"////////////"<<endl;
                #endif
                break;
            }
        printf("%d\n", res);
    }
}
