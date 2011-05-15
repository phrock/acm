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
  int n, w, h;
  cin>>n>>w>>h;
  vector<pair<pair<int, int>, int> > v;
  for (int i=0; i<n; ++i) {
    int a, b;
    cin>>a>>b;
    if (w<a && h<b) {
      pair<pair<int, int>, int> x;
      x.first.first=a;
      x.first.second=b;
      x.second=i+1;
      v.push_back(x);
    }
  }
  int m=(int)(v).size();
  if (!m) { cout<<0<<endl; return 0; }
  sort((v).begin(), (v).end());
  vector<int> dp(m), pre(m, -1);
  for (int i=0; i<m; ++i) {
    int aux=0;
    for (int j=0; j<i; ++j)
      if (v[j].first.first<v[i].first.first && v[j].first.second<v[i].first.second && aux<dp[j]) {
	aux=dp[j];
	pre[i]=j;
      }
    dp[i]=aux+1;
  }
  int res=0, idx=0;
  for (int i=0; i<(int)(dp).size(); ++i) 
    if (dp[i]>res) { res=dp[i]; idx=i; }
  cout<<res<<endl;
  vector<int> path;
  while (idx!=-1) {
    path.push_back(v[idx].second);
    idx=pre[idx];
  }
  reverse((path).begin(), (path).end());
  for (int i=0; i<(int)(path).size(); ++i) {
    if (i) cout<<" ";
    cout<<path[i];
  }
  cout<<endl;
}
