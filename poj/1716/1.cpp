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
  cin>>n;
  vector< pair<int, int> > a(n);
  vector<int> b(n);
  vector<int> v(10001);
  for (int i=0; i<n; ++i) cin>>a[i].second>>a[i].first;
  sort((a).begin(), (a).end());
  int res=0;
  for (int i=0; i<n; ++i) {
    if (b[i]>=2) continue;
    for (int j=a[i].first; j>=a[i].second && b[i]<2; --j) {
      if (v[j]) continue;
      v[j]=1;
      b[i]++;
      res++;
      for (int k=i+1; k<n; ++k) if (a[k].second<=j) b[k]++;
    }
  }
  cout<<res<<endl;
}
