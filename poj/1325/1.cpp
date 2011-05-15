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

const int M=1000;
int g[M][M], visited[M], match[M];
int n1, n2;

bool hungaryHelper(int idx)
{
  for (int i=1; i<=n2; ++i)
    if (g[idx][i] && !visited[i]) {
      visited[i]=1;
      if (match[i]==-1 || hungaryHelper(match[i])) {
	match[i]=idx;
	return true;
      }
    }
  return false;
}

int hungary()
{
  int res=0;
  memset(match, -1, sizeof(match));
  for (int i=1; i<=n1; ++i) {
    memset(visited, 0, sizeof(visited));
    if (hungaryHelper(i)) res++;
  }
  return res;
}

int main()
{
  int n, m, k;
  while (cin>>n && n) {
    memset(g, 0, sizeof(g));
    memset(match, 0, sizeof(match));
    cin>>m>>k;
    n1=n-1, n2=m-1;
    for (int i=0; i<k; ++i) {
      int dump, x, y;
      cin>>dump>>x>>y;
      if (x && y) g[x][y]=1;
    }
    cout<<hungary()<<endl;
  }
}
