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
    bool ok=false;
    for (int i=0; i<n; ++i) {
      vector<double> d(n, -1);
      d[i]=1;
      queue<pair<int, double> > q;
      q.push(make_pair(i, 1));
      while (!q.empty()) {
	if (ok) break;
	pair<int, double> x=q.front();
	#ifdef DEBUG
	cout<<x.first<<" "<<x.second<<endl;	
	#endif
	q.pop();
	if (x.first==i && x.second>1) { ok=true; break; }
	for (int j=0; j<n; ++j) {
	  if (g[x.first][j]!=-1) {
	    double p=x.second*g[x.first][j];
	    if (p>d[j]) q.push(make_pair(j, p)), d[j]=p;
	  }
	}
      }
      if (ok) break;
    }
    cout<<"Case "<<++cnt<<": "<<(ok?"Yes":"No")<<endl;
  }
}
