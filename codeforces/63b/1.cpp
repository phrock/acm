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
  int n, k;
  cin>>n>>k;
  vector<int> v(k+1);
  for (int i=0; i<n; ++i) {
    int x;
    cin>>x;
    v[x]++;
  }
  int res=0;
  while (v[k]!=n) {
    for (int i=k-1; i>=1; --i) 
      if (v[i]>0) v[i]--, v[i+1]++;
    res++;
  }
  cout<<res<<endl;
}
