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
////////////////////////////////////////////////////////////////////////////////

const int MAX=20;

int main()
{
    int start=0, dest=0;
    for (int i=0; i<MAX; ++i) { int x; cin>>x; if (x) start|=1<<i; }

    map<int, int> mm;
    queue<int> q;
    q.push(start);
    mm[start]=0;
    while (!q.empty()) {
        int x=q.front();
        q.pop();
        if (x==dest) break;
        for (int i=0; i<MAX-3+1; ++i) {
            int next=x;
            for (int j=0; j<3; ++j)
                next^=1<<(i+j);
            if (!((mm).find(next)!=(mm).end())) mm[next]=mm[x]+1, q.push(next);
        }
    }
    cout<<mm[dest]<<endl;
}
