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
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print(T A[], int n) { cout<<"{ "; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print2(T A[], int n, int m) { cout<<"{"<<endl; for (int i=0; i<n; ++i) {cout<<" { "; for (int j=0; j<m; ++j) { cout<<A[i][j]; if (j+1<m) cout<<", ";} cout<<" } "<<endl; } cout<<"}"<<endl; }

int main()
{
  int dir[][2]={ {0, 1}, {-1, 0}, {0, -1}, {1, 0} };
  int K;
  cin>>K;
  for (int tc=0; tc<K; ++tc) {
    int a, b;
    cin>>a>>b;
    vector< vector<int> > v(a+1, vector<int>(b+1));
    int n, m;
    cin>>n>>m;
    vector<vector<int> > robot(n+1, vector<int>(3));
    for (int i=1; i<=n; ++i) {
      int x, y;
      char c;
      cin>>x>>y>>c;
      v[x][y]=i;
      robot[i][1]=x; robot[i][2]=y;
      switch (c) {
      case 'N': robot[i][0]=0; break;
      case 'W': robot[i][0]=1; break;
      case 'S': robot[i][0]=2; break;
      case 'E': robot[i][0]=3; break;
      }
    }
    bool ok=true;
    for (int i=0; i<m; ++i) {
      int r, repeat;
      char action;
      cin>>r>>action>>repeat;
      #ifdef DEBUG
      cout<<i<<endl;
      print2(v);
      print2(robot);
      #endif
      if (!ok) continue;
      switch (action) {
      case 'L': for (int j=0; j<repeat; ++j) robot[r][0]=(robot[r][0]+1)%4; break;
      case 'R': for (int j=0; j<repeat; ++j) robot[r][0]=(robot[r][0]+3)%4; break;
      case 'F':
	int rx=robot[r][1], ry=robot[r][2];
	for (int j=0; j<repeat; ++j) {
	  rx+=dir[robot[r][0]][0];
	  ry+=dir[robot[r][0]][1];
	  if (rx<1 || rx>a || ry<1 || ry>b) { ok=false; cout<<"Robot "<<r<<" crashes into the wall"<<endl; break; }
	  if (v[rx][ry]) { ok=false; cout<<"Robot "<<r<<" crashes into robot "<<v[rx][ry]<<endl; break; }
	}
	if (ok) { v[rx][ry]=r; v[robot[r][1]][robot[r][2]]=0; robot[r][1]=rx; robot[r][2]=ry; }
      }
      #ifdef DEBUG
      cout<<i<<endl;
      print2(v);
      print2(robot);
      #endif
    }
    if (ok) cout<<"OK"<<endl;
  }
}
