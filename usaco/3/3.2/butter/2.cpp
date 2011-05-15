/*
  ID:   rock2to1
  LANG: C++
  PROG: butter
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

ifstream fin("butter.in");
ofstream fout("butter.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////
int main()
{
  cin.rdbuf(fin.rdbuf());
  cout.rdbuf(fout.rdbuf());
  #ifdef DEBUG
  cin.rdbuf(cin_buf);
  cout.rdbuf(cout_buf);
  #endif
  //////////////////////////////////////////////////////////////////////////////

  const int M=INT_MAX/2;
  int N, P, C;
  cin>>N>>P>>C;
  vector<int> a(P+1);
  for (int i=0; i<N; ++i) {
    int x;
    cin>>x;
    a[x]++;
  }
  vector<vector<pair<int, int> > > g(P+1);
  for (int i=0; i<C; ++i) {
    int a, b, c;
    cin>>a>>b>>c;
    g[a].push_back(make_pair(b, c));
    g[b].push_back(make_pair(a, c));
  }
  int res=M;
  for (int k=1; k<=P; ++k) {
    vector<int> dis(P+1, M);
    dis[k]=0;
    set<pair<int, int> > st;
    st.insert(make_pair(0, k));
    while (!st.empty()) {
      pair<int, int> x=*st.begin();
      int v=x.second;
      st.erase(st.begin());
      for (int i=0; i<(int)(g[v]).size(); ++i) {
	int v2=g[v][i].first, cost=g[v][i].second;
	if (dis[v]+cost<dis[v2]) {
	  if (dis[v2]!=M) st.erase(st.find(make_pair(dis[v2], v2)));
	  st.insert(make_pair(dis[v]+cost, v2));
	  dis[v2]=dis[v]+cost;
	}
      }
    }
    // cout<<k<<" ";
    // print(dis);
    int aux=0;
    for (int i=1; i<=P; ++i) aux+=a[i]*dis[i];
    res=min(res, aux);
  }

  cout<<res<<endl;
}
