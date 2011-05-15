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

const int M=100005;
int root[M];
int diff[M];

int getRoot(int x)
{
  if (x!=root[x]) root[x]=getRoot(root[x]);
  return root[x];
}

void setUnion(int x, int y)
{
  if (getRoot(x)!=getRoot(y)) root[getRoot(x)]=getRoot(y);
}

int main()
{
  int T, n, m;
  scanf("%d", &T);
  for (int i=0; i<T; ++i) {
    scanf("%d%d", &n, &m);
    for (int j=1; j<=n; ++j) root[j]=j, diff[j]=0;
    for (int j=0; j<m; ++j) {
      char c;
      int x, y;
      getchar();
      scanf("%c%d%d", &c, &x, &y);
      // cin>>c>>x>>y;
      #ifdef DEBUG
      cout<<c<<" "<<x<<" "<<y<<endl;      
      #endif
      int rx=getRoot(x);
      int ry=getRoot(y);
      if (c=='A') {
	if (rx==ry) cout<<"In the same gang."<<endl;
	else if (getRoot(diff[rx])==ry || getRoot(diff[ry])==rx) cout<<"In different gangs."<<endl;
	else cout<<"Not sure yet."<<endl;
      } else if (c=='D') {
	if (diff[x]) setUnion(diff[x], y);
	if (diff[y]) setUnion(diff[y], x);
	diff[rx]=ry;
	diff[ry]=rx;
      }
    }
  }
}
