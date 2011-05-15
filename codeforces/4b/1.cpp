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
  int n, sum;
  cin>>n>>sum;
  vector<int> a(n), b(n);
  int as=0, bs=0;
  for (int i=0; i<n; ++i) cin>>a[i]>>b[i], as+=a[i], bs+=b[i];
  if (as<=sum && bs>=sum) {
    cout<<"YES"<<endl;
    for (int i=0; i<n; ++i) {
      if (i) cout<<" ";
      for (int j=a[i]; j<=b[i]; ++j)
	if (as-a[i]<=sum-j && bs-b[i]>=sum-j) { as-=a[i]; bs-=b[i]; sum-=j; cout<<j; break; }
    }
    cout<<endl;
  } else cout<<"NO"<<endl;
}
