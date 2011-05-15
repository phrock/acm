/*
  ID:   rock2to1
  LANG: C++
  PROG: camelot
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

ifstream fin("camelot.in");
ofstream fout("camelot.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////

const int M=INT_MAX/4;
int kx, ky;
vector<int> knight;
int n, m;
int p[]={-2, -2, -1, -1, 1, 1, 2, 2};
int q[]={-1, 1, -2, 2, -2, 2, -1, 1};
int dist[1000][1000];

void findDist(int pos)
{
  dist[pos][pos]=0;
  queue<int> que;
  que.push(pos);
  while (!que.empty()) {
    int top=que.front();
    que.pop();
    int x=top/m, y=top%m;
    for (int i=0; i<8; ++i) {
      int nx=x+p[i], ny=y+q[i], next=nx*m+ny;
      if (nx>=0 && ny>=0 && nx<n && ny<m && dist[pos][next]==-1) {
	dist[pos][next]=dist[pos][top]+1;
	que.push(next);
      }
    }
  }
}

int func(int pos)
{
  for (int i=0; i<(int)(knight).size(); ++i) if (dist[pos][knight[i]]==-1) return M;

  int px=pos/m, py=pos%m;
  int king=abs(px-kx)+abs(py-ky)-min(abs(px-kx), abs(py-ky));
  int sum=0;
  for (int i=0; i<(int)(knight).size(); ++i) sum+=dist[pos][knight[i]];
  int res=sum+king;

  for (int i=kx-2; i<=kx+2; ++i)
    for (int j=ky-2; j<=ky+2; ++j) {
      if (!(i>=0 && j>=0 && i<n && j<m)) continue;
      if (dist[pos][i*m+j]==-1) continue;
      int king_move=abs(i-kx)+abs(j-ky)-min(abs(i-kx), abs(j-ky));
      if (king_move>=king) continue;
      int pick=i*m+j;
      for (int k=0; k<(int)(knight).size(); ++k) {
	if (dist[pick][pos]==-1 || dist[pick][knight[k]]==-1) continue;
       	int aux=king_move+dist[pick][pos]+dist[pick][knight[k]]+(sum-dist[pos][knight[k]]);
       	res=min(res, aux);
      }
    }
  return res;
}
  

int main()
{
  cin.rdbuf(fin.rdbuf());
  cout.rdbuf(fout.rdbuf());
  #ifdef DEBUG
  cin.rdbuf(cin_buf);
  cout.rdbuf(cout_buf);
  #endif
  //////////////////////////////////////////////////////////////////////////////

  int aux;
  char c;
  cin>>n>>m;
  cin>>c>>aux;
  kx=aux-1; ky=c-'A';
  while (cin>>c>>aux) {
    int x=aux-1, y=c-'A';
    knight.push_back(x*m+y);
  }
  memset(dist, -1, sizeof(dist));
  for (int i=0; i<n*m; ++i) findDist(i);
  int res=M;
  for (int i=0; i<n*m; ++i) res=min(res, func(i));
  cout<<res<<endl;
}
