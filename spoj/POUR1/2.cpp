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

    int p,q,a,b,c,t,n,cnt;

    scanf("%d",&t);
    for(n=0;n<t;n++) {
        scanf("%d %d %d",&a,&b,&c);
        if(a<=0||b<=0||c<=0||(c>a && c>b) || c%__gcd(a, b)) {
            cout << -1 << endl;
            continue;
        }

        int res = INT_MAX;
        for (int i = 0; i < 2; ++i) {
            if (i) swap(a, b);
            p=0; q=0; cnt = 0;
            while(p!=c && q!=c) {
                if(p==0) {
                    p=a;
                } else if(q<b) {
                    int pour = min(p, b-q);
                    p -= pour;
                    q += pour;
                } else if(q==b) {
                    q=0;
                }
                cnt++;
            }
            res = min(res, cnt);
        }

        cout << res << endl;
    }

}
