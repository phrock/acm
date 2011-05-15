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


map<int, vector<int> > mm;
int main()
{
  vector<string> vs(4);
  for (int i=0; i<(int)(vs).size(); ++i) cin>>vs[i];
  int start=0;
  for (int i=0; i<(int)(vs).size(); ++i) 
    for (int j=0; j<4; ++j)
      if (vs[i][j]=='-') start|=1<<(i*4+j);
  int dest=(1<<16)-1;
  queue<int> q;
  q.push(start);
  while (!q.empty()) {
    int x=q.front();
    q.pop();
    if (x==dest) {
      vector< pair<int, int> > path;
      while (x!=start) { path.push_back(make_pair(mm[x][1], mm[x][2])); x=mm[x][0]; }
      reverse((path).begin(), (path).end());
      cout<<(int)(path).size()<<endl;
      for (int i=0; i<(int)(path).size(); ++i) cout<<path[i].first<<" "<<path[i].second<<endl;
      break;
    }
    for (int i=0; i<4; ++i)
      for (int j=0; j<4; ++j) {
	int aux=x;
	aux^=1<<(i*4+j);
	for (int p=0; p<4; ++p) aux^=1<<(i*4+p);
	for (int p=0; p<4; ++p) aux^=1<<(p*4+j);
	if (((mm).find(aux)!=(mm).end())) continue;
	vector<int> v(3);
	v[0]=x; v[1]=i+1; v[2]=j+1;
	mm[aux]=v;
	q.push(aux);
      }
  }
}
