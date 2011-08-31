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
//#include <map>
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

 
int n,x[161],y[161];
double map[161][161],res=1e20,mmax[161];
 
double dist(int i,int j)
{
  return (sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
}
 
int main()
{
  fin>>n;
  for (int i=1;i<=n;i++)
    fin>>x[i]>>y[i];
  for (int i=1;i<=n;i++)
    mmax[i]=0;
  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
      {
	char c;
	fin>>c;
	if(c=='1') map[i][j]=dist(i,j);
	else map[i][j]=1e20;
	if (i==j) map[i][j]=0;
      }
 
  for (int k=1;k<=n;k++)
    for (int i=1;i<=n;i++)
      for (int j=1;j<=n;j++)
	if (map[i][k]+map[k][j]<map[i][j]) 
	  map[i][j]=map[i][k]+map[k][j];
 
  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
      if ((map[i][j]!=1e20)&&(map[i][j]>mmax[i]))
	mmax[i]=map[i][j];

  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
      if (map[i][j]==1e20)
	{
	  if (dist(i,j)+mmax[i]+mmax[j]<res)
	    {
	      res=dist(i,j)+mmax[i]+mmax[j];
	    }
	}
  for (int i=1;i<=n;i++)
    if (mmax[i]>res) res=mmax[i];
  fout<<setprecision(6)<<setiosflags(ios::fixed  | ios::showpoint)<<res<<endl;
  return 0;
}
