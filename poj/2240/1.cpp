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
  int n;
  int cnt=0;
  while (cin>>n && n) {
    vector<vector<double> > g(n, vector<double>(n, -1));
    map<string, int> mm;
    int x=0;
    for (int i=0; i<n; ++i) {
      string s;
      cin>>s;
      mm[s]=x++;
    }
    int m;
    cin>>m;
    for (int i=0; i<m; ++i) {
      string s1, s2;
      double p;
      cin>>s1>>p>>s2;
      g[mm[s1]][mm[s2]]=p;
    }
    vector<double> v(n, 1);
    for (int k=0; k<n; ++k)
      for (int i=0; i<n; ++i)
	for (int j=0; j<n; ++j)
	  if (g[i][j]!=-1 && v[i]*g[i][j]>v[j]) v[j]=v[i]*g[i][j];
    bool ok=false;
    for (int i=0; i<n; ++i)
      for (int j=0; j<n; ++j)
	if (g[i][j]!=-1 && v[i]*g[i][j]>v[j]) ok=true;
    cout<<"Case "<<++cnt<<": "<<(ok?"Yes":"No")<<endl;
  }
}
