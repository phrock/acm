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
  vector<vector<int> > g(P+1, vector<int>(P+1, M));
  for (int i=0; i<C; ++i) {
    int a, b, c;
    cin>>a>>b>>c;
    g[b][a]=g[a][b]=min(g[a][b], c);
  }
  for (int i=1; i<=P; ++i) g[i][i]=0;
  for (int k=1; k<=P; ++k)
    for (int i=1; i<=P; ++i)
      for (int j=1; j<=P; ++j)
	g[i][j]=min(g[i][j], g[i][k]+g[k][j]);
  int res=M;
  for (int k=1; k<=P; ++k) {
    int aux=0;
    for (int i=1; i<=P; ++i) aux+=a[i]*g[i][k];
    res=min(res, aux);
  }
  cout<<res<<endl;
}
