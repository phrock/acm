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
  if (x==root[x]) return x;
  else return root[x]=getRoot(root[x]);
}

void setUnion(int x, int y)
{
  if (getRoot(x)!=getRoot(y)) root[x]=getRoot(y);
}

int main()
{
  int T, n, m;
  cin>>T;
  for (int i=0; i<T; ++i) {
    cin>>n>>m;
    for (int j=1; j<=n; ++j) root[j]=j, diff[j]=0;
    for (int j=0; j<m; ++j) {
      string s;
      int x, y;
      cin>>s>>x>>y;
      #ifdef DEBUG
      cout<<s<<" "<<x<<" "<<y<<endl;      
      #endif
      if (s=="A") {
	if (getRoot(x)==getRoot(y)) cout<<"In the same gang."<<endl;
	else {
	  if (diff[x]==getRoot(y)) cout<<"In different gangs."<<endl;
	  else cout<<"Not sure yet."<<endl;
	}
      } else {
	if (diff[x]) setUnion(diff[x], y);
	if (diff[y]) setUnion(diff[y], x);
	diff[x]=y; diff[y]=x;
      }
    }
  }
}
