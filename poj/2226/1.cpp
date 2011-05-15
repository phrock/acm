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
int g[M][M], match[M], visited[M];
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
  int R, C;
  cin>>R>>C;
  vector<string> v(R);
  for (int i=0; i<R; ++i) cin>>v[i];
  vector<vector<int> > a(R, vector<int>(C)), b(R, vector<int>(C));
  int cnt=0;
  for (int i=0; i<R; ++i) {
    cnt++;
    for (int j=0; j<C; ++j)
      if (v[i][j]=='*') a[i][j]=cnt;
      else cnt++;
  }
  n1=cnt;
  
  cnt=0;
  for (int j=0; j<C; ++j) {
    cnt++;
    for (int i=0; i<R; ++i)
      if (v[i][j]=='*') b[i][j]=cnt;
      else cnt++;
  }
  n2=cnt;
  
  for (int i=0; i<(int)(v).size(); ++i)
    for (int j=0; j<(int)(v[i]).size(); ++j)
      if (v[i][j]=='*') g[a[i][j]][b[i][j]]=1;

  cout<<hungary()<<endl;
}
