/*
  ID:   rock2to1
  LANG: C++
  PROG: numtri
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

ifstream fin("numtri.in");
ofstream fout("numtri.out");
////////////////////////////////////////////////////////////////////////////////

int main()
{
  int n;
  fin>>n;
  vector< vector<int> > v(n+1, vector<int>(n+1, INT_MIN/2));
  vector< vector<int> > res=v;
  for (int i=1; i<=n; ++i)
    for (int j=1; j<=i; ++j)
      fin>>v[i][j];
  res[1][1]=v[1][1];
  for (int i=2; i<=n; ++i)
    for (int j=1; j<=n; ++j)
      res[i][j]=max(res[i][j], res[i-1][j-1]+v[i][j]), res[i][j]=max(res[i][j], res[i-1][j]+v[i][j]);
  fout<<*max_element((res[n]).begin(), (res[n]).end())<<endl;
}
