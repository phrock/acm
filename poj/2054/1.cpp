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

////////////////////////////////////////////////////////////////////////////////

const int M=1005;
int cost[M];
int father[M];
int visited[M];
int path[M];
int cur;

void dfs(int x)
{
  if (father[x]==x || visited[father[x]]) { path[cur++]=cost[x]; visited[x]=1; return; }
  dfs(father[x]);
  path[cur++]=cost[x]; visited[x]=1;
}

int main()
{
  int n, r;
  while (cin>>n>>r) {
    if (!n) break;
    memset(cost, 0, sizeof(cost));
    memset(father, 0, sizeof(father));
    memset(visited, 0, sizeof(visited));
    cur=0;
    for (int i=1; i<=n; ++i) cin>>cost[i];
    for (int i=0; i<n-1; ++i) {
      int a, b;
      cin>>a>>b;
      father[b]=a;
    }
    father[r]=r;
    vector< pair<int, int> > a;
    for (int i=1; i<=n; ++i) a.push_back(make_pair(cost[i], i));
    sort((a).begin(), (a).end(), greater<pair<int, int> >());
    while (true) {
      bool update=false;
      for (int i=0; i<(int)(a).size(); ++i) {
	if (visited[a[i].second]) continue;
	dfs(a[i].second);
	update=true;
      }
      if (!update) break;
    }
    int res=0;
    for (int i=0; i<n; ++i) res+=path[i]*(i+1);
    cout<<res<<endl;
  }
}
