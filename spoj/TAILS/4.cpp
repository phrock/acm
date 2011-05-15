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

int p[(1<<MAX)+1];

int main()
{
    int start=0, dest=0;
    for (int i=0; i<MAX; ++i) { int x; cin>>x; if (x) start|=1<<i; }
    memset(p, -1, sizeof(p));

    queue<int> q;
    q.push(start);
    p[start]=0;
    while (!q.empty()) {
        int x=q.front();
        q.pop();
        if (p[dest]!=-1) break;
        for (int i=0; i<MAX; ++i) {
            int next=x;
            for (int j=-1; j<=1; ++j)
                if (i+j>=0 && i+j<MAX) next^=1<<(i+j);
            if (p[next]==-1) p[next]=p[x]+1, q.push(next);
        }
    }
    cout<<p[dest]<<endl;
}
