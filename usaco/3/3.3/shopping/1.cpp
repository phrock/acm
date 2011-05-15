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

vector<pair<vector<pair<int, int> >, int> > special_price;
int price[1000];
int a[1000];
int res;

bool check(const vector<pair<int, int> > &v)
{
  for (int i=0; i<(int)(v).size(); ++i) if (a[v[i].first]<v[i].second) return false;
  return true;
}

void dfs(int sum)
{
  int aux=0;
  for (int i=1; i<1000; ++i) aux+=a[i]*price[i];
  res=min(res, sum+aux);
  for (int i=0; i<(int)(special_price).size(); ++i) {
    if (check(special_price[i].first)) {
      for (int j=0; j<(int)(special_price[i].first).size(); ++j)
	a[special_price[i].first[j].first]-=special_price[i].first[j].second;
      dfs(sum+special_price[i].second);
      for (int j=0; j<(int)(special_price[i].first).size(); ++j)
	a[special_price[i].first[j].first]+=special_price[i].first[j].second;
    }
  }
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
    special_price.push_back(make_pair(v, p));
  }
  int b;
  cin>>b;
  for (int i=0; i<b; ++i) {
    int c, k, p;
    cin>>c>>k>>p;
    a[c]+=k;
    price[c]=p;
  }
  res=INT_MAX;
  dfs(0);
  cout<<res<<endl;
}
