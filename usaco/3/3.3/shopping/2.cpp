/*
  ID:   rock2to1
  LANG: C++
  PROG: shopping
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

ifstream fin("shopping.in");
ofstream fout("shopping.out");
streambuf *cin_buf=cin.rdbuf();
streambuf *cout_buf=cout.rdbuf();
////////////////////////////////////////////////////////////////////////////////
vector<pair<vector<pair<int, int> >, int> > price;
int dp[6][6][6][6][6];
int a[5];
int c[5];

bool check(const vector<pair<int, int> > &v, int b[])
{
  for (int i=0; i<(int)(v).size(); ++i) {
    bool ok=false;
    for (int j=0; j<5; ++j) 
      if (c[j]==v[i].first && b[j]>=v[i].second) { ok=true; b[j]-=v[i].second; }
    if (!ok) return false;
  }
  return true;
}

int main()
{
  cin.rdbuf(fin.rdbuf());
  cout.rdbuf(fout.rdbuf());
  #ifdef DEBUG
  cin.rdbuf(cin_buf);
  cout.rdbuf(cout_buf);
  #endif
  //////////////////////////////////////////////////////////////////////////////

  int s;
  cin>>s;
  for (int i=0; i<s; ++i) {
    int n;
    cin>>n;
    vector<pair<int, int> > v;
    for (int j=0; j<n; ++j) {
      int c, k;
      cin>>c>>k;
      v.push_back(make_pair(c, k));
    }
    int p;
    cin>>p;
    price.push_back(make_pair(v, p));
  }
  int b;
  cin>>b;
  for (int i=0; i<b; ++i) {
    int cc, k, p;
    cin>>cc>>k>>p;
    a[i]=k; c[i]=cc;
    vector<pair<int, int> > v;
    v.push_back(make_pair(cc, 1));
    price.push_back(make_pair(v, p));
  }
  for (int i0=0; i0<=a[0]; ++i0)
    for (int i1=0; i1<=a[1]; ++i1)
      for (int i2=0; i2<=a[2]; ++i2)
	for (int i3=0; i3<=a[3]; ++i3)
	  for (int i4=0; i4<=a[4]; ++i4)
	    dp[i0][i1][i2][i3][i4]=INT_MAX/2;
  dp[0][0][0][0][0]=0;

  for (int k=0; k<(int)(price).size(); ++k)
    for (int i0=0; i0<=a[0]; ++i0)
      for (int i1=0; i1<=a[1]; ++i1)
	for (int i2=0; i2<=a[2]; ++i2)
	  for (int i3=0; i3<=a[3]; ++i3)
	    for (int i4=0; i4<=a[4]; ++i4) {
	      int b[5];
	      b[0]=i0; b[1]=i1; b[2]=i2; b[3]=i3; b[4]=i4;
	      if (check(price[k].first, b)) {
		dp[i0][i1][i2][i3][i4]=min(dp[i0][i1][i2][i3][i4], dp[b[0]][b[1]][b[2]][b[3]][b[4]]+price[k].second);
	      }
	    }
  cout<<dp[a[0]][a[1]][a[2]][a[3]][a[4]]<<endl;
  
}
