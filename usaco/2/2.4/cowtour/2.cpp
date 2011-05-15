/*
  ID:   rock2to1
  LANG: C++
  PROG: cowtour
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

ifstream fin("cowtour.in");
ofstream fout("cowtour.out");
////////////////////////////////////////////////////////////////////////////////
const int M=INT_MAX/2;

double dist(pair<double, double> a, pair<double, double> b)
{
  return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}

int main()
{
  int n;
  fin>>n;
  vector<pair<double, double> > position(n);
  for (int i=0; i<(int)(position).size(); ++i) fin>>position[i].first>>position[i].second;
  vector<string> g(n);
  for (int i=0; i<(int)(g).size(); ++i) fin>>g[i];
  vector<vector<double> > dis(n, vector<double>(n, M));
  for (int i=0; i<(int)(dis).size(); ++i)
    for (int j=0; j<(int)(dis[i]).size(); ++j)
      if (i==j) dis[i][j]=0;
      else if (g[i][j]=='1') dis[i][j]=dist(position[i], position[j]);
  for (int k=0; k<n; ++k)
    for (int i=0; i<n; ++i)
      for (int j=0; j<n; ++j) {
	dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
      }
  vector<double> far(n);
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      if (dis[i][j]!=M) far[i]=max(far[i], dis[i][j]);
  double res=M;
  for (int i=0; i<n; ++i)
    for (int j=i+1; j<n; ++j) {
      if (dis[i][j]!=M) continue;
      double aux=dist(position[i], position[j])+far[i]+far[j];
      res=min(res, aux);
    }
  for (int i=0; i<n; ++i) res=max(res, far[i]);
  fout<<setiosflags(ios::fixed|ios::showpoint)<<setprecision(6);
  fout<<res<<endl;
}
