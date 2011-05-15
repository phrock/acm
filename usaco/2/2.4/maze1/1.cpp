/*
  ID:   rock2to1
  LANG: C++
  PROG: maze1
*/

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

ifstream fin("maze1.in");
ofstream fout("maze1.out");
////////////////////////////////////////////////////////////////////////////////
int p[]={-1, 0, 1, 0};
int q[]={0, 1, 0, -1};

int main()
{
  int w, h;
  string s;
  getline(fin, s);
  stringstream is(s);
  is>>w>>h;
  vector<string> g(2*h+1);
  for (int i=0; i<(int)(g).size(); ++i) getline(fin, g[i]);
#ifdef DEBUG
   for (int i=0; i<(int)(g).size(); ++i) cout<<g[i]<<endl;
#endif
  const int M=INT_MAX/2;
  vector<vector<int> > a(h, vector<int>(w, M));
  for (int i=0; i<(int)(g[0]).size(); ++i) if (g[0][i]==' ') a[0][(i-1)/2]=1;
  for (int i=0; i<(int)(g[2*h]).size(); ++i) if (g[2*h][i]==' ') a[h-1][(i-1)/2]=1;
  for (int i=0; i<(int)(g).size(); ++i) if (g[i][0]==' ') a[(i-1)/2][0]=1;
  for (int i=0; i<(int)(g).size(); ++i) if (g[i][2*w]==' ') a[(i-1)/2][w-1]=1;
  #ifdef DEBUG
  print2(a);  
  #endif
  int start1=-1, start2=-1;
  for (int i=0; i<h; ++i)
    for (int j=0; j<w; ++j)
      if (a[i][j]==1) {
	if (start1==-1) start1=i*w+j;
	else start2=i*w+j;
      }
  queue<int> qu;
  qu.push(start1); qu.push(start2);
  while (!qu.empty()) {
    int top=qu.front();
    qu.pop();
    int x=top/w;
    int y=top%w;
    for (int i=0; i<4; ++i) {
      int nx=x+p[i];
      int ny=y+q[i];
      // cout<<"****** "<<i<<" "<<nx<<" "<<ny<<endl;
      if (nx>=0 && ny>=0 && nx<h && ny<w) {
	int t1, t2;
	if (x==nx) t1=x*2+1, t2=max(y, ny)*2;
	else t1=max(x, nx)*2, t2=y*2+1;
	// cout<<t1<<" "<<t2<<" "<<g[t1][t2]<<endl;
	if (g[t1][t2]==' ' && a[x][y]+1<a[nx][ny]) {
	  a[nx][ny]=a[x][y]+1;
	  qu.push(nx*w+ny);
	}
      }
    }
  }
  #ifdef DEBUG
  print2(a);  
  #endif
  int res=0;
  for (int i=0; i<(int)(a).size(); ++i)
    for (int j=0; j<(int)(a[i]).size(); ++j)
      res=max(res, a[i][j]);
  fout<<res<<endl;
}
