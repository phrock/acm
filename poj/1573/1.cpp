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


int main()
{
  int n, m, x, y;
  while (cin>>n>>m>>y) {
    if (!n) break;
    x=0;
    y--;
    vector<string> a(n);
    for (int i=0; i<n; ++i) cin>>a[i];
    vector< vector<int> > v(n, vector<int>(m, -1));
    v[x][y]=0;
    int cnt=0;
    while (true) {
      cnt++;
      switch (a[x][y]) {
      case 'N': x--; break;
      case 'S': x++; break;
      case 'W': y--; break;
      case 'E': y++; break;
      }
      if (x<0 || x>=n || y<0 || y>=m) { cout<<cnt<<" step(s) to exit"<<endl; break; }
      else if (v[x][y]!=-1) { cout<<v[x][y]<<" step(s) before a loop of "<<cnt-v[x][y]<<" step(s)"<<endl; break; }
      else v[x][y]=cnt;
    }
  }
}
