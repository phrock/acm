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


int p1[]={-1, 1, 0, 0};
int p2[]={0, 0, -1, 1};

int main()
{
  int m, n;
  while (cin>>m>>n) {
    if (!m) break;
    vector<string> v(n);
    for (int i=0; i<n; ++i) cin>>v[i];
    vector< vector<int> > a(n, vector<int>(m));
    int x, y;
    for (int i=0; i<n; ++i)
      for (int j=0; j<m; ++j)
	if (v[i][j]=='@') { x=i; y=j; }
    a[x][y]=1;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
      pair<int, int> aux=q.front();
      q.pop();
      #ifdef DEBUG
      cout<<aux.first<<" "<<aux.second<<endl;
      #endif
      for (int i=0; i<4; ++i) {
	int x=aux.first+p1[i];
	int y=aux.second+p2[i];
	if (x>=0 && x<n && y>=0 && y<m && v[x][y]=='.' && !a[x][y]) q.push(make_pair(x, y)), a[x][y]=1;
      }
    }
    int res=0;
    for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) if (a[i][j]==1) res++;
    cout<<res<<endl;
  }
}
