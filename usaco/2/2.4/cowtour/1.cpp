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
template<class T> inline void print(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) cout<<*i<<", "; cout<<"}"<<endl; }
template<class T> inline void print2(T A) { cout<<"{"<<endl; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<" { "; for (__typeof((*i).begin()) j=(*i).begin(); j!=(*i).end(); j++) cout<<*j<<", "; cout<<"}"; cout<<endl;} cout<<"}"<<endl; }
template<class T> inline void printp(T A) { cout<<"{ "; for (__typeof((A).begin()) i=(A).begin(); i!=(A).end(); ++i) {cout<<"{"<<i->first<<", "<<i->second<<"}"; cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print(T A[], int n) { cout<<"{ "; for (int i=0; i<n; i++) { cout<<A[i]; if (i+1<n) cout<<", ";} cout<<" }"<<endl; }
template<class T> inline void print2(T A[], int n, int m) { cout<<"{"<<endl; for (int i=0; i<n; ++i) {cout<<" { "; for (int j=0; j<m; ++j) { cout<<A[i][j]; if (j+1<m) cout<<", ";} cout<<" } "<<endl; } cout<<"}"<<endl; }
const int M=INT_MAX/2;

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
      else if (g[i][j]=='1')
	dis[i][j]=sqrt((position[i].first-position[j].first)*(position[i].first-position[j].first)+
		       (position[i].second-position[j].second)*(position[i].second-position[j].second));
  for (int k=0; k<n; ++k)
    for (int i=0; i<n; ++i)
      for (int j=0; j<n; ++j) {
	if (i==j || k==i || k==j) continue;
	dis[i][j]=min(dis[i][j], dis[i][k]+dis[k][j]);
      }
  #ifdef DEBUG
  print2(dis);  
  #endif
  double res=M;
  for (int i=0; i<n; ++i)
    for (int j=i+1; j<n; ++j) {
      if (dis[i][j]!=M) continue;
      double bridge=sqrt((position[i].first-position[j].first)*(position[i].first-position[j].first)+
		       (position[i].second-position[j].second)*(position[i].second-position[j].second));
      double aux=-1;
      for (int p=0; p<n; ++p)
	for (int q=p+1; q<n; ++q) {
	  if (dis[p][q]!=M) continue;
	  double tmp=0;
	  if (dis[p][i]!=M) {
	    tmp=dis[p][i]+bridge+dis[q][j];
	  } else {
	    tmp=dis[p][j]+bridge+dis[q][i];
	  }
	  aux=max(aux, tmp);
	}
      res=min(res, aux);
    }
  double orig=0;
  for (int i=0; i<n; ++i)
    for (int j=i+1; j<n; ++j)
      if (dis[i][j]!=M) orig=max(orig, dis[i][j]);
  fout.setf(ios_base::fixed);
  fout<<setprecision(6);
  fout<<max(res, orig)<<endl;
}
