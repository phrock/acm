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

const int MAX=2000;
int root[MAX+5];
int rank[MAX+5];
int anti[MAX+5];

void initSet()
{
    for (int i=1; i<=MAX; ++i) root[i]=i, rank[i]=1, anti[i]=-1;
}

int findRoot(int x)
{
    if (root[x]!=x) root[x]=findRoot(root[x]);
    return root[x];
}

void mergeDisjointSet(int a, int b)
{
    int ra=findRoot(a), rb=findRoot(b);
    if (rank[ra]>rank[rb]) root[rb]=ra, rank[ra]++;
    else root[ra]=rb, rank[rb]++;
}

int main()
{
    int T, n, m, a, b;
    scanf("%d", &T);
    for (int i=0; i<T; ++i) {
        cout<<"Scenario #"<<i+1<<":"<<endl;
        initSet();
        bool ok = true;
        scanf("%d%d", &n, &m);
        for (int i=0; i<m; ++i) {
            scanf("%d%d", &a, &b);
            if (!ok) continue;
            if (findRoot(a) == findRoot(b)) { ok = false; continue; }
            if (anti[a] == -1) anti[a] = findRoot(b);
            else mergeDisjointSet(anti[a], b);
            if (anti[b] == -1) anti[b] = findRoot(a);
            else mergeDisjointSet(a, anti[b]);
        }
        cout<<(ok ? "No suspicious bugs found!" : "Suspicious bugs found!")<<endl;
    }
}
