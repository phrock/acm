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


int main()
{
    typedef bitset<20> node;
    node start, dest;
    for (int i=0; i<(int)(start).size(); ++i) { int x; cin>>x; start[i]=x; }
    dest.reset();
    map<node, int> mm;
    queue<node> q;
    q.push(start);
    mm[start]=0;
    while (!q.empty()) {
        node x=q.front();
        q.pop();
        if (x==dest) break;
        for (int i=0; i<(int)(start).size()-3+1; ++i) {
            node next=x;
            for (int j=0; j<3; ++j)
                next.flip(i+j);
            if (!((mm).find(next)!=(mm).end())) mm[next]=mm[x]+1, q.push(next);
        }
    }
}
