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


int main()
{
  int n;
  cin>>n;
  vector<int> a(n), b(n);
  for (int i=0; i<n; ++i) cin>>a[i];
  for (int i=0; i<n; ++i) cin>>b[i];
  vector<pair<int, int> > res;
  for (int i=0; i<n; ++i)
    if (b[i]!=a[i]) {
      for (int j=i+1; j<n; ++j)
	if (b[j]==a[i]) {
	  while (j!=i) {
	    pair<int, int> x;
	    x.first=j;
	    x.second=j+1;
	    res.push_back(x);
	    swap(b[j-1], b[j]);
	    j--;
	  }
	  break;
	}
    }
  cout<<(int)(res).size()<<endl;
  for (int i=0; i<(int)(res).size(); ++i) cout<<res[i].first<<" "<<res[i].second<<endl;
}
