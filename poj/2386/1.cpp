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
  int n, m;
  cin>>n>>m;
  vector<string> g(n);
  for (int i=0; i<n; ++i) cin>>g[i];
  int res=0;
  for (int i=0; i<(int)(g).size(); ++i)
    for (int j=0; j<(int)(g[i]).size(); ++j)
      if (g[i][j]=='W') {
	res++;
	queue<int> q;
	q.push(i*m+j);
	g[i][j]='.';
	while (!q.empty()) {
	  int top=q.front();
	  q.pop();
	  int x=top/m, y=top%m;
	  for (int a=-1; a<=1; ++a)
	    for (int b=-1; b<=1; ++b) {
	      if (!a && !b) continue;
	      if (x+a>=0 && y+b>=0 && x+a<n && y+b<m && g[x+a][y+b]=='W')
		g[x+a][y+b]='.', q.push((x+a)*m+y+b);
	    }
	}
      }
  cout<<res<<endl;
}
