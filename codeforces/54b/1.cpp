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

#ifdef DEBUG
#include "/home/rock/program/topcoder/libs/debug.cpp"
#endif
////////////////////////////////////////////////////////////////////////////////

vector<string> rotate(const vector<string> &a)
{
  vector<string> res;
  for (int i=0; i<(int)(a[0]).size(); ++i) {
    string s;
    for (int j=(int)(a).size()-1; j>=0; --j)
      s+=a[j][i];
    res.push_back(s);
  }
  return res;
}

bool equal(const vector<string> &a, const vector<string> &b)
{
  vector<string> c=a;
  for (int i=0; i<4; ++i) {
    c=rotate(c);
    if (b==c) return true;
  }
  return false;
}

bool check(const vector<vector<string> > &v)
{
  for (int i=0; i<(int)(v).size(); ++i)
    for (int j=i+1; j<(int)(v).size(); ++j)
      if (equal(v[i], v[j])) return false;
  return true;
}

bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
  int x=a.first*a.second, y=b.first*b.second;
  if (x!=y) return x<y;
  else return a.first<b.first;
}

int main()
{
  int n, m;
  cin>>n>>m;
  vector<string> a(n);
  for (int i=0; i<n; ++i) cin>>a[i];
  vector<pair<int, int> > res;
  for (int i=1; i<=n; ++i)
    for (int j=1; j<=m; ++j)
      if (n%i==0 && m%j==0) {
	vector<vector<string> > aux;
	for (int p=0; p<n/i; ++p)
	  for (int q=0; q<m/j; ++q) {
	    vector<string> tmp;
	    for (int t=0; t<i; ++t)
	      tmp.push_back(a[p*i+t].substr(q*j, j));
	    aux.push_back(tmp);
	  }
	#ifdef DEBUG
	cout<<i<<" "<<j<<endl;
	print2(aux);
	#endif
	if (check(aux)) res.push_back(make_pair(i, j));
      }
  cout<<(int)(res).size()<<endl;
  sort((res).begin(), (res).end(), cmp);
  cout<<res[0].first<<" "<<res[0].second<<endl;
}
