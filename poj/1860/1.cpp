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

struct node {
  int p;
  double rate;
  double commission;
};

vector<node> a[105];
map<int, double> mm;

int main()
{
  int n, m, s;
  double v;
  cin>>n>>m>>s>>v;
  mm[s]=v;
  for (int z=0; z<m; ++z) {
    int from, to;
    double r1, c1, r2, c2;
    cin>>from>>to>>r1>>c1>>r2>>c2;
    node nd1, nd2;
    nd1.p=to; nd1.rate=r1; nd1.commission=c1;
    a[from].push_back(nd1);
    nd2.p=from; nd2.rate=r2; nd2.commission=c2;
    a[to].push_back(nd2);
  }
  pair<int, double> start;
  start.first=s; start.second=v;
  queue<pair<int, double> > q;
  q.push(start);
  bool ok=false;
  while (!q.empty()) {
    pair<int, double> x=q.front();
    q.pop();
    if (x.first==s && x.second>v) { ok=true; break; }
    for (int i=0; i<(int)(a[x.first]).size(); ++i) {
      int to=a[x.first][i].p;
      double rate=a[x.first][i].rate;
      double commission=a[x.first][i].commission;
      double got=(x.second-commission)*rate;
      pair<int, double> next;
      next.first=to; next.second=got;
      if (((mm).find(to)!=(mm).end())) {
	if (mm[to]<got) { q.push(next); mm[to]=got; }
      } else { q.push(next); mm[to]=got; }
    }
  }
  cout<<(ok?"YES":"NO")<<endl;
}
