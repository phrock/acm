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

double g[50][50];

int main()
{
  int n;
  int cnt=0;
  while (cin>>n && n) {
    // vector<vector<double> > g(n, vector<double>(n, -1));
    memset(g, 0, sizeof(g));
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
    bool ok=false;
    for (int k=0; k<n; ++k)
      for (int i=0; i<n; ++i)
	for (int j=0; j<n; ++j)
	  if (g[i][k]>0 && g[k][j]>0 && g[i][k]*g[k][j]>g[i][j]) g[i][j]=g[i][k]*g[k][j];
    for (int i=0; i<n; ++i) if (g[i][i]>1) ok=true;
    cout<<"Case "<<++cnt<<": "<<(ok?"Yes":"No")<<endl;
  }
}
